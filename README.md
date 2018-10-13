# 远场微波成像探针控制器
#### 项目介绍
基于STM32控制器，控制三个步进电机驱动器使探针向着x，y，z轴三个方向运动；LED显示当前探针运动方向；数码管显示当前扫描行数；扫描至下一行时蜂鸣器发出提示音；按键控制步进电机运动。

* V1.0   2018.9.8
    * 主控为STM32f103RBT6。
    * 串口下载。
    * 电源输入为12V-2A，使用RT7272转为5V，再通过AMS1117转为3.3V。
    * 三轴流水灯显示探针运动方向,每轴三颗LED。
    * 两位数码管显示已扫描行数。
    * 扫描至下一行时使用NPN三极管驱动蜂鸣器，NPN选用S8050。
    * 步进电机驱动器的控制逻辑为5V/0V，所以需要将STM32输出引脚通过PMOS开关连接到5V电源或接地，PMOS选用NTR2101P-D
    * 六个按键控制探针向右、向后、向后步进、向前、向上、向下运动。
    * 板载12V电源滤波之后给步进电机驱动器供电。

* V1.1   2018.9.21
    * STM32的一些引脚不支持连接5V，强行连接时电压为3.6V，达不到步进电机驱动器的逻辑1（5V），所以需要修改引脚。
    * PMOS开关电路输出为逻辑0时实际为负电压，所以修改为接下拉电阻使逻辑0为0V.

* V1.2   2018.10.13
    * 加入按键消抖
