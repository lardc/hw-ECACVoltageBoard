﻿// -----------------------------------------
// Global definitions
// ----------------------------------------

// Header
#include "Constraints.h"

// Constants
//
const TableItemConstraint NVConstraint[DATA_TABLE_NV_SIZE] = {
		{0, REGULATOR_K_MAX, 0},													// 0
		{0, REGULATOR_K_MAX, 0},													// 1
		{SHUNT_RES_MIN, SHUNT_RES_MAX, SHUNT_RES_DEF},								// 2
		{SHUNT_RES_MIN, SHUNT_RES_MAX, SHUNT_RES_DEF},								// 3
		{SHUNT_RES_MIN, SHUNT_RES_MAX, SHUNT_RES_DEF},								// 4
		{1, INT16U_MAX, 1000},														// 5
		{1, INT16U_MAX, 1000},														// 6
		{1, INT16U_MAX, 1000},														// 7
		{1, INT16U_MAX, 1000},														// 8
		{1, INT16U_MAX, 1000},														// 9
		{VOLTAGE_OUTPUT_MIN, VOLTAGE_OUTPUT_MAX, VOLTAGE_OUTPUT_DEF},				// 10
		{CURRENT_OUTPUT_UA_MIN, CURRENT_OUTPUT_UA_MAX, CURRENT_OUTPUT_UA_DEF},		// 11
		{CURRENT_OUTPUT_UA_MIN, CURRENT_OUTPUT_UA_MAX, CURRENT_OUTPUT_UA_DEF},		// 12
		{CURRENT_OUTPUT_MA_MIN, CURRENT_OUTPUT_MA_MAX, CURRENT_OUTPUT_MA_DEF},		// 13
		{0, 0, 0},																	// 14
		{0, INT16U_MAX, 0},															// 15
		{1, INT16U_MAX, 1000},														// 16
		{0, INT16U_MAX, 0},															// 17
		{1, INT16U_MAX, 1000},														// 18
		{0, INT16U_MAX, 0},															// 19
		{0, INT16U_MAX, 0},															// 20
		{1, INT16U_MAX, 1000},														// 21
		{0, INT16U_MAX, 0},															// 22
		{1, INT16U_MAX, 1000},														// 23
		{0, INT16U_MAX, 0},															// 24
		{0, INT16U_MAX, 0},															// 25
		{1, INT16U_MAX, 1000},														// 26
		{0, INT16U_MAX, 0},															// 27
		{1, INT16U_MAX, 1000},														// 28
		{0, INT16U_MAX, 0},															// 29
		{0, INT16U_MAX, 0},															// 30
		{1, INT16U_MAX, 1000},														// 31
		{0, INT16U_MAX, 0},															// 32
		{1, INT16U_MAX, 1000},														// 33
		{0, INT16U_MAX, 0},															// 34
		{0, INT16U_MAX, 0},															// 35
		{1, INT16U_MAX, 1000},														// 36
		{0, INT16U_MAX, 0},															// 37
		{1, INT16U_MAX, 1000},														// 38
		{0, INT16U_MAX, 0},															// 39
		{0, PWM_DUTY_OFFSET_MAX, PWM_DUTY_OFFSET_DEF},								// 40
		{0, 0, 0},																	// 41
		{0, 0, 0},																	// 42
		{0, 0, 0},																	// 43
		{0, 0, 0},																	// 44
		{0, 0, 0},																	// 45
		{0, 0, 0},																	// 46
		{0, 0, 0},																	// 47
		{0, 0, 0},																	// 48
		{0, 0, 0},																	// 49
		{0, 0, 0},																	// 50
		{0, 0, 0},																	// 51
		{0, 0, 0},																	// 52
		{0, 0, 0},																	// 53
		{0, 0, 0},																	// 54
		{0, 0, 0},																	// 55
		{0, 0, 0},																	// 56
		{0, 0, 0},																	// 57
		{0, 0, 0},																	// 58
		{0, 0, 0},																	// 59
		{TRANSFORMER_RATIO_MIN, TRANSFORMER_RATIO_MAX, TRANSFORMER_RATIO_DEF},		// 60
		{VOLTAGE_OUTPUT_MIN, VOLTAGE_OUTPUT_MAX, VOLTAGE_OUTPUT_DEF},				// 61
		{VOLTAGE_RISE_RATE_MIN, VOLTAGE_RISE_RATE_MAX, VOLTAGE_RISE_RATE_DEF},		// 62
		{VOLTAGE_READY_LVL_MIN, VOLTAGE_READY_LVL_MAX, VOLTAGE_READY_LVL_DEF},		// 63
		{0, 0, 0},																	// 64
		{0, 0, 0},																	// 65
		{0, 0, 0},																	// 66
		{0, 0, 0},																	// 67
		{0, 0, 0},																	// 68
		{0, 0, 0},																	// 69
		{NO, YES, YES},																// 70
		{FE_LEVEL_MIN, FE_LEVEL_MAX, FE_LEVEL_DEF},									// 71
		{FE_COUNTER_MIN, FE_COUNTER_MAX, FE_COUNTER_DEF},							// 72
		{0, 0, 0},																	// 73
		{0, 0, 0},																	// 74
		{0, 0, 0},																	// 75
		{0, 0, 0},																	// 76
		{0, 0, 0},																	// 77
		{0, 0, 0},																	// 78
		{0, 0, 0},																	// 79
		{0, 0, 0},																	// 80
		{0, 0, 0},																	// 81
		{0, 0, 0},																	// 82
		{0, 0, 0},																	// 83
		{0, 0, 0},																	// 84
		{0, 0, 0},																	// 85
		{0, 0, 0},																	// 86
		{0, 0, 0},																	// 87
		{0, 0, 0},																	// 88
		{0, 0, 0},																	// 89
		{0, 0, 0},																	// 90
		{0, 0, 0},																	// 91
		{0, 0, 0},																	// 92
		{0, 0, 0},																	// 93
		{0, 0, 0},																	// 94
		{0, 0, 0},																	// 95
		{0, 0, 0},																	// 96
		{0, 0, 0},																	// 97
		{0, 0, 0},																	// 98
		{0, 0, 0},																	// 99
		{0, 0, 0},																	// 100
		{0, 0, 0},																	// 101
		{0, 0, 0},																	// 102
		{0, 0, 0},																	// 103
		{0, 0, 0},																	// 104
		{0, 0, 0},																	// 105
		{0, 0, 0},																	// 106
		{0, 0, 0},																	// 107
		{0, 0, 0},																	// 108
		{0, 0, 0},																	// 109
		{0, 0, 0},																	// 110
		{0, 0, 0},																	// 111
		{0, 0, 0},																	// 112
		{0, 0, 0},																	// 113
		{0, 0, 0},																	// 114
		{0, 0, 0},																	// 115
		{0, 0, 0},																	// 116
		{0, 0, 0},																	// 117
		{0, 0, 0},																	// 118
		{0, 0, 0},																	// 119
		{0, 0, 0},																	// 120
		{0, 0, 0},																	// 121
		{0, 0, 0},																	// 122
		{0, 0, 0},																	// 123
		{0, 0, 0},																	// 124
		{0, 0, 0},																	// 125
		{0, 0, 0},																	// 126
		{0, 0, 0}																	// 127
};

