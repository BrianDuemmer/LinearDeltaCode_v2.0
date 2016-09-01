//*****************************************************************************
//
// Configure the device pins for different signals
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

// This file was automatically generated on 8/27/2016 at 11:59:37 AM
// by TI PinMux version 
//
//*****************************************************************************

#include <source\LinearDelta2.hpp>


//*****************************************************************************
//
//! \addtogroup pinout_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Configures the device pins for the customer specific usage.
//!
//! \return None.
//
//*****************************************************************************
void
PinoutSet(void)
{
    //
    // Enable Peripheral Clocks 
    //
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);

    //
    // Configure the GPIO Pin Mux for PF0
	// for M0PWM0
    //
	MAP_GPIOPinConfigure(GPIO_PF0_M0PWM0);
	MAP_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);

    //
    // Configure the GPIO Pin Mux for PG0
	// for M0PWM4
    //
	MAP_GPIOPinConfigure(GPIO_PG0_M0PWM4);
	MAP_GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_0);

    //
    // Configure the GPIO Pin Mux for PF2
	// for M0PWM2
    //
	MAP_GPIOPinConfigure(GPIO_PF2_M0PWM2);
	MAP_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);

    //
    // Configure the GPIO Pin Mux for PF1
	// for M0PWM1
    //
	MAP_GPIOPinConfigure(GPIO_PF1_M0PWM1);
	MAP_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);

    //
    // Configure the GPIO Pin Mux for PF3
	// for M0PWM3
    //
	MAP_GPIOPinConfigure(GPIO_PF3_M0PWM3);
	MAP_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);

    //
    // Configure the GPIO Pin Mux for PE3
	// for AIN0
    //
	MAP_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);

    //
    // Configure the GPIO Pin Mux for PE2
	// for AIN1
    //
	MAP_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2);

    //
    // Configure the GPIO Pin Mux for PE1
	// for GPIO_PE1
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_1);
	MAP_GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //
    // Configure the GPIO Pin Mux for PE0
	// for GPIO_PE0
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_0);
	MAP_GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //
    // Configure the GPIO Pin Mux for PK0
	// for GPIO_PK0
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTK_BASE, GPIO_PIN_0);
	MAP_GPIOPadConfigSet(GPIO_PORTK_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //
    // Configure the GPIO Pin Mux for PK1
	// for GPIO_PK1
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTK_BASE, GPIO_PIN_1);
	MAP_GPIOPadConfigSet(GPIO_PORTK_BASE, GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //
    // Configure the GPIO Pin Mux for PK2
	// for GPIO_PK2
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTK_BASE, GPIO_PIN_2);
	MAP_GPIOPadConfigSet(GPIO_PORTK_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //
    // Configure the GPIO Pin Mux for PK3
	// for GPIO_PK3
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTK_BASE, GPIO_PIN_3);
	MAP_GPIOPadConfigSet(GPIO_PORTK_BASE, GPIO_PIN_3, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //
    // Configure the GPIO Pin Mux for PC7
	// for GPIO_PC7
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_7);
	MAP_GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Configure the GPIO Pin Mux for PC6
	// for GPIO_PC6
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_6);
	MAP_GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Configure the GPIO Pin Mux for PC5
	// for GPIO_PC5
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_5);
	MAP_GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Configure the GPIO Pin Mux for PC4
	// for GPIO_PC4
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_4);
	MAP_GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Configure the GPIO Pin Mux for PH0
	// for GPIO_PH0
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_0);
	MAP_GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, GPIO_PIN_0);

    //
    // Configure the GPIO Pin Mux for PH1
	// for GPIO_PH1
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_1);
	MAP_GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 0x0);

    //
    // Configure the GPIO Pin Mux for PH2
	// for GPIO_PH2
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_2);
	MAP_GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, GPIO_PIN_2);

    //
    // Configure the GPIO Pin Mux for PH3
	// for GPIO_PH3
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_3);
	MAP_GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_3, GPIO_PIN_3);

    //
    // Configure the GPIO Pin Mux for PA0
	// for GPIO_PA0
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_0);
	MAP_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_0, 0x0);

    //
    // Configure the GPIO Pin Mux for PA1
	// for GPIO_PA1
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_1);
	MAP_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_1, 0x0);

    //
    // Configure the GPIO Pin Mux for PA2
	// for GPIO_PA2
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2);
	MAP_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);

    //
    // Configure the GPIO Pin Mux for PA3
	// for GPIO_PA3
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_3);
	MAP_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);

    //
    // Configure the GPIO Pin Mux for PA6
	// for GPIO_PA6
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6);
	MAP_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);

    //
    // Configure the GPIO Pin Mux for PA7
	// for GPIO_PA7
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_7);
	MAP_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0x0);

    //
    // Configure the GPIO Pin Mux for PF4
	// for GPIO_PF4
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);
	MAP_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);

    //
    // Configure the GPIO Pin Mux for PG1
	// for GPIO_PG1
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_1);
	MAP_GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_1, GPIO_PIN_1);

    //
    // Configure the GPIO Pin Mux for PK7
	// for GPIO_PK7
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_7);
	MAP_GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, 0x0);

    //
    // Configure the GPIO Pin Mux for PK5
	// for GPIO_PK5
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_5);
	MAP_GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_5, 0x0);

    //
    // Configure the GPIO Pin Mux for PK4
	// for GPIO_PK4
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_4);
	MAP_GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_4, 0x0);

    //
    // Configure the GPIO Pin Mux for PM7
	// for GPIO_PM7
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_7);
	MAP_GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_7, GPIO_PIN_7);

    //
    // Configure the GPIO Pin Mux for PM6
	// for GPIO_PM6
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_6);
	MAP_GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_6, GPIO_PIN_6);

    //
    // Configure the GPIO Pin Mux for PM5
	// for GPIO_PM5
    //
	MAP_GPIOPinTypeGPIOInput(GPIO_PORTM_BASE, GPIO_PIN_5);
	MAP_GPIOPadConfigSet(GPIO_PORTM_BASE, GPIO_PIN_5, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Configure the GPIO Pin Mux for PM4
	// for GPIO_PM4
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_4);
	MAP_GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, 0x0);

    //
    // Configure the GPIO Pin Mux for PM3
	// for GPIO_PM3
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_3);
	MAP_GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_3, 0x0);

    //
    // Configure the GPIO Pin Mux for PM2
	// for GPIO_PM2
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_2);
	MAP_GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_2, 0x0);

    //
    // Configure the GPIO Pin Mux for PM1
	// for GPIO_PM1
    //
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_1);
	MAP_GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_1, 0x0);

    //
    // Configure the GPIO Pin Mux for PD1
	// for SSI2XDAT0
    //
	MAP_GPIOPinConfigure(GPIO_PD1_SSI2XDAT0);
	MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_1);

    //
    // Configure the GPIO Pin Mux for PD0
	// for SSI2XDAT1
    //
	MAP_GPIOPinConfigure(GPIO_PD0_SSI2XDAT1);
	MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0);

    //
    // Configure the GPIO Pin Mux for PD2
	// for SSI2FSS
    //
	MAP_GPIOPinConfigure(GPIO_PD2_SSI2FSS);
	MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_2);

    //
    // Configure the GPIO Pin Mux for PD3
	// for SSI2CLK
    //
	MAP_GPIOPinConfigure(GPIO_PD3_SSI2CLK);
	MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_3);

    //
    // Configure the GPIO Pin Mux for PQ2
	// for SSI3XDAT0
    //
	MAP_GPIOPinConfigure(GPIO_PQ2_SSI3XDAT0);
	MAP_GPIOPinTypeSSI(GPIO_PORTQ_BASE, GPIO_PIN_2);

    //
    // Configure the GPIO Pin Mux for PQ3
	// for SSI3XDAT1
    //
	MAP_GPIOPinConfigure(GPIO_PQ3_SSI3XDAT1);
	MAP_GPIOPinTypeSSI(GPIO_PORTQ_BASE, GPIO_PIN_3);

    //
    // Configure the GPIO Pin Mux for PQ1
	// for SSI3FSS
    //
	MAP_GPIOPinConfigure(GPIO_PQ1_SSI3FSS);
	MAP_GPIOPinTypeSSI(GPIO_PORTQ_BASE, GPIO_PIN_1);

    //
    // Configure the GPIO Pin Mux for PQ0
	// for SSI3CLK
    //
	MAP_GPIOPinConfigure(GPIO_PQ0_SSI3CLK);
	MAP_GPIOPinTypeSSI(GPIO_PORTQ_BASE, GPIO_PIN_0);

