# [View English version](./README.md)

# SKR 3
## 硬件参数
* 微处理器：ARM Cortex-M7 STM32H743VI 480MHz 带 FDCAN 总线
* DCDC 5V 输出最大电流：5A, 峰值可达 6A
* 输入电压：DC12V-DC24V
* 逻辑电压：DC 3.3V
* 加热接口：热床（HB） 最大输出电流：10A，加热棒（ E0、 E1）最大输出电流：5.5A
* 热敏电阻端口带保护电路，避免因热床或者加热棒漏电 24V 电压接到热敏电阻端口导致主控芯片烧毁
* 热敏电阻可通过跳线选择上拉电阻值(1Kohm)，以此方式支持 PT1000，而不需外接模块，方便客户 DIY 使用(精度相比Max31865低很多)
* 风扇接口：三个数控风扇（FAN0， FAN1，FAN2），两个常开风扇端口，单个风扇最大输出电流：1A
* 数控风扇通过外插电源模块实现 24V、 12V、 5V 电压选择（ 注意： 3 个数控风扇的电压是统一的，无法单独设置为不同的电压），省去客户外接变压模块的操作
* 加热棒 + 驱动 + 风扇的总电流小于 10A
* WIFI 接口：ESP-12S、ESP-07S、ESP32U、ESP32E
* 拓展接口：BLTouch（Servos、Probe）、PS-ON、PWR-DET、Fil-DET、RGB、FDCAN
* 电机驱动：支持 TMC5160、TMC2209、TMC2225、TMC2226、TMC2208、TMC2130、ST820、LV8729、DRV8825、A4988 等，驱动工作模式支持 SPI、UART、STEP/DIR


## 固件支持
* 此产品支持 [Marlin](./Firmware/Marlin-bugfix-2.0.9.3.x)、 [Klipper](./Firmware/Klipper) 和 [RRF(RepRapFirmware)](./Firmware/RRF)固件

## Pin 脚说明
* [SKR 3-PIN.pdf](./Hardware%20(SKR%203)/BIGTREETECH%20SKR%203-PIN.pdf)


# SKR 3 EZ
## 硬件参数
* 热敏电阻可通过跳线选择上拉电阻值为(2.2Kohm， SKR 3 是 1Kohm, 2.2K搭配PT1000在我们工作的温度范围内，电压变化刻度更明显，相同的ADC精度下采集的温度比1K更准确些)，以此方式支持 PT1000.
* 逻辑电压：驱动信号线为DC 5V
* 所有电机驱动电压都是高低压可选的
* 电机驱动支持[EZ系列的驱动](https://bit.ly/39GaLVy)
* 其他的所有参数与 SKR 3 相同

## Pin 脚说明
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
