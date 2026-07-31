This repository consists of training SW created while going through STM32L4 Training provided by Forbot team - https://forbot.pl/blog/kurs-stm32-l4-wstep-spis-tresci-dla-kogo-jest-ten-kurs-id48575

Please be advised that the training on the website is in polish language.

Below you can find the summary of subjects taken during 17 lessons of the training:

1. STM Cube IDE & Cube MX tooling setup and walktrough.
2. Introduction to ARM architecture/CORTEXes genesis and the NUCLEO board used in the training.
3. Embedded "Hello World!" - toggling LED via pin :) + LEDs line manipulating.
4. Setting up UART in order to communicate with PC - I personally was using PuTTY instead of recommended TeraTerm.
5. Processor clocks setup introduction = LSI, LSE, HSI, MSI, HSE + sending current time (MCU perspective) to PC.
6. Low-power consumption subject - introduction and solutions presented for overwriting eg. HAL_Delay functions. Putting MCU into sleep mode and other experiments with multimeter.
7. Interrupts - Interrupt Service routines - priorities.
8. Timers (or rather counters ;) ) - cyclic interrupts generation - PWM generation using timer, encoder support.
9. ADC - internal/external voltage measurement, potentiometers - using DMA to get measurement results. Joystick support (double potentiometer).
10. SPI protocol + GPIO expander (MCP23S08).
11. TFT support - communication over SPI - displaying various colors, images, drawing shapes.
12. I2C + EEPROM (24AA01) - monitoring of I2C with SALEAE.
13. Pressure and temperature monitoring using I2C communication with LPS25HB sensor.
14. Distance measurement using HC-SR04 sensore + displaying the result in cm on 2 digits 7-seg. LED panel. + temperature compensation.
15. WS2812 LEDs panel - using PWM to update colors.
16. IR remote contoller - sending commands and displaying them in PuTTY terminal.
17. 1-wire protocol temperature sensors.
