[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHTC3

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/shtc3/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHTC3是一种数字湿度和温度传感器，专门为电池驱动的大规模消费电子应用而设计。该传感器经过严格设计，可以克服传统的尺寸、功耗和性价比限制，以满足当前和未来的要求。Sensirion的CMOSens®技术在单个芯片上提供完整的传感器系统，包括电容式湿度传感器、带隙温度传感器、模拟和数字信号处理、A/D转换器、校准数据存储器和支持I2C Fast Mode Plus的数字通信接口。小型2×2×0.75 mm^3 DFN封装允许在最有限的空间中应用。该传感器涵盖0至100%RH的湿度测量范围和-40°C至125°C的温度测量范围，典型精度为±2%RH和±0.2°C。1.62 V至3.6 V的宽电源电压和每次测量低于1μJ的能量消耗使SHTC3适合由电池供电的移动或无线应用。凭借Sensirion湿度和温度传感器的业界公认的质量和可靠性，以及在大范围测量内的恒定精度，SHTC3提供了最佳的性价比。

LibDriver SHTC3是LibDriver推出的SHTC3全功能驱动，该驱动提供正常模式读取和低功耗模式读取等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver SHTC3的源文件。

/interface目录包含了LibDriver SHTC3与平台无关的IIC总线模板。

/test目录包含了LibDriver SHTC3驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver SHTC3编程范例。

/doc目录包含了LibDriver SHTC3离线文档。

/datasheet目录包含了SHTC3数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC总线模板，完成指定平台的IIC总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_shtc3_basic.h"

uint8_t res;
uint32_t i;
float temperature;
float humidity;

/* basic init */
res = shtc3_basic_init();
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    shtc3_interface_delay_ms(1000);

    /* read data */
    res = shtc3_basic_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)shtc3_basic_deinit();

        return 1;
    }

    /* output */
    shtc3_interface_debug_print("shtc3: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)3);
    shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature);
    shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity);
    
    ...
}

...

/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    shtc3_interface_delay_ms(1000);

    /* read data */
    res = shtc3_basic_read_low_power((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)shtc3_basic_deinit();

        return 1;
    }

    /* output */
    shtc3_interface_debug_print("shtc3: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)3);
    shtc3_interface_debug_print("shtc3: temperature is %0.2fC.\n", temperature);
    shtc3_interface_debug_print("shtc3: humidity is %0.2f%%.\n", humidity);
    
    ...
}  

...
    
/* basic deinit */
(void)shtc3_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/shtc3/index.html](https://www.libdriver.com/docs/shtc3/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。