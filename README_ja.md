[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHTC3

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/shtc3/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHTC3は、バッテリー駆動の大量生産民生用電子機器向けに特別に設計されたデジタル湿度・温度センサーです。このセンサーは、サイズ、消費電力、価格性能比における従来の限界を克服し、現在および将来の要件を満たすよう厳密に設計されています。SensirionのCMOSens®テクノロジーは、静電容量式湿度センサー、バンドギャップ温度センサー、アナログおよびデジタル信号処理、A/Dコンバーター、キャリブレーションデータメモリ、I2C Fast Mode Plusをサポートするデジタル通信インターフェースで構成される完全なセンサーシステムをシングルチップで提供します。2×2×0.75 mm3の小型DFNパッケージは、最も限られたスペースでもアプリケーションを可能にします。このセンサーは、湿度測定範囲0～100 %RH、温度測定範囲-40 °C～125 °Cをカバーし、標準精度は±2 %RH、±0.2 °Cです。 SHTC3は、1.62V～3.6Vの幅広い電源電圧と、1計測あたり1μJ未満のエネルギーバジェットにより、バッテリー駆動のモバイルアプリケーションやワイヤレスアプリケーションに最適です。業界で実証されたSensirionの湿度・温度センサーは、その高い品質と信頼性に加え、広い計測範囲にわたる安定した精度を実現しており、SHTC3は最高の価格性能比を実現します。

LibDriver SHTC3は、LibDriverがリリースしたSHTC3用のフル機能ドライバです。通常読み取り、低消費電力読み取り、そして追加機能を提供します。LibDriverはMISRAに準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver SHTC3のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver SHTC3用のプラットフォームに依存しないIICバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver SHTC3ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver SHTC3プログラミング例が含まれています。

/ docディレクトリには、LibDriver SHTC3オフラインドキュメントが含まれています。

/ datasheetディレクトリには、SHTC3データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIICバステンプレートを参照して、指定したプラットフォームのIICバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

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

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/shtc3/index.html](https://www.libdriver.com/docs/shtc3/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。