/*
 * GlobalData.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>



//	Printer modal data
bool			g_paused;
bool			g_routeToSD;
bool			g_EmStopped;
bool			g_unitsIsInch;
bool			g_absPositioning;
bool			g_motorsEnabled;
bool			g_DirectCodeExec;
bool			g_SDprinting;
char			*g_SDprintPath;

// Printer config data
GCarg			*g_criticalCommands;
uint8_t			g_criticalCommandCt;
char			*g_configFilePath;
float			g_maxFeedrate;
vec2d			*g_motOutLut;
uint16_t		g_motOutLutCt;

// Printer state data
vec3d			g_headPos;
DPosVec			g_deltaPos;
vec3d			g_headVel;
uint8_t			g_fanSpeed;

// Misc data
uint32_t		g_msecTime;

// HdrLayer container
HdrLayer 		g_hwl;

// Motion controller container
DeltaKinematics	g_motionCtl;





















