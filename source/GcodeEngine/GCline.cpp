/*
 * GCline.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>

/*
 * The constructor for this class is one of the only functions for this class
 * that will be used by he end user. It converts a raw line of gcode into a
 * GCline object, which stores the line data in a form much more convenient
 * for later use. Note that it is the responsibility of the end user to handle
 * deallocating GCline if necessary
 */
GCline::GCline(char *GCline) {
	// initialize all variables to safe defaults
	lineNum = -1;
	command.letter = 0x0;
	command.val = 0;
	critType = false;
	args = NULL;
	stringArg = NULL;
	argCount = 0;

	// parse out any strng args, as well as the line number and command,
	// and get a list of the argument strings
	char *rawArgString = getCmdTypeAndNum(GCline);
	char *argString = getStrArg(rawArgString);
	int16_t argOffset = 0;

	// do a null check. This value will be null if a string arg is read without a
	// terminal ".
	if(argString != NULL){
		argCount = getArgCt_Raw(argString);

		// allocate a GCarg array for the args, and parse them out one by one
		if(argCount > 0){
			GCarg *argsTmp = new GCarg[argCount];
			for(int i = 0; i < argCount; i++){
				argOffset = getArg(argString, &argsTmp[i], argOffset);
			}
			args = argsTmp;
		}
	}
	// delete the temp strings
	if(argString != NULL) {delete[] argString;}
	if(rawArgString != NULL) {delete[] rawArgString;}
}

GCline::~GCline() {
	delete[] args;
	delete[] stringArg;
}

/*
 * pass this function a line of gcode, with the line and command numbers removed,
 * and it will return the number of args in the string, but does not parse them.
 * Does not modify argString
 */
uint8_t GCline::getArgCt_Raw(char *argString){

	// if the input string is null, skip everything and return 0
	if(argString != NULL)
	{
		int strLen = strlen(argString);
		bool prevMatch = false;
		uint8_t Charcount = 0;
		int i = 0;
		uint8_t c = 0;

		while(i < strLen){
			// get char at i
			c = (uint8_t)*(argString + i);
			i++;
			// see if it is an alphabetic character, and the previous character
			// was not. if so, increment the counter.
			if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
				if(!prevMatch){
					Charcount++;
				}
				prevMatch = true;
			}
			else{
				prevMatch = false;
			}
		}
		return Charcount;
	}
	else { return 0; }
}

/*
 *  Parses the line number, command type and number out of the raw line.
 *  Returns the arguments string, or null if there are no more arguments.
 *  Will also populate the lineNum field, if a line number is found.
 *  Make sure to deallocate the memory when finished!
 */
char* GCline::getCmdTypeAndNum(char *GCline){
	GCarg* Temp = new GCarg;
	// Parse the first arg in the line, and check whether it is a line number field
	int16_t nextArgOffset = getArg(GCline, Temp, 0);
	if(Temp->letter == 'n' || Temp->letter == 'N'){
	// if so, populate the lineNum variable, get the next arg, and assign that to the command variable
		lineNum = Temp->val + 0.5;
		nextArgOffset = getArg(GCline, &command, nextArgOffset);
	}
	else{
	// if not, copy the contents from Temp to command
		memcpy(Temp, &command, sizeof(command));
	}
	// cleanup
	delete Temp;

	if(nextArgOffset != -1){
		char *rtn = strdup(GCline + nextArgOffset);
		return rtn;
	}
	else{
		return NULL;
	}

}



/*
 * gets an argument (defined as a single leter followed by a variable - length number)
 * from a gcode line, with offset being the position in the string of the letter.
 * returns the offset position of the first character after the found character,
 * or -1 if the end of string is reached
 */
