/*
 * LinearDelta2.hpp
 *
 *  Created on: Jul 22, 2016
 *      Author: Duemmer
 *
 * Provides a single, cohesive include file that contains all necessary includes
 * for the project. Every source file in the project should include this file.
 */

#ifndef SOURCE_LINEARDELTA2_HPP_
#define SOURCE_LINEARDELTA2_HPP_

//////////////////////////////////////////////////////////////////////
//////////////////////////////  Includes  ////////////////////////////
//////////////////////////////////////////////////////////////////////

 /* Includes many commonly used header files. Used to consoldate
  * everything we need to include in one place.
 */

// put the critical includes at the top
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/System.h>
#include <xdc/cfg/global.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>


/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/SDSPI.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/PWM.h>

/* Peripheral header files */
#include "inc\hw_memmap.h"
#include "driverlib\qei.h"
#include "driverlib\gpio.h"
#include "driverlib\fpu.h"
#include "driverlib\ssi.h"
#include "driverlib\sysctl.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

/* NDK BSD support */
#include <sys/socket.h>

/* Board Header file */
#include "Board.h"

//////////////////////////////// Custom header files ///////////////////////////////

#include "../source/GcodeEngine/GCline.h"
#include "../source/motion/DeltaAxis.h"
#include "../source/motion/PID.h"
#include "../source/util/VecMath.h"
#include "../source/motion/DeltaKinematics.h"
#include "io/pinout.h"
#include "io/HdrLayer.h"
#include "FileIO\config.h"
#include "FileIO\inih-master\ini.h"
#include "io/TCPcomm.h"
#include "../source/FileIO/GlobalData.h"
#include <test.h>


#endif /* SOURCE_LINEARDELTA2_HPP_ */
