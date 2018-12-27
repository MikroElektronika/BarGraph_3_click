#include "Click_BarGraph3_types.h"


uint32_t bargraph3_pwmInit(uint16_t freq)
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM0_Init( freq );
	
	return pwmPeriod;
}

void bargraph3_pwmSetDuty(uint16_t duty)
{
    PWM0_Set_Duty( duty, _PWM_NON_INVERTED );
}

void bargraph3_pwmStart()
{
    PWM0_Start();
}

void bargraph3_pwmStop()
{
    PWM0_Stop();
}