//    //
//    // Configure the GPIO Pin Mux for PK6
//	// for EN0LED1
//    //
//	MAP_GPIOPinConfigure(GPIO_PK6_EN0LED1);
//	GPIOPinTypeEthernetLED(GPIO_PORTK_BASE, GPIO_PIN_6);
//
//    //
//    // Configure the GPIO Pin Mux for PJ0
//	// for EN0PPS
//    //
//	MAP_GPIOPinConfigure(GPIO_PJ0_EN0PPS);
//	GPIOPinTypeEthernetMII(GPIO_PORTJ_BASE, GPIO_PIN_0);

    //
    // Configure the GPIO Pin Mux for PA4
	// for I2C7SCL
    //
	MAP_GPIOPinConfigure(GPIO_PA4_I2C7SCL);
	MAP_GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_4);

    //
    // Configure the GPIO Pin Mux for PA5
	// for I2C7SDA
    //
	MAP_GPIOPinConfigure(GPIO_PA5_I2C7SDA);
	MAP_GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_5);

    //
    // Configure the GPIO Pin Mux for PL2
	// for PHB0
    //
	MAP_GPIOPinConfigure(GPIO_PL2_PHB0);
	MAP_GPIOPinTypeQEI(GPIO_PORTL_BASE, GPIO_PIN_2);

    //
    // Configure the GPIO Pin Mux for PL1
	// for PHA0
    //
	MAP_GPIOPinConfigure(GPIO_PL1_PHA0);
	MAP_GPIOPinTypeQEI(GPIO_PORTL_BASE, GPIO_PIN_1);
	//GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_1 | GPIO_PIN_2, 1);

}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

