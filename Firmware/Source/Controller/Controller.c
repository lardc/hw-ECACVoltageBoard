// Header
#include "Controller.h"
//
// Includes
#include "Board.h"
#include "Delay.h"
#include "DeviceProfile.h"
#include "Interrupts.h"
#include "Global.h"
#include "LowLevel.h"
#include "SysConfig.h"
#include "DebugActions.h"
#include "Diagnostic.h"
#include "BCCIxParams.h"

// Types
//
typedef void (*FUNC_AsyncDelegate)();

// Variables
//
volatile DeviceState CONTROL_State = DS_None;
static Boolean CycleActive = false;

volatile Int64U CONTROL_TimeCounter = 0;

/// Forward functions
//
static Boolean CONTROL_DispatchAction(Int16U ActionID, pInt16U pUserError);
void CONTROL_SetDeviceState(DeviceState NewState);
void CONTROL_SwitchToFault(Int16U Reason);
void CONTROL_DelayMs(uint32_t Delay);
void CONTROL_UpdateWatchDog();
void CONTROL_ResetToDefaultState();

// Functions
//
void CONTROL_Init()
{
	// ������������ ������� ������ Data-table � EPROM
	EPROMServiceConfig EPROMService = {(FUNC_EPROM_WriteValues)&NFLASH_WriteDT, (FUNC_EPROM_ReadValues)&NFLASH_ReadDT};
	// ������������� data table
	DT_Init(EPROMService, false);
	DT_SaveFirmwareInfo(CAN_SLAVE_NID, 0);
	// ������������� device profile
	DEVPROFILE_Init(&CONTROL_DispatchAction, &CycleActive);
	// ����� ��������
	DEVPROFILE_ResetControlSection();
	CONTROL_ResetToDefaultState();
}
//------------------------------------------

void CONTROL_ResetToDefaultState()
{
	DataTable[REG_FAULT_REASON] = DF_NONE;
	DataTable[REG_DISABLE_REASON] = DF_NONE;
	DataTable[REG_PROBLEM] = PROBLEM_NONE;
	DataTable[REG_OP_RESULT] = OPRESULT_NONE;

	DEVPROFILE_ResetScopes(0);
	DEVPROFILE_ResetEPReadState();
	
	CONTROL_SetDeviceState(DS_None);
}

//------------------------------------------

void CONTROL_Idle()
{
	DEVPROFILE_ProcessRequests();
	CONTROL_UpdateWatchDog();
}
//------------------------------------------

static Boolean CONTROL_DispatchAction(Int16U ActionID, pInt16U pUserError)
{
	*pUserError = ERR_NONE;
	
	switch (ActionID)
	{
		case ACT_ENABLE_POWER:
			{
				DataTable[REG_OP_RESULT] = OPRESULT_NONE;
				if((CONTROL_State == DS_None) || (CONTROL_State == DS_Disabled))
				{
					CONTROL_SetDeviceState(DS_Enabled);
					DataTable[REG_OP_RESULT] = OPRESULT_OK;
				}
				else
				{
					DataTable[REG_OP_RESULT] = OPRESULT_FAIL;
					*pUserError = ERR_OPERATION_BLOCKED;
				}
				break;
			}
			
		case ACT_DISABLE_POWER:
			DataTable[REG_OP_RESULT] = OPRESULT_NONE;
			if((CONTROL_State == DS_None) || (CONTROL_State == DS_Enabled) || (CONTROL_State == DS_SafetyEnabled)
					|| (CONTROL_State == DS_SafetyDanger))
			{
				CONTROL_SetDeviceState(DS_Disabled);
			}
			else
			{
				if((CONTROL_State == DS_Disabled))
				{
					DataTable[REG_OP_RESULT] = OPRESULT_OK;
				}
				else
				{
					DataTable[REG_OP_RESULT] = OPRESULT_FAIL;
				}
			}
			
		case ACT_FAULT_CLEAR:
			{
				CONTROL_ResetToDefaultState();
			}
			break;

		default:
			return DIAG_HandleDiagnosticAction(ActionID, pUserError);
			
	}
	return true;
}
//-----------------------------------------------

void CONTROL_SwitchToFault(Int16U Reason)
{
	CONTROL_SetDeviceState(DS_Fault);
	DataTable[REG_FAULT_REASON] = Reason;
}
//------------------------------------------

void CONTROL_SetDeviceState(DeviceState NewState)
{
	CONTROL_State = NewState;
	DataTable[REG_DEV_STATE] = NewState;
}
//------------------------------------------

void CONTROL_DelayMs(uint32_t Delay)
{
	uint64_t Counter = (uint64_t)CONTROL_TimeCounter + Delay;
	while(Counter > CONTROL_TimeCounter)
		CONTROL_UpdateWatchDog();
}
//------------------------------------------

void CONTROL_UpdateWatchDog()
{
	if(BOOT_LOADER_VARIABLE != BOOT_LOADER_REQUEST)
		IWDG_Refresh();
}
//------------------------------------------

