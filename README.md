![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# BarGraph3 Click

- **CIC Prefix**  : BARGRAPH3
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---


### Software Support

We provide a library for the BarGraph3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2615/bargraph-3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines SPI bus driver and drivers that offer a choice for writting data in registers and reading data from registers. 
Library includes functions for logging values on the BarGraph display.  
User can enable and disable the chip with the function bargraph3_enable(), which is supported in the library. 

Key functions :

- ``` void bargraph3_display(uint8_t ctrl, uint8_t dir, uint8_t counter) ``` -  Displays function
- ``` void bargraph3_enable(uint8_t state) ``` - Functions for enable the chip

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI module and sets AN, RST, CS and PWM pin as OUTPUT
- Application Initialization - Initialization driver init, enable device and set PWM
- Application Task - (code snippet) - Counter passes through the loop and logs the value of the counter on the bargraph display


```.c
void applicationTask()
{
    uint8_t bargraph_cnt;

    for (bargraph_cnt = 0; bargraph_cnt <= 5; bargraph_cnt++)
    {
        bargraph3_display(_BARGRAPH3_INCREASE_LED, _BARGRAPH3_DIRECTION_BOTTOM_TO_TOP, bargraph_cnt);
        Delay_1sec();
    }
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2615/bargraph-3-click) page.

Other mikroE Libraries used in the example:

- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
