#include "Click_BarGraph3_types.h"


uint32_t bargraph3_pwmInit(uint16_t freq)
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM_FTM0_Init( freq, _PWM_EDGE_ALIGNED_PWM, 
	                                 _PWM_CHANNEL_1, 
									 &_GPIO_Module_PWM0_PTA4 );
	
	return pwmPeriod;
}

void bargraph3_pwmSetDuty(uint16_t duty)
{
    PWM_FTM0_Set_Duty( duty, _PWM_NON_INVERTED, _PWM_CHANNEL_1 );
}

void bargraph3_pwmStart()
{
    PWM_FTM0_Start( _PWM_CHANNEL_1 );
}

void bargraph3_pwmStop()
{
    PWM_FTM0_Stop( _PWM_CHANNEL_1 );
}