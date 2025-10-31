[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHTC3

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/shtc3/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHTC3是一種數位濕度和溫度感測器，專門為電池驅動的大規模消費電子應用而設計。 該感測器經過嚴格設計，可以克服傳統的尺寸、功耗和性價比限制，以滿足當前和未來的要求。 Sensirion的CMOSens ® 科技在單個晶片上提供完整的感測器系統，包括電容式濕度感測器、帶隙溫度感測器、類比和數位信號處理、A/D轉換器、校準數據記憶體和支持I2C Fast Mode Plus的數位通信介面。 小型2×2×0.75 mm^3 DFN封裝允許在最有限的空間中應用。 該感測器涵蓋0至100%RH的濕度測量範圍和-40°C至125°C的溫度測量範圍，典型精度為±2%RH和±0.2°C。1.62 V至3.6 V的寬電源電壓和每次量測低於1μJ的能量消耗使SHTC3適合由電池供電的移動或無線應用。 憑藉Sensirion濕度和溫度感測器的業界公認的質量和可靠性，以及在大範圍量測內的恒定精度，SHTC3提供了最佳的性價比。

LibDriver SHTC3是LibDriver推出的SHTC3全功能驅動，該驅動提供正常模式讀取和低功耗模式讀取等功能並且它符合MISRA標準。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver SHTC3的源文件。

/interface目錄包含了LibDriver SHTC3與平台無關的IIC總線模板。

/test目錄包含了LibDriver SHTC3驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver SHTC3編程範例。

/doc目錄包含了LibDriver SHTC3離線文檔。

/datasheet目錄包含了SHTC3數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的IIC總線模板，完成指定平台的IIC總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

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

### 文檔

在線文檔: [https://www.libdriver.com/docs/shtc3/index.html](https://www.libdriver.com/docs/shtc3/index.html)。

離線文檔: /doc/html/index.html。

### 貢獻

請參攷CONTRIBUTING.md。

### 版權

版權 (c) 2015 - 現在 LibDriver 版權所有

MIT 許可證（MIT）

特此免費授予任何獲得本軟件副本和相關文檔文件（下稱“軟件”）的人不受限制地處置該軟件的權利，包括不受限制地使用、複製、修改、合併、發布、分發、轉授許可和/或出售該軟件副本，以及再授權被配發了本軟件的人如上的權利，須在下列條件下：

上述版權聲明和本許可聲明應包含在該軟件的所有副本或實質成分中。

本軟件是“如此”提供的，沒有任何形式的明示或暗示的保證，包括但不限於對適銷性、特定用途的適用性和不侵權的保證。在任何情況下，作者或版權持有人都不對任何索賠、損害或其他責任負責，無論這些追責來自合同、侵權或其它行為中，還是產生於、源於或有關於本軟件以及本軟件的使用或其它處置。

### 聯繫我們

請聯繫lishifenging@outlook.com。