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

### SKR 3  & SKR 3 EZ Pinout table

<table>
   <tr><td>Peripheral</td><td>Function</td><td>Pin name</td><td>Pin No.</td><td>Comment</td></tr>
   <tr><td rowspan="4">X</td><td>STEP</td><td>PD4</td><td>85</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>DIR</td><td>PD3</td><td>84</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>EN</td><td>PD6</td><td>87</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>CS/UART</td><td>PD5</td><td>86</td><td></td></tr>
   <tr><td rowspan="4">Y</td><td>STEP</td><td>PA15</td><td>77</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>DIR</td><td>PA8</td><td>67</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>EN</td><td>PD1</td><td>82</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>CS/UART</td><td>PD0</td><td>81</td><td></td></tr>
   <tr><td rowspan="4">Z</td><td>STEP</td><td>PE2</td><td>1</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>DIR</td><td>PE3</td><td>2</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>EN</td><td>PE0</td><td>97</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>CS/UART</td><td>PE1</td><td>98</td><td></td></tr>
   <tr><td rowspan="4">E0</td><td>STEP</td><td>PD15</td><td>62</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>DIR</td><td>PD14</td><td>61</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>EN</td><td>PC7</td><td>64</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>CS/UART</td><td>PC6</td><td>63</td><td></td></tr>
   <tr><td rowspan="4">E1</td><td>STEP</td><td>PD11</td><td>58</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>DIR</td><td>PD10</td><td>57</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>EN</td><td>PD13</td><td>60</td><td>SKR 3 EZ is converted to 5V to driver (SKR 3 is MCU 3.3V)</td></tr>
   <tr><td>CS/UART</td><td>PD12</td><td>59</td><td></td></tr>
   <tr><td rowspan="3">TMC SPI (Software SPI)</td><td>MISO</td><td>PE15</td><td>45</td><td></td></tr>
   <tr><td>MOSI</td><td>PE13</td><td>43</td><td></td></tr>
   <tr><td>SCK</td><td>PE14</td><td>44</td><td></td></tr>
   <tr><td rowspan="3">Heater</td><td>E0</td><td>PB3</td><td>89</td><td>is converted to 5V to MOSFET with flyback protection</td></tr>
   <tr><td>E1</td><td>PB4</td><td>90</td><td>is converted to 5V to MOSFET with flyback protection</td></tr>
   <tr><td>HB(heated bed)</td><td>PD7</td><td>88</td><td>is converted to 5V to MOSFET with flyback protection</td></tr>
   <tr><td rowspan="3">Temperature</td><td>TH0</td><td>PA2</td><td>24</td><td>4.7KOhm 0.1% pull up resistor for NTC100K,etc. 1KOhm(SKR 3) or 2.2KOhm(SKR 3 EZ) 0.1% pull up resistor for PT1000 by jumper. with thermistor protection circuit</td></tr>
   <tr><td>TH1</td><td>PA3</td><td>25</td><td>4.7KOhm 0.1% pull up resistor for NTC100K,etc. 1KOhm(SKR 3) or 2.2KOhm(SKR 3 EZ) 0.1% pull up resistor for PT1000 by jumper. with thermistor protection circuit</td></tr>
   <tr><td>THB</td><td>PA1</td><td>23</td><td>4.7KOhm 0.1% pull up resistor for NTC100K,etc. with thermistor protection circuit</td></tr>
   <tr><td rowspan="5">Endstop</td><td>X-STOP</td><td>PC1</td><td>16</td><td>Share with X-DIAG</td></tr>
   <tr><td>Y-STOP</td><td>PC3</td><td>18</td><td>Share with Y-DIAG</td></tr>
   <tr><td>Z-STOP</td><td>PC0</td><td>15</td><td>Share with Z-DIAG</td></tr>
   <tr><td>E0-DET</td><td>PC2</td><td>17</td><td>Share with E0-DIAG</td></tr>
   <tr><td>E1-DET</td><td>PA0</td><td>22</td><td>Share with E1-DIAG</td></tr>
   <tr><td rowspan="3">FAN</td><td>FAN0</td><td>PB7</td><td>93</td><td>is converted to 5V to MOSFET with flyback protection</td></tr>
   <tr><td>FAN1</td><td>PB6</td><td>92</td><td>is converted to 5V to MOSFET with flyback protection</td></tr>
   <tr><td>FAN2</td><td>PB5</td><td>91</td><td>is converted to 5V to MOSFET with flyback protection</td></tr>
   <tr><td rowspan="3">Misc</td><td>PWRDET</td><td>PC15</td><td>9</td><td></td></tr>
   <tr><td>PS-ON</td><td>PE4</td><td>3</td><td></td></tr>
   <tr><td>RGB(Neopixel/WS2812)</td><td>PE6</td><td>5</td><td>is converted to 5V</td></tr>
   <tr><td rowspan="2">BLTouch</td><td>SERVOS</td><td>PE5</td><td>4</td><td></td></tr>
   <tr><td>PROBE</td><td>PC13</td><td>7</td><td></td></tr>
   <tr><td rowspan="2">TFT UART1</td><td>RX</td><td>PA10</td><td>69</td><td></td></tr>
   <tr><td>TX</td><td>PA9</td><td>68</td><td></td></tr>
   <tr><td rowspan="2">FDCAN1</td><td>RX</td><td>PB8</td><td>95</td><td></td></tr>
   <tr><td>TX</td><td>PB9</td><td>96</td><td></td></tr>
   <tr><td rowspan="2">USB-Device</td><td>OTG_FS_DM</td><td>PA11</td><td>70</td><td></td></tr>
   <tr><td>OTG_FS_DP</td><td>PA12</td><td>71</td><td></td></tr>
   <tr><td rowspan="10">EXP1</td><td>5V</td><td>5V</td><td></td><td>Marlin: EXP1_01_PIN, Klipper: EXP1_10</td></tr>
   <tr><td>GND</td><td>GND</td><td></td><td>Marlin: EXP1_02_PIN, Klipper: EXP1_9</td></tr>
   <tr><td>LCD_D7</td><td>PE12</td><td>42</td><td>Marlin: EXP1_03_PIN, Klipper: EXP1_8</td></tr>
   <tr><td>LCD_D6</td><td>PE11</td><td>41</td><td>Marlin: EXP1_04_PIN, Klipper: EXP1_7</td></tr>
   <tr><td>LCD_D5</td><td>PE10</td><td>40</td><td>Marlin: EXP1_05_PIN, Klipper: EXP1_6</td></tr>
   <tr><td>LCD_D4</td><td>PE9</td><td>39</td><td>Marlin: EXP1_06_PIN, Klipper: EXP1_5</td></tr>
   <tr><td>LCD_RS</td><td>PE8</td><td>38</td><td>Marlin: EXP1_07_PIN, Klipper: EXP1_4</td></tr>
   <tr><td>LCD_EN</td><td>PB1</td><td>35</td><td>Marlin: EXP1_08_PIN, Klipper: EXP1_3</td></tr>
   <tr><td>BTN_ENC</td><td>PB0</td><td>34</td><td>Marlin: EXP1_09_PIN, Klipper: EXP1_2</td></tr>
   <tr><td>BEEPER</td><td>PC5</td><td>33</td><td>Marlin: EXP1_10_PIN, Klipper: EXP1_1</td></tr>
   <tr><td rowspan="10">EXP2</td><td>NC</td><td>NC</td><td></td><td>Marlin: EXP2_01_PIN, Klipper: EXP2_10</td></tr>
   <tr><td>GND</td><td>GND</td><td></td><td>Marlin: EXP2_02_PIN, Klipper: EXP2_9</td></tr>
   <tr><td>RESET</td><td>RESET</td><td>14</td><td>Marlin: EXP2_03_PIN, Klipper: EXP2_8</td></tr>
   <tr><td>SD_DETECT</td><td>PC4</td><td>32</td><td>Marlin: EXP2_04_PIN, Klipper: EXP2_7</td></tr>
   <tr><td>MOSI</td><td>PA7</td><td>31</td><td>Marlin: EXP2_05_PIN, Klipper: EXP2_6</td></tr>
   <tr><td>BTN_EN2</td><td>PB2</td><td>36</td><td>Marlin: EXP2_06_PIN, Klipper: EXP2_5</td></tr>
   <tr><td>SD_SS</td><td>PA4</td><td>28</td><td>Marlin: EXP2_07_PIN, Klipper: EXP2_4</td></tr>
   <tr><td>BTN_EN1</td><td>PE7</td><td>37</td><td>Marlin: EXP2_08_PIN, Klipper: EXP2_3</td></tr>
   <tr><td>SCK</td><td>PA5</td><td>29</td><td>Marlin: EXP2_09_PIN, Klipper: EXP2_2</td></tr>
   <tr><td>MISO</td><td>PA6</td><td>30</td><td>Marlin: EXP2_10_PIN, Klipper: EXP2_1</td></tr>
   <tr><td rowspan="6">OnboardSD(SDIO)</td><td>SDMMC1_CK</td><td>PC12</td><td>80</td><td></td></tr>
   <tr><td>SDMMC1_CMD</td><td>PD2</td><td>83</td><td></td></tr>
   <tr><td>SDMMC1_D0</td><td>PC8</td><td>65</td><td></td></tr>
   <tr><td>SDMMC1_D1</td><td>PC9</td><td>66</td><td></td></tr>
   <tr><td>SDMMC1_D2</td><td>PC10</td><td>78</td><td></td></tr>
   <tr><td>SDMMC1_D3</td><td>PC11</td><td>79</td><td></td></tr>
   <tr><td rowspan="9">WIFI(ESP3D/RRF)</td><td>ESP-RST(espResetPin)</td><td>PC14</td><td>8</td><td></td></tr>
   <tr><td>ESP-IO0(espDataReadyPin)</td><td>PB10</td><td>46</td><td></td></tr>
   <tr><td>ESP-IO4(TfrReadyPin)</td><td>PB11</td><td>47</td><td></td></tr>
   <tr><td>ESP-RX(UART3)</td><td>PD8</td><td>55</td><td></td></tr>
   <tr><td>ESP-TX(UART3)</td><td>PD9</td><td>56</td><td></td></tr>
   <tr><td>ESP-CS</td><td>PB12</td><td>51</td><td></td></tr>
   <tr><td>ESP-MOSI</td><td>PB15</td><td>54</td><td></td></tr>
   <tr><td>ESP-MISO</td><td>PB14</td><td>53</td><td></td></tr>
   <tr><td>ESP-CLK</td><td>PB13</td><td>52</td><td></td></tr>
   <tr><td rowspan="2">EEPROM(Software-I2C)</td><td>SCL</td><td>PA14</td><td>76</td><td></td></tr>
   <tr><td>SDA</td><td>PA13</td><td>72</td><td>Share with onboard status LED</td></tr>
</table>

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
