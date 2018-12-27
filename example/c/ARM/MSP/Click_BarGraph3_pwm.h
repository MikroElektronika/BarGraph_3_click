#include "Click_BarGraph3_types.h"


uint32_t bargraph3_pwmInit(uint16_t freq)
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM0_Init(freq, _PWM_CFG_CLOCK_SRC_SMCLK | 
	                             _PWM_CFG_OUTPUTMODE_SET | 
								 _PWM_CFG_CHANNEL_4, 
								 &_GPIO_MODULE_PWM_TA0_4_A15);
	
	return pwmPeriod;
}

void bargraph3_pwmSetDuty(uint16_t duty)
{
    PWM0_SetDuty( duty, _PWM_CFG_CHANNEL_4 );
}

void bargraph3_pwmStart()
{
    PWM0_Start();
}

void bargraph3_pwmStop()
{
    PWM0_Stop();
}