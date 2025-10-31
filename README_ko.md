[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHTC3

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/shtc3/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHTC3는 배터리 구동 대량 생산 가전제품용으로 특별히 설계된 디지털 습도 및 온도 센서입니다. 이 센서는 크기, 전력 소비, 가격 대비 성능의 기존 한계를 극복하여 현재 및 미래의 요구 사항을 충족하도록 엄격하게 설계되었습니다. 센시리온의 CMOSens® 기술은 정전용량형 습도 센서, 밴드갭 온도 센서, 아날로그 및 디지털 신호 처리, A/D 컨버터, 교정 데이터 메모리, 그리고 I2C Fast Mode Plus를 지원하는 디지털 통신 인터페이스로 구성된 단일 칩 기반의 완벽한 센서 시스템을 제공합니다. 2 × 2 × 0.75 mm3의 소형 DFN 패키지는 매우 제한된 공간에서도 적용 가능합니다. 이 센서는 0 ~ 100 %RH의 습도 측정 범위와 -40 °C ~ 125 °C의 온도 측정 범위를 지원하며, 일반적인 정확도는 ±2 %RH 및 ±0.2 °C입니다. 1.62V ~ 3.6V의 넓은 공급 전압과 측정당 1 μJ 미만의 에너지 예산을 갖춘 SHTC3는 배터리 구동 모바일 또는 무선 애플리케이션에 적합합니다. Sensirion의 습도 및 온도 센서는 업계에서 입증된 품질과 신뢰성을 갖추고 있으며, 넓은 측정 범위에서도 일정한 정확도를 유지하여 SHTC3는 가격대비 최고의 성능을 제공합니다.

LibDriver SHTC3는 LibDriver에서 출시한 SHTC3용 모든 기능을 갖춘 드라이버입니다. 일반 판독, 저전력 판독 및 추가 기능을 제공하며, MISRA 표준을 준수합니다.

### 콘텐츠

  - [설명](#설명)
  - [설치](#설치)
  - [사용](#사용)
    - [example basic](#example-basic)
  - [문서](#문서)
  - [기고](#기고)
  - [저작권](#저작권)
  - [문의하기](#문의하기)

### 설명

/src 디렉토리에는 LibDriver SHTC3의 소스 파일이 포함되어 있습니다.

/interface 디렉토리에는 LibDriver SHTC3용 플랫폼 독립적인 IIC버스 템플릿이 포함되어 있습니다.

/test 디렉토리에는 LibDriver SHTC3드라이버 테스트 프로그램이 포함되어 있어 칩의 필요한 기능을 간단히 테스트할 수 있습니다.

/example 디렉토리에는 LibDriver SHTC3프로그래밍 예제가 포함되어 있습니다.

/doc 디렉토리에는 LibDriver SHTC3오프라인 문서가 포함되어 있습니다.

/datasheet 디렉토리에는 SHTC3데이터시트가 있습니다.

/project 디렉토리에는 일반적으로 사용되는 Linux 및 마이크로컨트롤러 개발 보드의 프로젝트 샘플이 포함되어 있습니다. 모든 프로젝트는 디버깅 방법으로 셸 스크립트를 사용하며, 자세한 내용은 각 프로젝트의 README.md를 참조하십시오.

/misra 에는 LibDriver misra 코드 검색 결과가 포함됩니다.

### 설치

/interface 디렉토리에서 플랫폼 독립적인IIC 버스 템플릿을 참조하여 지정된 플랫폼에 대한 IIC버스 드라이버를 완성하십시오.

/src 디렉터리, 플랫폼용 인터페이스 드라이버 및 자체 드라이버를 프로젝트에 추가합니다. 기본 예제 드라이버를 사용하려면 /example 디렉터리를 프로젝트에 추가합니다.

### 사용

/example 디렉터리의 예제를 참조하여 자신만의 드라이버를 완성할 수 있습니다. 기본 프로그래밍 예제를 사용하려는 경우 사용 방법은 다음과 같습니다.

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

### 문서

온라인 문서: [https://www.libdriver.com/docs/shtc3/index.html](https://www.libdriver.com/docs/shtc3/index.html).

오프라인 문서: /doc/html/index.html.

### 기고

CONTRIBUTING.md 를 참조하십시오.

### 저작권

저작권 (c) 2015 - 지금 LibDriver 판권 소유

MIT 라이선스(MIT)

이 소프트웨어 및 관련 문서 파일("소프트웨어")의 사본을 얻은 모든 사람은 이에 따라 무제한 사용, 복제, 수정, 통합, 출판, 배포, 2차 라이선스를 포함하여 소프트웨어를 처분할 수 있는 권리가 부여됩니다. 소프트웨어의 사본에 대한 라이선스 및/또는 판매, 그리고 소프트웨어가 위와 같이 배포된 사람의 권리에 대한 2차 라이선스는 다음 조건에 따릅니다.

위의 저작권 표시 및 이 허가 표시는 이 소프트웨어의 모든 사본 또는 내용에 포함됩니다.

이 소프트웨어는 상품성, 특정 목적에의 적합성 및 비침해에 대한 보증을 포함하되 이에 국한되지 않는 어떠한 종류의 명시적 또는 묵시적 보증 없이 "있는 그대로" 제공됩니다. 어떤 경우에도 저자 또는 저작권 소유자는 계약, 불법 행위 또는 기타 방식에 관계없이 소프트웨어 및 기타 소프트웨어 사용으로 인해 발생하거나 이와 관련하여 발생하는 청구, 손해 또는 기타 책임에 대해 책임을 지지 않습니다.

### 문의하기

연락주세요lishifenging@outlook.com.