int16_t GCline::getArg(char *GCline, GCarg *arg, uint8_t offset){

	uint8_t c;
	uint8_t lastDigit;

	// set the active character equal to the character in GCline at index offset
	c = (uint8_t)*(GCline + offset);

	// move the actual offset up to the first alphabetic character past
	// the provided offset
	while(!((c >= 65 && c <= 90) || (c >= 97 && c <= 122))){
		offset++;
		c = (uint8_t)*(GCline + offset);
	}

	// set the letter value to the value in the string specified by offset, and force
	// lowercase letters to be capital
	if(c >= 97) {c -= 32;}
	arg->letter = c;

	// set the initial value for lastDigit to offset + 1
	lastDigit = offset + 1;
	c = (uint8_t)*(GCline + lastDigit);

	// see how many digits there are. Keep incrementing the count until we find
	// a character that isn't a '.', whitespace, or a number
	while((c >= 48 && c <= 57) || c == 46 || (c >= 1 && c <= 32)){
		lastDigit++;
		c = (uint8_t)*(GCline + lastDigit);
	}

	// last digit will always be high by 1, so decrement to get the actual value
	lastDigit--;

	// if there are numbers after the command, get the numbers and convert to a float.
	// if not, set arg->val equal to 0.
	if(lastDigit != offset){
		// allocate a temporary array to hold the number, and a null-termination value
		char *cNum = new char[lastDigit - offset + 1];
		// add the number characters into the new array
		for(int i = 0; i < lastDigit - offset; i++){
			cNum[i] = (char)*(GCline + offset + i + 1);
		}
		// null terminate it
		cNum[lastDigit - offset] = 0x0;
		arg->val = atof(cNum);
		// make sure to clean up the temporary array
		delete[] cNum;
	}
	else{
		arg->val = 0;
	}

	// check to see if we reached the end of the string
	if((uint8_t)*(GCline + lastDigit + 1) == 0){
		return -1;
	}
	else{
		return lastDigit + 1;
	}
}


/*
 * Sees if a string argument exists, and, if it does, populates the stringArg class
 * variable and returns argStringIn with the string arg removed. If not, leaves stringArg
 * a NULL value, and returns a copy of argStringIn. Does not delete argStringIn.
 */
char *GCline::getStrArg(char *argStringIn){
	uint8_t startOffset = 0;
	uint8_t endOffset = 0;
	uint8_t inLen = strlen(argStringIn);
	uint8_t outLen = 0;
	char c = *argStringIn;

	// set startOffset to the first character that is a '"' (quote mark)
	while(c != 34){
		startOffset++;
		c = *(argStringIn + startOffset);

		// if we reach the end of a string before finding a ", then there is no
		// string arg, and just return
		if(c == 0){
			return strdup(argStringIn);
		}
	}
// we want startOffset to point to the first character after the ", so increment
	startOffset++;
	// Reassign the value of c
	c = *(argStringIn + startOffset);
	endOffset = startOffset;
	while(c != 34){
		endOffset++;
		c = *(argStringIn + endOffset);

		// if we reach the end of a string before finding a ", then there isn't a
		// second quote, so copy everything after startOffset into the stringArg
		// class variable, and return NULL
		if(c == 0){
			stringArg = strdup(argStringIn + startOffset);

			return NULL;
		}
	}

	if(endOffset - startOffset != 0){
		// copy the string argument from the input string into the stringArg class var
		outLen = endOffset - startOffset + 1;
		char *str = new char[outLen];
		stringArg = strncpy(str, (argStringIn + startOffset), outLen);
		stringArg[outLen - 1] = 0;

		// return a new string containing everything in argString after endOffset
		char *rtn = strdup(argStringIn + endOffset + 1);
		return rtn;
	}
	else {
		// if there is an empty string arg ("") then return what's after, but leave
		// the stringArg variable alone
		char *rtn = strdup(argStringIn + endOffset + 1);
		return rtn;
	}
}


void GCline::sysPrint(){
	System_printf("Line number:   %d\n", lineNum);
	System_printf("Command letter:  %c\nCommand number:   %d\n", command.letter, (int)(command.val + .5));
	System_printf("String arg:   \"%s\"\n", stringArg);
	for(int i = 0; i <argCount; i++){
		System_printf("Arg number %d:\n", i);
		System_printf("\tCommand letter:  %c\n\tCommand number:   %7.3f \n", args[i].letter, args[i].val);
	}
	System_flush();
}


bool GCline::hasArgLtr(char ltr){
	// account for case insensitivity
	if(ltr >=96) {ltr -= 32;}
	for(int i = 0; i < argCount; i++){
		if(args[i].letter == ltr){
			return true;
		}
	}
	return false;
}



int32_t GCline::getLineNum(){
	return lineNum;
}


GCarg GCline::getCmdType(){
	return command;
}


bool GCline::isCritType(GCarg *critCmds, uint8_t critCmdCount){
	for(int i = 0; i < critCmdCount; i++){
		// account for case insensitivity
		if(critCmds[i].letter >= 96) {critCmds[i].letter -= 32;}
		if(command.letter == critCmds[i].letter && command.val == critCmds[i].val){
			return true;
		}
	}
	return false;
}






