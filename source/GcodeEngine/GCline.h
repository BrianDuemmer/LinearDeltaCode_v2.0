/*
 * GCline.h
 *
 *  Created on: Jul 17, 2016
 *      Author: Duemmer
 */


#ifndef CUSTOMCODE_GCODEENGINE_GCLINE_H_
#define CUSTOMCODE_GCODEENGINE_GCLINE_H_

#include <xdc\std.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// container for gcode argument
typedef struct GCarg {
	char letter;
	float val;
}GCarg;

class GCline {
private:

	// variables
	int32_t 			lineNum;
	GCarg				command;
	bool 				critType;
	GCarg				*args;
	uint8_t 			argCount;
	char				*stringArg;

	// functions
	uint8_t getArgCt_Raw(char* argString);
	char* getCmdTypeAndNum(char* GCline);
	int16_t getArg(char *GCline, GCarg *arg, uint8_t offset);
	char *getStrArg(char *argStringIn);

public:
	GCline(char* GCline);
	virtual ~GCline();
	void sysPrint();
	bool hasArgLtr(char ltr);
	int32_t getLineNum();
	GCarg getCmdType();
	bool isCritType(GCarg *critCmds, uint8_t critCmdCount);
};

#endif /* CUSTOMCODE_GCODEENGINE_GCLINE_H_ */
