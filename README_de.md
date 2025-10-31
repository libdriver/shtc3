[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHTC3

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/shtc3/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Der SHTC3 ist ein digitaler Feuchtigkeits- und Temperatursensor, der speziell für batteriebetriebene Massenanwendungen in der Unterhaltungselektronik entwickelt wurde. Dieser Sensor wurde speziell entwickelt, um die üblichen Grenzen hinsichtlich Größe, Stromverbrauch und Preis-Leistungs-Verhältnis zu überwinden und so aktuelle und zukünftige Anforderungen zu erfüllen. Die CMOSens®-Technologie von Sensirion bietet ein komplettes Sensorsystem auf einem einzigen Chip, bestehend aus einem kapazitiven Feuchtigkeitssensor, einem Bandgap-Temperatursensor, analoger und digitaler Signalverarbeitung, A/D-Wandler, Kalibrierdatenspeicher und einer digitalen Kommunikationsschnittstelle mit I²C Fast Mode Plus. Das kleine DFN-Gehäuse (2 × 2 × 0,75 mm³) ermöglicht Anwendungen selbst auf engstem Raum. Der Sensor deckt einen Feuchtigkeitsmessbereich von 0 bis 100 % rF und einen Temperaturmessbereich von -40 °C bis 125 °C mit einer typischen Genauigkeit von ±2 % rF und ±0,2 °C ab. Dank des breiten Versorgungsspannungsbereichs von 1,62 V bis 3,6 V und eines Energieverbrauchs von unter 1 μJ pro Messung eignet sich der SHTC3 ideal für mobile oder drahtlose, batteriebetriebene Anwendungen. Mit der branchenerprobten Qualität und Zuverlässigkeit der Feuchtigkeits- und Temperatursensoren von Sensirion sowie der konstanten Genauigkeit über einen großen Messbereich bietet der SHTC3 ein optimales Preis-Leistungs-Verhältnis.

LibDriver SHTC3 ist ein umfassender Treiber für SHTC3, entwickelt von LibDriver. Er bietet normales Auslesen, Auslesen im Energiesparmodus und zusätzliche Funktionen. LibDriver ist MISRA-konform.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver SHTC3-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver SHTC3 IIC.

/test enthält den Testcode des LibDriver SHTC3-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver SHTC3-Beispielcode.

/doc enthält das LibDriver SHTC3-Offlinedokument.

/Datenblatt enthält SHTC3-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

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

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/shtc3/index.html](https://www.libdriver.com/docs/shtc3/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.