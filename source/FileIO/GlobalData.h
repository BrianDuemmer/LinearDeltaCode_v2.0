/*
 * GlobalData.h
 *
 *  Created on: Jul 23, 2016
 *      Author: Duemmer
 *
 * Provides a header to include all general global data, to be included in the
 * main include file, linearDelta2.hpp. Also contains all global constants
 */

#ifndef SOURCE_FILEIO_GLOBALDATA_H_
#define SOURCE_FILEIO_GLOBALDATA_H_

//	Printer modal data
extern bool			g_paused;
extern bool			g_routeToSD;
extern bool			g_EmStopped;
extern bool			g_unitsIsInch;
extern bool			g_absPositioning;
extern bool			g_motorsEnabled;
extern bool			g_DirectCodeExec;
extern bool			g_SDprinting;
extern char			*g_SDprintPath;

// Printer config data
extern GCarg		*g_criticalCommands;
extern uint8_t		g_criticalCommandCt;
extern char			*g_configFilePath;
extern float		g_maxFeedrate;
extern vec2d		*g_motOutLut;
extern uint16_t		g_motOutLutCt;

// Printer State data
extern vec3d		g_headPos;
extern DPosVec		g_deltaPos;
extern vec3d		g_headVel;
extern uint8_t		g_fanSpeed;

// Misc data
extern uint32_t		g_msecTime;

// HdrLayer container
extern HdrLayer 	g_hwl;

// Motion controller container
extern DeltaKinematics	g_motionCtl;

// #define statements

#define UPDATE_MSEC						17 // msecs between global updates

#define VICTOR_PWM_MIN_USEC_HIGH		1000
#define VICTOR_PWM_MAX_USEC_HIGH		2000
#define VICTOR_PWM_PERIOD				5000 // must be greater than PWM_MAX_USEC_HIGH
#define VICTOR_PWM_DEADBAND_USEC		50
#define AXIS_A_PWM_IDX					0
#define AXIS_B_PWM_IDX					1
#define AXIS_C_PWM_IDX					2

#define ENDSTOP_DEBOUNCE_TIME			50 // minimum time required for an endstop state change to be recognized

#define TCP_PORT						50000
#define TCP_SERVER_STACK				4096
#define MAX_CLIENT_CT					2   // maximum number of clients allowed to connect
#define TCP_PACKET_SIZE					1024


#endif /* SOURCE_FILEIO_GLOBALDATA_H_ */
