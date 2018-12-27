#include "Click_BarGraph3_types.h"


uint32_t bargraph3_pwmInit(uint16_t freq)
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM_Init( freq, 1, 1, 3 );
	
	return pwmPeriod;
}

void bargraph3_pwmSetDuty(uint16_t duty)
{
    PWM_Set_Duty( duty, 1 );
}

void bargraph3_pwmStart()
{
    PWM_Start( 1 );
}

void bargraph3_pwmStop()
{
    PWM_Stop( 1 );
}