const TableItemConstraint VConstraint[DATA_TABLE_WP_START - DATA_TABLE_WR_START] = {
		{0, INT16U_MAX, 0},															// 128
		{0, INT16U_MAX, 0},															// 129
		{0, INT16U_MAX, 0},															// 130
		{0, INT16U_MAX, 0},															// 131
		{AC_None, AC_CTRL, AC_None},												// 132
		{0, 0, 0},																	// 133
		{0, 0, 0},																	// 134
		{0, 0, 0},																	// 135
		{0, 0, 0},																	// 136
		{0, 0, 0},																	// 137
		{0, 0, 0},																	// 138
		{0, 0, 0},																	// 139
		{0, 0, 0},																	// 140
		{0, 0, 0},																	// 141
		{0, 0, 0},																	// 142
		{0, 0, 0},																	// 143
		{0, 0, 0},																	// 144
		{0, 0, 0},																	// 145
		{0, 0, 0},																	// 146
		{0, 0, 0},																	// 147
		{0, 0, 0},																	// 148
		{0, 0, 0},																	// 149
		{0, INT16U_MAX, 0},															// 150
		{0, 0, 0},																	// 151
		{0, 0, 0},																	// 152
		{0, 0, 0},																	// 153
		{0, 0, 0},																	// 154
		{0, 0, 0},																	// 155
		{0, 0, 0},																	// 156
		{0, 0, 0},																	// 157
		{0, 0, 0},																	// 158
		{0, 0, 0},																	// 159
		{0, 0, 0},																	// 160
		{0, 0, 0},																	// 161
		{0, 0, 0},																	// 162
		{0, 0, 0},																	// 163
		{0, 0, 0},																	// 164
		{0, 0, 0},																	// 165
		{0, 0, 0},																	// 166
		{0, 0, 0},																	// 167
		{0, 0, 0},																	// 168
		{0, 0, 0},																	// 169
		{0, 0, 0},																	// 170
		{0, 0, 0},																	// 171
		{0, 0, 0},																	// 172
		{0, 0, 0},																	// 173
		{0, 0, 0},																	// 174
		{0, 0, 0},																	// 175
		{0, 0, 0},																	// 176
		{0, 0, 0},																	// 177
		{0, 0, 0},																	// 178
		{0, 0, 0},																	// 179
		{0, 0, 0},																	// 180
		{0, 0, 0},																	// 181
		{0, 0, 0},																	// 182
		{0, 0, 0},																	// 183
		{0, 0, 0},																	// 184
		{0, 0, 0},																	// 185
		{0, 0, 0},																	// 186
		{0, 0, 0},																	// 187
		{0, 0, 0},																	// 188
		{0, 0, 0},																	// 189
		{0, INT16U_MAX, 0},															// 190
		{0, 0, 0}																	// 191
};
