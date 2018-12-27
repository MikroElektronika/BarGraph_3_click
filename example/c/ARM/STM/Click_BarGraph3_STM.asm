_leddriver5_pwmInit:
;Click_BarGraph3_STM.c,30 :: 		uint32_t leddriver5_pwmInit(uint16_t freq)
; freq start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; freq end address is: 0 (R0)
; freq start address is: 0 (R0)
;Click_BarGraph3_STM.c,34 :: 		pwmPeriod = PWM_TIM5_Init(freq);
; freq end address is: 0 (R0)
BL	_PWM_TIM5_Init+0
; pwmPeriod start address is: 0 (R0)
;Click_BarGraph3_STM.c,36 :: 		return pwmPeriod;
; pwmPeriod end address is: 0 (R0)
;Click_BarGraph3_STM.c,37 :: 		}
L_end_leddriver5_pwmInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _leddriver5_pwmInit
_leddriver5_pwmSetDuty:
;Click_BarGraph3_STM.c,39 :: 		void leddriver5_pwmSetDuty(uint16_t duty)
; duty start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; duty end address is: 0 (R0)
; duty start address is: 0 (R0)
;Click_BarGraph3_STM.c,41 :: 		PWM_TIM5_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL1);
MOVS	R2, #0
MOVS	R1, #0
; duty end address is: 0 (R0)
BL	_PWM_TIM5_Set_Duty+0
;Click_BarGraph3_STM.c,42 :: 		}
L_end_leddriver5_pwmSetDuty:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _leddriver5_pwmSetDuty
_leddriver5_pwmStart:
;Click_BarGraph3_STM.c,44 :: 		void leddriver5_pwmStart()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph3_STM.c,46 :: 		PWM_TIM5_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM5_CH1_PA0);
MOVW	R1, #lo_addr(__GPIO_MODULE_TIM5_CH1_PA0+0)
MOVT	R1, #hi_addr(__GPIO_MODULE_TIM5_CH1_PA0+0)
MOVS	R0, #0
BL	_PWM_TIM5_Start+0
;Click_BarGraph3_STM.c,47 :: 		}
L_end_leddriver5_pwmStart:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _leddriver5_pwmStart
_leddriver5_pwmStop:
;Click_BarGraph3_STM.c,49 :: 		void leddriver5_pwmStop()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph3_STM.c,51 :: 		PWM_TIM5_Stop( _PWM_CHANNEL1 );
MOVS	R0, #0
BL	_PWM_TIM5_Stop+0
;Click_BarGraph3_STM.c,52 :: 		}
L_end_leddriver5_pwmStop:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _leddriver5_pwmStop
_systemInit:
;Click_BarGraph3_STM.c,54 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph3_STM.c,56 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN,  _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph3_STM.c,57 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph3_STM.c,58 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph3_STM.c,59 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN,  _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph3_STM.c,61 :: 		mikrobus_spiInit( _MIKROBUS1, &_BARGRAPH3_SPI_CFG[0] );
MOVW	R0, #lo_addr(__BARGRAPH3_SPI_CFG+0)
MOVT	R0, #hi_addr(__BARGRAPH3_SPI_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_spiInit+0
;Click_BarGraph3_STM.c,62 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_BarGraph3_STM.c,64 :: 		leddriver5_pwmInit( 100 );
MOVS	R0, #100
BL	_leddriver5_pwmInit+0
;Click_BarGraph3_STM.c,65 :: 		leddriver5_pwmSetDuty(30000);
MOVW	R0, #30000
BL	_leddriver5_pwmSetDuty+0
;Click_BarGraph3_STM.c,66 :: 		leddriver5_pwmStart();
BL	_leddriver5_pwmStart+0
;Click_BarGraph3_STM.c,67 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_BarGraph3_STM.c,69 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_BarGraph3_STM.c,71 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph3_STM.c,73 :: 		bargraph3_spiDriverInit( (T_BARGRAPH3_P)&_MIKROBUS1_GPIO, (T_BARGRAPH3_P)&_MIKROBUS1_SPI );
MOVW	R1, #lo_addr(__MIKROBUS1_SPI+0)
MOVT	R1, #hi_addr(__MIKROBUS1_SPI+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_bargraph3_spiDriverInit+0
;Click_BarGraph3_STM.c,74 :: 		bargraph3_enable( _BARGRAPH3_DEVICE_ENABLE );
MOVS	R0, __BARGRAPH3_DEVICE_ENABLE
BL	_bargraph3_enable+0
;Click_BarGraph3_STM.c,76 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_BarGraph3_STM.c,78 :: 		void applicationTask()
SUB	SP, SP, #8
STR	LR, [SP, #0]
;Click_BarGraph3_STM.c,82 :: 		for (bargraph_cnt = 0; bargraph_cnt <= 5; bargraph_cnt++)
; bargraph_cnt start address is: 4 (R1)
MOVS	R1, #0
; bargraph_cnt end address is: 4 (R1)
L_applicationTask0:
; bargraph_cnt start address is: 4 (R1)
CMP	R1, #5
IT	HI
BHI	L_applicationTask1
;Click_BarGraph3_STM.c,84 :: 		bargraph3_display(_BARGRAPH3_INCREASE_LED, _BARGRAPH3_DIRECTION_BOTTOM_TO_TOP, bargraph_cnt);
STRB	R1, [SP, #4]
UXTB	R2, R1
MOVS	R1, __BARGRAPH3_DIRECTION_BOTTOM_TO_TOP
MOVS	R0, __BARGRAPH3_INCREASE_LED
BL	_bargraph3_display+0
LDRB	R1, [SP, #4]
;Click_BarGraph3_STM.c,85 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_BarGraph3_STM.c,82 :: 		for (bargraph_cnt = 0; bargraph_cnt <= 5; bargraph_cnt++)
ADDS	R1, R1, #1
UXTB	R1, R1
;Click_BarGraph3_STM.c,86 :: 		}
; bargraph_cnt end address is: 4 (R1)
IT	AL
BAL	L_applicationTask0
L_applicationTask1:
;Click_BarGraph3_STM.c,87 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _applicationTask
_main:
;Click_BarGraph3_STM.c,89 :: 		void main()
;Click_BarGraph3_STM.c,91 :: 		systemInit();
BL	_systemInit+0
;Click_BarGraph3_STM.c,92 :: 		applicationInit();
BL	_applicationInit+0
;Click_BarGraph3_STM.c,94 :: 		while (1)
L_main3:
;Click_BarGraph3_STM.c,96 :: 		applicationTask();
BL	_applicationTask+0
;Click_BarGraph3_STM.c,97 :: 		}
IT	AL
BAL	L_main3
;Click_BarGraph3_STM.c,98 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
