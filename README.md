# **trice** - **TR**ace **I**ds **C** **E**mbedded *(printf() - replacement)*
embedded device C printf-like trace code and real-time PC logging (trace ID visualization) over any port

## Info shields
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/rokath/trice/goreleaser)
![GitHub issues](https://img.shields.io/github/issues/rokath/trice)
![GitHub All Releases](https://img.shields.io/github/downloads/rokath/trice/total)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/rokath/trice)
![GitHub watchers](https://img.shields.io/github/watchers/rokath/trice?label=watch)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/rokath/trice)
![GitHub commits since latest release](https://img.shields.io/github/commits-since/rokath/trice/latest)

## Link shields
[![Go Report Card](https://goreportcard.com/badge/github.com/rokath/trice)](https://goreportcard.com/report/github.com/rokath/trice) 
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Coverage Status](https://coveralls.io/repos/github/rokath/trice/badge.svg)](https://coveralls.io/github/rokath/trice)

## Search counters
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/trace)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/instrumentation)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/embedded)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/logging)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/real-time)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/debugging)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/monitoring)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/terminal)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/cli)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/diagnostics)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/tool)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/data-recording)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/rtos)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/multi-language-support)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/compression)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/timing-analysis)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/time-measurement)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/golang)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/printf)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/encryption)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/serial)
![GitHub search hit counter](https://img.shields.io/github/search/rokath/trice/C)

<!---
- [docs folder](https://github.com/rokath/trice/tree/master/docs)
- [doc index](https://rokath.github.io/trice/docs/)
--->
- [github.io/trice/](https://rokath.github.io/trice/)

## About

- C trace code (`TRICE` macros)  and real-time PC logging with `trice` (tool written in [Go](https://en.wikipedia.org/wiki/Go_(programming_language))).
- Communication without string transfer, just with IDs. Prerequisite: byte transmission to PC, low bandwidth is ok:
  - method does'nt matter: serial port, i2c, spi, DAC->ADC, toggle pin, RTT, ...
- "log in (a) trice" ![ ](./docs/README.media/life0.gif)
- Main idea: Logging strings **not** into an embedded device to display them later on a PC but keep usage comfortable and simple. The `TRICE` macros look like printf() but work under the hood completely different.

## `TRICE` macros for C|C++ code

- Real fast (**under 20 CPU clocks per trace possible!!!**) and small loggging technique, a tracer in software usable
  - for debugging dynamic behaviour during development, 
  - as runtime logger or simply for narrow bandwidth logging in the field even with encryption.
- TRICE in your code reduces the needed FLASH memory because the instrumentation code is very small (can be less 150 bytes FLASH and about 100 bytes RAM) and no printf library code nor log strings are inside the embedded device anymore.

## How it approximately works

For example change the source code line

```c
printf( "MSG: %d Kelvin\n", k );
```

into

```c
TRICE16( "MSG: %d Kelvin\n", k );
```

`trice update` (run it automatically in the tool chain) changes it to  

```c
TRICE16_1( Id(12345), "MSG: %d Kelvin\n", k );
```

and adds the *ID 12345* together with *"msg: %d Kelvin\n"* into a **t**rice **I**D **l**ist, a JSON referece file named [til.json](https://github.com/rokath/trice/blob/master/til.json).
- With the `16` in TRICE**16** you adjust the parameter size to 16 bit what allows more runtime efficient code compared to `32` or `64`.
- The appended **_1** sets the expected parameter count to 1 allowing further optimization and also a compile time parameter count check.
- During compilation the `TRICE16_1` macro is translated to only a *12345* reference and the variable *k*. The format string never sees the target.

This is a slightly simplified view:

![trice](./docs/README.media/trice4BlockDiagram.svg)

- When the programflow passes the line `TRICE16_1( Id(12345), "MSG: %d Kelvin\n", k );` the 16 bit ID *12345* and the 16 bit temperature value are transfered as one combined 32 bit value into the triceFifo, what goes really fast. Different encodings are possible. The program flow is nearly undisturbed, so **TRICE macros are usable also inside interrupts or in the scheduler**.
- For visualization a background service is needed. In the simplest case it is just an UART triggered interrupt for triceFIFO reading.
- During runtime the trice tool receives the trice as a 4 byte package `0x30 0x39 0x00 0x0F`
- The `0x30 0x39` is the ID 12345 and a map lookup delivers the format string *"msg: %d Kelvin\n"* and also the format information *"TRICE16_1"*. Now the trice tool is able to execute `printf("MSG: %d Kelvin\n", 0x000F);` and the full log information is displayed.

## `trice` PC tool

- Manages `TRICE` macro IDs inside a C|C++ source tree and extracts the strings in an ID-string list during target device compile time.
- Displays `TRICE` macros like printf() output in realtime during target device runtime. The received IDs and parameters are printed out.
- Can receive trices on several PCs and display them on a remote display server-
- Written in [Go](https://en.wikipedia.org/wiki/Go_(programming_language)), simply usage, no installer, needs to be in $PATH.

## Quick target setup

Follow these steps for instrumentation information even your target is not an ARM:

- Install the free [STCubeMX](https://www.st.com/en/development-tools/stm32cubemx.html).
- Choose from [test examples](https://github.com/rokath/trice/tree/master/test) the for you best fitting project, for example `MDK-ARM_LL_UART_RTT0_ESC_STM32F030R8_NUCLEO-64`.
- Open the `MDK-ARM_LL_UART_RTT0_ESC_STM32F030R8_NUCLEO-64.ioc` file with [STCubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) and generate without changing any setting.
- Make an empty directory `MyProject` inside the `test` folder and copy the `MDK-ARM_LL_UART_RTT0_ESC_STM32F030R8_NUCLEO-64.ioc` there and rename it to `MyProject.ioc`.
- Generate `MyProject` with CubeMX.
- Now compare the directories `MDK-ARM_LL_UART_RTT0_ESC_STM32F030R8_NUCLEO-64` and `MyProject` to see the trice instrumentation as differences.

## Possible Use Cases

- Using trice not only for **dynamic debugging** but also as **logging** technique
    is possible and gives the advantage to have very short messages (no strings) for transmission, 
    but keep in mind that the file `til.json` is the key to read all output if your devices in the field for 10 or more years.
- The `til.json` file can be deleted and regenerated from the sources anytime. In that case you get rid of all legacy strings but it is better to keep them for compability reasons.
- You can en|dis-able the TRICE code generation on file or project level, so no need to remove the TRICE macros from the code after dynamic debugging.
- You can consider TRICE also as **a kind of intelligent data compression** what could be interesting for IoT things, especially NB-IoT, where you have very low data rates.
- Also it is possible to **encrypt the trice transfer packets** to get a reasonable protection for many cases.
  - This way you can deliver firmware images with encrypted TRICE output only readable with the appropriate key and til.json.
  - XTEA is implemented as one option.
- You can even translate the til.json in **different languages**, so changing a language is just changing the til.json file.
- TRICE has intentionally no target timestamps for performance reasons. On the PC you can display the *reception timestampts*. But you can add own **timestamps as parameters** for exact embedded time measuremnets. Having several devices with trice timestamps, **network timing measurement** is possible.
- Using trice with an **RTOS** gives the option for detailed **task timing analysis**. Because of the very short execution time of a trice you could add `TRICE16( "tim:%d us, task=%d\n", us, nexTask );` to the scheduler and vizualize the output on PC. The same is possible for **interrupt timing analysis**.
- `TRICE16( "tim:%d us\n", sysTick );` before and after a function call lets you easy measure the function execution time.
- As graphical vizualisation you could use a tool similar to https://github.com/sqshq/sampler.

## Documentation
### Common
- see [./docs/Common.md](https://github.com/rokath/trice/tree/master/docs/Common.md)
### RealTimeTransfer
- see [./docs/SeggerRTT.md](https://github.com/rokath/trice/tree/master/docs/SeggerRTT.md)
### Examples
- follow [./docs/TestExamples.md](https://github.com/rokath/trice/tree/master/docs/TestExamples.md)
### Hints
- One free GPIO-Pin is already enough for using TRICE. You can transmit each basic trice (4 bytes) as bare messages over one pin:
  - ![manchester1.PNG](./docs/README.media/manchester1.PNG)
  - ![manchester2.PNG](./docs/README.media/manchester2.PNG)
  - See [https://circuitcellar.com/cc-blog/a-trace-tool-for-embedded-systems/](https://circuitcellar.com/cc-blog/a-trace-tool-for-embedded-systems/) for more information. As trace dongle you can use any spare microcontroller board with an UART together with an FTDI USB converter.
  - This slow path is usable because trice needs only few bytes for transmission.
