#include "Click_BarGraph3_types.h"


uint32_t bargraph3_pwmInit(uint16_t freq)
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM_Init(freq);
	
	return pwmPeriod;
}

void bargraph3_pwmSetDuty(uint16_t duty)
{
    PWM_ConfigChannel(duty,  _PWM_INIT_STATE_1, _PWM_CHANNEL_0);
}

void bargraph3_pwmStart()
{
    PWM_EnableOutput();
}

void bargraph3_pwmStop()
{
    PWM_DisableOutput();
}