### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. SHTC3

#### 3.1 Command Instruction

1. Show shtc3 chip and driver information.

   ```shell
   shtc3 (-i | --information)
   ```

2. Show shtc3 help.

   ```shell
   shtc3 (-h | --help)
   ```

3. Show shtc3 pin connections of the current board.

   ```shell
   shtc3 (-p | --port)
   ```

4. Run shtc3 register test.

   ```shell
   shtc3 (-t reg | --test=reg)
   ```

5. Run shtc3 read test, num is test times.

   ```shell
   shtc3 (-t read | --test=read) [--times=<num>]
   ```

6. Run shtc3 read function, num is read times.

   ```shell
   shtc3 (-e read | --example=read) [--times=<num>]
   ```

7. Run shtc3 low powr read function, num is read times.

   ```shell
   shtc3 (-e read-lp | --example=read-lp) [--times=<num>]
   ```
   
8. Run shtc3 reset function.

   ```shell
   shtc3 (-e reset | --example=reset)
   ```
   
9. Run shtc3 sleep function.

    ```shell
    shtc3 (-e sleep | --example=sleep)
    ```
10. Run shtc3 wakeup function.

    ```shell
    shtc3 (-e wakeup | --example=wakeup)
    ```

#### 3.2 Command Example

```shell
shtc3 -i

shtc3: chip is Sensirion SHTC3.
shtc3: manufacturer is Sensirion.
shtc3: interface is IIC.
shtc3: driver version is 1.0.
shtc3: min supply voltage is 1.6V.
shtc3: max supply voltage is 3.6V.
shtc3: max current is 0.90mA.
shtc3: max temperature is 125.0C.
shtc3: min temperature is -40.0C.
```

```shell
shtc3 -p

shtc3: SCL connected to GPIOB PIN8.
shtc3: SDA connected to GPIOB PIN9.
```

```shell
shtc3 -t reg

shtc3: chip is Sensirion SHTC3.
shtc3: manufacturer is Sensirion.
shtc3: interface is IIC.
shtc3: driver version is 1.0.
shtc3: min supply voltage is 1.6V.
shtc3: max supply voltage is 3.6V.
shtc3: max current is 0.90mA.
shtc3: max temperature is 125.0C.
shtc3: min temperature is -40.0C.
shtc3: start register test.
shtc3: shtc3_sleep test.
shtc3: sleep.
shtc3: check sleep ok.
shtc3: shtc3_wakeup test.
shtc3: wakeup.
shtc3: check wakeup ok.
shtc3: shtc3_soft_reset test.
shtc3: soft reset.
shtc3: check soft reset ok.
shtc3: finish register test.
```

```shell
shtc3 -t read --times=3

shtc3: chip is Sensirion SHTC3.
shtc3: manufacturer is Sensirion.
shtc3: interface is IIC.
shtc3: driver version is 1.0.
shtc3: min supply voltage is 1.6V.
shtc3: max supply voltage is 3.6V.
shtc3: max current is 0.90mA.
shtc3: max temperature is 125.0C.
shtc3: min temperature is -40.0C.
shtc3: start read test.
shtc3: enable clock stretching.
shtc3: normal read test.
shtc3: temperature is 29.77C.
shtc3: humidity is 66.85%.
shtc3: temperature is 29.35C.
shtc3: humidity is 66.20%.
shtc3: temperature is 28.64C.
shtc3: humidity is 53.38%.
shtc3: low power read test.
shtc3: temperature is 28.71C.
shtc3: humidity is 46.10%.
shtc3: temperature is 28.13C.
shtc3: humidity is 43.15%.
shtc3: temperature is 27.71C.
shtc3: humidity is 42.02%.
shtc3: disable clock stretching.
shtc3: normal read test.
shtc3: temperature is 26.84C.
shtc3: humidity is 41.47%.
shtc3: temperature is 26.59C.
shtc3: humidity is 41.59%.
shtc3: temperature is 26.32C.
shtc3: humidity is 41.84%.
shtc3: low power read test.
shtc3: temperature is 26.44C.
shtc3: humidity is 42.45%.
shtc3: temperature is 26.42C.
shtc3: humidity is 42.81%.
shtc3: temperature is 26.01C.
shtc3: humidity is 43.06%.
shtc3: finish read test.
```

```shell
shtc3 -e read --times=3

shtc3: 1/3.
shtc3: temperature is 22.73C.
shtc3: humidity is 48.98%.
shtc3: 2/3.
shtc3: temperature is 22.73C.
shtc3: humidity is 48.99%.
shtc3: 3/3.
shtc3: temperature is 22.73C.
shtc3: humidity is 49.00%.
```

```shell
shtc3 -e read-lp --times=3

shtc3: 1/3.
shtc3: temperature is 23.27C.
shtc3: humidity is 49.09%.
shtc3: 2/3.
shtc3: temperature is 23.27C.
shtc3: humidity is 49.08%.
shtc3: 3/3.
shtc3: temperature is 23.27C.
shtc3: humidity is 49.18%.
```

```shell
shtc3 -e reset

shtc3: soft reset.
```

```shell
shtc3 -e sleep

shtc3: sleep.
```

```shell
shtc3 -e wakeup

shtc3: wakeup.
```

```shell
shtc3 -h

Usage:
  shtc3 (-i | --information)
  shtc3 (-h | --help)
  shtc3 (-p | --port)
  shtc3 (-t reg | --test=reg)
  shtc3 (-t read | --test=read) [--times=<num>]
  shtc3 (-e read | --example=read) [--times=<num>]
  shtc3 (-e read-lp | --example=read-lp) [--times=<num>]
  shtc3 (-e reset | --example=reset)
  shtc3 (-e sleep | --example=sleep)
  shtc3 (-e wakeup | --example=wakeup)

Options:
  -e <read | read-lp | reset | sleep | wakeup>, --example=<read | read-lp | reset | sleep | wakeup>
                        Run the driver example.
  -h, --help            Show the help.
  -i, --information     Show the chip information.
  -p, --port            Display the pin connections of the current board.
  -t <reg | read>, --test=<reg | read>
                        Run the driver test.
      --times=<num>     Set the running times.([default: 3])
```

