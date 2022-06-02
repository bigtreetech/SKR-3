# [切换到中文版](./README_zh_cn.md)

# SKR 3
## Hardware
* MCU: ARM Cortex-M7 STM32H743VI 480MHz with FDCAN bus
* DCDC 5V current output rated at 5A max continuous and 6A max instantaneous
* Voltage in: DC12V-DC24V
* Logic voltage: DC 3.3V
* Heated bed(HB) max current: 10A, heater cartridge(E0, E1) max current: 5.5A
* Thermistor circuit is protected to prevent MCU damage from shorted heatbed and heater cartridge connection
* Thermistor connection supports Pull up resistance value(1Kohm) setting using jumpers, No more extra module needed for PT1000(Accuracy is much lower than max31865)
* Fan port: 3 X CNC(selectable voltage), 2 X always on(PSU voltage), max current: 1A per port
* Selectable voltage (24V, 12V, 5V by SKR 3-DC MODE)for CNC fan (Note: The voltages of the 3 * CNC fans are unified, different voltages cannot be set separately for different ports), no more need for external stepdown
*  Overall max current(HB+E0+E0+All fans): 10A
* WIFI: ESP-12S, ESP-07S, ESP32U, ESP32E
* Expansion port: BLTouch(Servos, Probe), PS-ON, PWR-DET, Fil-DET, RGB, FDCAN
* Stepper driver: TMC5160, TMC2209, TMC2225, TMC2226, TMC2208, TMC2130, ST820, LV8729, DRV8825, A4988 etc. Stepper driver mode: SPI, UART, STEP/DIR


## Firmware
* Supported Firmware: [Marlin](./Firmware/Marlin-bugfix-2.0.9.3.x),  [Klipper](./Firmware/Klipper) and [RRF(RepRapFirmware)](./Firmware/RRF)

## Pinout
* [SKR 3-PIN.pdf](./Hardware%20(SKR%203)/BIGTREETECH%20SKR%203-PIN.pdf)


# SKR 3 EZ
## Hardware
* Thermistor connection supports Pull up resistance value(2.2Kohm, SKR 3 use 1Kohm, Within our working temperature range, the voltage change scale of 2.2k with PT1000 is more obvious, and the temperature collected under the same ADC accuracy is more accurate than 1K) setting using jumpers, No more extra module needed for PT1000(Accuracy is much lower than max31865)
* Logic voltage: Stepper driver signal DC 5V
* High and low voltage can be selected for all stepper driver by jumper
* stepper driver support [EZ Driver](https://bit.ly/39GaLVy)
* All other parameters are the same as SKR 3

## Pinout
* [SKR 3 EZ-PIN.pdf](./Hardware%20(SKR%203%20EZ)/BIGTREETECH%20SKR%203%20EZ%20V1.0-PIN.pdf)

# Note
## Here’s BIGTREETECH! For Makers, by makers!
* We appreciate all of your support to BIGTREETECH! To offer an excellent experience of creation to every makers,We’re devoted to design and produce high-quality and durable accessories!

## How to contact:
### If you have any technical issue,please don’t hesitate contact us:
* BIGTREETECH: service004@biqu3d.com

### Follow us on social media to get more news:
* Facebook: https://www.facebook.com/BIGTREETECH/
* Twitter: https://twitter.com/BigTreeTech
* Instagram: https://www.instagram.com/bigtreetech_official/
* Official Site: https://bigtree-tech.com/

## Purchase link:
* SKR 3: https://bit.ly/3NoMhPf
* SKR 3 EZ: https://bit.ly/3LqfB6M
* EZ Driver: https://bit.ly/39GaLVy
