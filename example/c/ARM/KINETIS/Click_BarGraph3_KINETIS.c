/*
Example for BarGraph3 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI module and sets AN, RST, CS and PWM pin as OUTPUT
- Application Initialization - Initialization driver init, enable device and set PWM
- Application Task - (code snippet) - Counter passes through the loop and logs the value of the counter on the bargraph display

*/

#include "Click_BarGraph3_types.h"
#include "Click_BarGraph3_config.h"
#include "Click_BarGraph3_pwm.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN,  _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN,  _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_BARGRAPH3_SPI_CFG[0] );
    Delay_100ms();
}

void applicationInit()
{
    bargraph3_spiDriverInit( (T_BARGRAPH3_P)&_MIKROBUS1_GPIO, (T_BARGRAPH3_P)&_MIKROBUS1_SPI );
    bargraph3_enable( _BARGRAPH3_DEVICE_ENABLE );
    
	/* PWM Init */
    bargraph3_pwmInit( 100 );
    bargraph3_pwmSetDuty( 30000 );
    bargraph3_pwmStart();
    Delay_100ms();
}

void applicationTask()
{
    uint8_t bargraph_cnt;

    for (bargraph_cnt = 0; bargraph_cnt <= 5; bargraph_cnt++)
    {
        bargraph3_display(_BARGRAPH3_INCREASE_LED, _BARGRAPH3_DIRECTION_BOTTOM_TO_TOP, bargraph_cnt);
        Delay_1sec();
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}