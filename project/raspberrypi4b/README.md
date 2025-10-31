### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(shtc3 REQUIRED)
```
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
   shtc3 (-t rcead | --test=read) [--times=<num>]
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
./shtc3 -i

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
./shtc3 -p

shtc3: SCL connected to GPIO3(BCM).
shtc3: SDA connected to GPIO2(BCM).
```

```shell
./shtc3 -t reg

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
./shtc3 -t read --times=3

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
shtc3: temperature is 24.00C.
shtc3: humidity is 46.60%.
shtc3: temperature is 23.96C.
shtc3: humidity is 46.47%.
shtc3: temperature is 23.97C.
shtc3: humidity is 46.44%.
shtc3: low power read test.
shtc3: temperature is 24.39C.
shtc3: humidity is 46.50%.
shtc3: temperature is 24.52C.
shtc3: humidity is 46.53%.
shtc3: temperature is 24.45C.
shtc3: humidity is 46.46%.
shtc3: finish read test.
```

```shell
./shtc3 -e read --times=3

shtc3: 1/3.
shtc3: temperature is 24.16C.
shtc3: humidity is 46.26%.
shtc3: 2/3.
shtc3: temperature is 24.13C.
shtc3: humidity is 46.25%.
shtc3: 3/3.
shtc3: temperature is 24.13C.
shtc3: humidity is 46.24%.
```

```shell
./shtc3 -e read-lp --times=3

shtc3: 1/3.
shtc3: temperature is 24.58C.
shtc3: humidity is 46.26%.
shtc3: 2/3.
shtc3: temperature is 24.58C.
shtc3: humidity is 46.43%.
shtc3: 3/3.
shtc3: temperature is 24.51C.
shtc3: humidity is 46.36%.
```

```shell
./shtc3 -e reset

shtc3: soft reset.
```

```shell
./shtc3 -e sleep

shtc3: sleep.
```

```shell
./shtc3 -e wakeup

shtc3: wakeup.
```

```shell
./shtc3 -h

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
