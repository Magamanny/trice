// Copyright 2020 Thomas.Hoehenleitner [at] seerose.net
// Use of this source code is governed by a license that can be found in the LICENSE file.

package decoder

import (
	"testing"
)

func TestBareL(t *testing.T) {
	var bareLTestTable = testTable{
		{[]byte{0, 0, 238, 153}, "s:                                                   \\ns:   MDK-ARM_LL_UART_RTT0_BARE_STM32F030_NUCLEO-64   \\ns:                                                   \\n"},
		{[]byte{239, 205, 171, 137, 4, 0, 0, 0, 0, 0, 47, 186}, `MSG: triceFifoMaxDepth = 4, select = 0`},
		{[]byte{0, 0, 24, 255}, `--------------------------------------------------`},
		{[]byte{0, 0, 24, 255}, `--------------------------------------------------`},
		{[]byte{57, 48, 144, 254}, `dbg:12345 as 16bit is 0b0011000000111001`},
		{[]byte{0, 0, 24, 255}, `--------------------------------------------------`},
		{[]byte{0, 0, 242, 253}, `sig:This ASSERT error is just a demo and no real error:`},
		{[]byte{0, 0, 24, 255}, `--------------------------------------------------`},
		{[]byte{239, 205, 171, 137, 36, 0, 0, 0, 1, 0, 47, 186}, `MSG: triceFifoMaxDepth = 36, select = 1`},
		{[]byte{126, 177, 212, 254}, `ERR:error       message, SysTick is -20098`},
		{[]byte{179, 175, 108, 255}, `WRN:warning     message, SysTick is -20557`},
		{[]byte{231, 173, 81, 254}, `ATT:attention   message, SysTick is -21017`},
		{[]byte{28, 172, 32, 255}, `DIA:diagnostics message, SysTick is -21476`},
		{[]byte{80, 170, 159, 255}, `TIM:timing      message, SysTick is -21936`},
		{[]byte{133, 168, 29, 255}, `DBG:debug       message, SysTick is -22395`},
		{[]byte{185, 166, 187, 254}, `SIG:signal      message, SysTick is -22855`},
		{[]byte{238, 164, 158, 255}, `RD:read         message, SysTick is -23314`},
		{[]byte{34, 163, 20, 254}, `WR:write        message, SysTick is -23774`},
		{[]byte{87, 161, 183, 255}, `ISR:interrupt   message, SysTick is -24233`},
		{[]byte{139, 159, 84, 255}, `MSG:normal      message, SysTick is -24693`},
		{[]byte{192, 157, 75, 254}, `INFO:informal   message, SysTick is -25152`},
		{[]byte{239, 205, 171, 137, 60, 0, 0, 0, 2, 0, 47, 186}, `MSG: triceFifoMaxDepth = 60, select = 2`},
		{[]byte{127, 177, 250, 254}, `tst:TRICE16_1   message, SysTick is -20097`},
		{[]byte{179, 175, 250, 254}, `tst:TRICE16_1   message, SysTick is -20557`},
		{[]byte{232, 173, 250, 254}, `tst:TRICE16_1   message, SysTick is -21016`},
		{[]byte{24, 172, 250, 254}, `tst:TRICE16_1   message, SysTick is -21480`},
		{[]byte{239, 205, 171, 137, 60, 0, 0, 0, 3, 0, 47, 186}, `MSG: triceFifoMaxDepth = 60, select = 3`},
		{[]byte{0, 0, 0, 0, 233, 175, 7, 255}, `tst:TRICE32_1   message, SysTick is  45033`},
		{[]byte{0, 0, 0, 0, 135, 172, 7, 255}, `tst:TRICE32_1   message, SysTick is  44167`},
		{[]byte{0, 0, 0, 0, 38, 169, 7, 255}, `tst:TRICE32_1   message, SysTick is  43302`},
		{[]byte{0, 0, 0, 0, 196, 165, 7, 255}, `tst:TRICE32_1   message, SysTick is  42436`},
		{[]byte{239, 205, 171, 137, 60, 0, 0, 0, 4, 0, 47, 186}, `MSG: triceFifoMaxDepth = 60, select = 4`},
		{[]byte{127, 1, 0, 0, 255, 128, 212, 255}, `tst:TRICE8_4  %03x ->  001  07f  -80  -01`},
		{[]byte{127, 1, 0, 0, 255, 128, 51, 255}, `tst:TRICE8_4   %4d ->    1  127 -128   -1`},
		{[]byte{127, 1, 0, 0, 255, 128, 79, 254}, `tst:TRICE8_4   %4o ->    1  177 -200   -1`},
		{[]byte{1, 0, 0, 0, 255, 127, 0, 0, 0, 128, 0, 0, 255, 255, 31, 254}, `tst:TRICE16_4  %05x ->   00001   07fff   -8000   -0001`},
		{[]byte{1, 0, 0, 0, 255, 127, 0, 0, 0, 128, 0, 0, 255, 255, 53, 254}, `tst:TRICE16_4   %6d ->       1   32767  -32768      -1`},
		{[]byte{1, 0, 0, 0, 255, 127, 0, 0, 0, 128, 0, 0, 255, 255, 36, 254}, `tst:TRICE16_4   %7o ->       1   77777 -100000      -1`},
		{[]byte{0, 0, 0, 0, 1, 0, 0, 0, 255, 127, 0, 0, 255, 255, 0, 0, 0, 128, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 255, 255, 230, 255}, `tst:TRICE32_4 %09x ->      000000001      07fffffff       -80000000     -00000001`},
		{[]byte{0, 0, 0, 0, 1, 0, 0, 0, 255, 127, 0, 0, 255, 255, 0, 0, 0, 128, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 255, 255, 42, 254}, `tst:TRICE32_4 %10d ->              1     2147483647     -2147483648            -1`},
		{[]byte{34, 17, 0, 0, 68, 51, 0, 0, 102, 85, 0, 0, 136, 119, 116, 255}, `att:TRICE64_1 0b1000100100010001100110100010001010101011001100111011110001000`},
		{[]byte{239, 205, 171, 137, 164, 0, 0, 0, 5, 0, 47, 186}, `MSG: triceFifoMaxDepth = 164, select = 5`},
		{[]byte{145, 0, 129, 255}, `tst:TRICE8_1 -111`},
		{[]byte{34, 145, 28, 255}, `tst:TRICE8_2 -111 34`},
		{[]byte{34, 145, 0, 0, 253, 0, 174, 255}, `tst:TRICE8_3 -111 34 -3`},
		{[]byte{34, 145, 0, 0, 252, 253, 245, 253}, `tst:TRICE8_4 -111 34 -3 -4`},
		{[]byte{34, 145, 0, 0, 252, 253, 0, 0, 251, 0, 215, 254}, `tst:TRICE8_5 -111 34 -3 -4 -5`},
		{[]byte{34, 145, 0, 0, 252, 253, 0, 0, 250, 251, 92, 255}, `tst:TRICE8_6 -111 34 -3 -4 -5 -6`},
		{[]byte{34, 145, 0, 0, 252, 253, 0, 0, 250, 251, 0, 0, 249, 0, 222, 254}, `tst:TRICE8_7 -111 34 -3 -4 -5 -6 -7`},
		{[]byte{34, 145, 0, 0, 252, 253, 0, 0, 250, 251, 0, 0, 248, 249, 240, 254}, `tst:TRICE8_8 -111 34 -3 -4 -5 -6 -7 -8`},
		{[]byte{239, 205, 171, 137, 164, 0, 0, 0, 6, 0, 47, 186}, `MSG: triceFifoMaxDepth = 164, select = 6`},
		{[]byte{239, 205, 171, 137, 164, 0, 0, 0, 7, 0, 47, 186}, `MSG: triceFifoMaxDepth = 164, select = 7`},
		{[]byte{145, 255, 136, 255}, `tst:TRICE16_1 -111`},
		{[]byte{145, 255, 0, 0, 34, 255, 132, 255}, `tst:TRICE16_2 -111 -222`},
		{[]byte{145, 255, 0, 0, 34, 255, 0, 0, 179, 254, 249, 253}, `tst:TRICE16_3 -111 -222 -333`},
		{[]byte{145, 255, 0, 0, 34, 255, 0, 0, 179, 254, 0, 0, 68, 254, 93, 254}, `tst:TRICE16_4 -111 -222 -333 -444`},
		{[]byte{239, 205, 171, 137, 164, 0, 0, 0, 8, 0, 47, 186}, `MSG: triceFifoMaxDepth = 164, select = 8`},
		{[]byte{35, 1, 0, 0, 254, 202, 24, 254}, `tst:TRICE32_1 0123cafe`},
		{[]byte{255, 255, 0, 0, 145, 255, 249, 255}, `tst:TRICE32_1 -111`},
		{[]byte{255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 34, 255, 38, 255}, `tst:TRICE32_2 -6f -de`},
		{[]byte{255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 34, 255, 253, 253}, `tst:TRICE32_2 -111 -222`},
		{[]byte{255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 34, 255, 0, 0, 255, 255, 0, 0, 179, 254, 49, 254}, `tst:TRICE32_3 -6f -de -14d`},
		{[]byte{255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 34, 255, 0, 0, 255, 255, 0, 0, 179, 254, 108, 254}, `tst:TRICE32_3 -111 -222 -333`},
		{[]byte{255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 34, 255, 0, 0, 255, 255, 0, 0, 179, 254, 0, 0, 255, 255, 0, 0, 68, 254, 3, 255}, `tst:TRICE32_4 -6f -de -14d -1bc`},
		{[]byte{255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 34, 255, 0, 0, 255, 255, 0, 0, 179, 254, 0, 0, 255, 255, 0, 0, 68, 254, 170, 255}, `tst:TRICE32_4 -111 -222 -333 -444`},
		{[]byte{239, 205, 171, 137, 172, 0, 0, 0, 9, 0, 47, 186}, `MSG: triceFifoMaxDepth = 172, select = 9`},
		{[]byte{255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 145, 255, 248, 255}, `tst:TRICE64_1 -111`},
		{[]byte{255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 145, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 34, 255, 111, 255}, `tst:TRICE64_2 -111 -222`},
		{[]byte{239, 205, 171, 137, 172, 0, 0, 0, 10, 0, 47, 186}, `MSG: triceFifoMaxDepth = 172, select = 10`},
		{[]byte{0, 0, 160, 254, 0, 0, 18, 254, 0, 0, 143, 254, 0, 0, 163, 255, 0, 0, 87, 255}, `e:Aw:Ba:cwr:drd:e`},
		{[]byte{0, 0, 66, 254, 0, 0, 177, 254, 0, 0, 237, 255, 0, 0, 17, 254, 0, 0, 64, 255, 0, 0, 34, 255}, `diag:fd:Gt:Htime:imessage:Jdbg:k`},
		{[]byte{239, 205, 171, 137, 172, 0, 0, 0, 11, 0, 47, 186}, `MSG: triceFifoMaxDepth = 172, select = 11`},
		{[]byte{0, 0, 204, 254, 0, 0, 137, 254, 0, 0, 85, 254, 0, 0, 195, 254, 0, 0, 22, 254, 0, 0, 237, 253, 0, 0, 105, 255}, `1234e:7m:12m:123`},
		{[]byte{239, 205, 171, 137, 172, 0, 0, 0, 12, 0, 47, 186}, `MSG: triceFifoMaxDepth = 172, select = 12`},
		{[]byte{1, 0, 129, 255}, `tst:TRICE8_1 1`},
		{[]byte{2, 1, 28, 255}, `tst:TRICE8_2 1 2`},
		{[]byte{2, 1, 0, 0, 3, 0, 174, 255}, `tst:TRICE8_3 1 2 3`},
		{[]byte{2, 1, 0, 0, 4, 3, 245, 253}, `tst:TRICE8_4 1 2 3 4`},
		{[]byte{2, 1, 0, 0, 4, 3, 0, 0, 5, 0, 215, 254}, `tst:TRICE8_5 1 2 3 4 5`},
		{[]byte{2, 1, 0, 0, 4, 3, 0, 0, 6, 5, 92, 255}, `tst:TRICE8_6 1 2 3 4 5 6`},
		{[]byte{2, 1, 0, 0, 4, 3, 0, 0, 6, 5, 0, 0, 7, 0, 222, 254}, `tst:TRICE8_7 1 2 3 4 5 6 7`},
		{[]byte{2, 1, 0, 0, 4, 3, 0, 0, 6, 5, 0, 0, 8, 7, 240, 254}, `tst:TRICE8_8 1 2 3 4 5 6 7 8`},
		{[]byte{239, 205, 171, 137, 172, 0, 0, 0, 13, 0, 47, 186}, `MSG: triceFifoMaxDepth = 172, select = 13`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 114, 116, 0, 0, 110, 105, 188, 255, 10, 103, 255, 254}, `an_example_string`},
		{[]byte{10, 0, 49, 255}, ``},
		{[]byte{10, 97, 255, 254}, `a`},
		{[]byte{110, 97, 0, 0, 10, 0, 33, 254}, `an`},
		{[]byte{110, 97, 0, 0, 10, 95, 28, 254}, `an_`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 10, 0, 64, 254}, `an_e`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 10, 120, 193, 255}, `an_ex`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 10, 0, 97, 254}, `an_exa`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 10, 109, 188, 255}, `an_exam`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 10, 0, 49, 255}, `an_examp`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 10, 108, 255, 254}, `an_exampl`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 10, 0, 33, 254}, `an_example`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 10, 95, 28, 254}, `an_example_`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 10, 0, 64, 254}, `an_example_s`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 10, 116, 193, 255}, `an_example_st`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 114, 116, 0, 0, 10, 0, 97, 254}, `an_example_str`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 114, 116, 0, 0, 10, 105, 188, 255}, `an_example_stri`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 114, 116, 0, 0, 110, 105, 188, 255, 10, 0, 49, 255}, `an_example_strin`},
		{[]byte{110, 97, 0, 0, 101, 95, 0, 0, 97, 120, 0, 0, 112, 109, 188, 255, 101, 108, 0, 0, 115, 95, 0, 0, 114, 116, 0, 0, 110, 105, 188, 255, 10, 103, 255, 254}, `an_example_string`},
		{[]byte{239, 205, 171, 137, 152, 1, 0, 0, 14, 0, 47, 186}, `MSG: triceFifoMaxDepth = 408, select = 14`},
		{[]byte{239, 205, 171, 137, 152, 1, 0, 0, 28, 0, 47, 186}, `MSG: triceFifoMaxDepth = 408, select = 28`},
		{[]byte{239, 205, 171, 137, 152, 1, 0, 0, 29, 0, 47, 186}, `MSG: triceFifoMaxDepth = 408, select = 29`},
		{[]byte{239, 205, 171, 137, 152, 1, 0, 0, 0, 0, 47, 186}, `MSG: triceFifoMaxDepth = 408, select = 0`},
	}
	doTableTest(t, NewBareDecoder, littleEndian, bareLTestTable, "unwrapped")
}

func TestBare(t *testing.T) {
	var bareTestTable = testTable{
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 0}, `MSG: triceFifoMaxDepth = 408, select = 0`},
		{[]byte{255, 24, 0, 0}, `--------------------------------------------------`},
		{[]byte{255, 24, 0, 0}, `--------------------------------------------------`},
		{[]byte{254, 144, 48, 57}, `dbg:12345 as 16bit is 0b0011000000111001`},
		{[]byte{255, 24, 0, 0}, `--------------------------------------------------`},
		{[]byte{253, 242, 0, 0}, `sig:This ASSERT error is just a demo and no real error:`},
		{[]byte{255, 24, 0, 0}, `--------------------------------------------------`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 1}, `MSG: triceFifoMaxDepth = 408, select = 1`},
		{[]byte{254, 212, 178, 179}, `ERR:error       message, SysTick is -19789`},
		{[]byte{255, 108, 176, 243}, `WRN:warning     message, SysTick is -20237`},
		{[]byte{254, 81, 175, 52}, `ATT:attention   message, SysTick is -20684`},
		{[]byte{255, 32, 173, 116}, `DIA:diagnostics message, SysTick is -21132`},
		{[]byte{255, 159, 171, 181}, `TIM:timing      message, SysTick is -21579`},
		{[]byte{255, 29, 169, 241}, `DBG:debug       message, SysTick is -22031`},
		{[]byte{254, 187, 168, 49}, `SIG:signal      message, SysTick is -22479`},
		{[]byte{255, 158, 166, 114}, `RD:read         message, SysTick is -22926`},
		{[]byte{254, 20, 164, 178}, `WR:write        message, SysTick is -23374`},
		{[]byte{255, 183, 162, 243}, `ISR:interrupt   message, SysTick is -23821`},
		{[]byte{255, 84, 161, 51}, `MSG:normal      message, SysTick is -24269`},
		{[]byte{254, 75, 159, 116}, `INFO:informal   message, SysTick is -24716`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 2}, `MSG: triceFifoMaxDepth = 408, select = 2`},
		{[]byte{254, 250, 178, 159}, `tst:TRICE16_1   message, SysTick is -19809`},
		{[]byte{254, 250, 176, 219}, `tst:TRICE16_1   message, SysTick is -20261`},
		{[]byte{254, 250, 175, 27}, `tst:TRICE16_1   message, SysTick is -20709`},
		{[]byte{254, 250, 173, 92}, `tst:TRICE16_1   message, SysTick is -21156`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 3}, `MSG: triceFifoMaxDepth = 408, select = 3`},
		{[]byte{0, 0, 0, 0, 255, 7, 177, 65}, `tst:TRICE32_1   message, SysTick is  45377`},
		{[]byte{0, 0, 0, 0, 255, 7, 174, 35}, `tst:TRICE32_1   message, SysTick is  44579`},
		{[]byte{0, 0, 0, 0, 255, 7, 170, 1}, `tst:TRICE32_1   message, SysTick is  43521`},
		{[]byte{0, 0, 0, 0, 255, 7, 167, 228}, `tst:TRICE32_1   message, SysTick is  42980`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 4}, `MSG: triceFifoMaxDepth = 408, select = 4`},
		{[]byte{0, 0, 1, 127, 255, 212, 128, 255}, `tst:TRICE8_4  %03x ->  001  07f  -80  -01`},
		{[]byte{0, 0, 1, 127, 255, 51, 128, 255}, `tst:TRICE8_4   %4d ->    1  127 -128   -1`},
		{[]byte{0, 0, 1, 127, 254, 79, 128, 255}, `tst:TRICE8_4   %4o ->    1  177 -200   -1`},
		{[]byte{0, 0, 0, 1, 0, 0, 127, 255, 0, 0, 128, 0, 254, 31, 255, 255}, `tst:TRICE16_4  %05x ->   00001   07fff   -8000   -0001`},
		{[]byte{0, 0, 0, 1, 0, 0, 127, 255, 0, 0, 128, 0, 254, 53, 255, 255}, `tst:TRICE16_4   %6d ->       1   32767  -32768      -1`},
		{[]byte{0, 0, 0, 1, 0, 0, 127, 255, 0, 0, 128, 0, 254, 36, 255, 255}, `tst:TRICE16_4   %7o ->       1   77777 -100000      -1`},
		{[]byte{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 127, 255, 0, 0, 255, 255, 0, 0, 128, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 230, 255, 255}, `tst:TRICE32_4 %09x ->      000000001      07fffffff       -80000000     -00000001`},
		{[]byte{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 127, 255, 0, 0, 255, 255, 0, 0, 128, 0, 0, 0, 0, 0, 0, 0, 255, 255, 254, 42, 255, 255}, `tst:TRICE32_4 %10d ->              1     2147483647     -2147483648            -1`},
		{[]byte{0, 0, 17, 34, 0, 0, 51, 68, 0, 0, 85, 102, 255, 116, 119, 136}, `att:TRICE64_1 0b1000100100010001100110100010001010101011001100111011110001000`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 5}, `MSG: triceFifoMaxDepth = 408, select = 5`},
		{[]byte{255, 129, 0, 145}, `tst:TRICE8_1 -111`},
		{[]byte{255, 28, 145, 34}, `tst:TRICE8_2 -111 34`},
		{[]byte{0, 0, 145, 34, 255, 174, 0, 253}, `tst:TRICE8_3 -111 34 -3`},
		{[]byte{0, 0, 145, 34, 253, 245, 253, 252}, `tst:TRICE8_4 -111 34 -3 -4`},
		{[]byte{0, 0, 145, 34, 0, 0, 253, 252, 254, 215, 0, 251}, `tst:TRICE8_5 -111 34 -3 -4 -5`},
		{[]byte{0, 0, 145, 34, 0, 0, 253, 252, 255, 92, 251, 250}, `tst:TRICE8_6 -111 34 -3 -4 -5 -6`},
		{[]byte{0, 0, 145, 34, 0, 0, 253, 252, 0, 0, 251, 250, 254, 222, 0, 249}, `tst:TRICE8_7 -111 34 -3 -4 -5 -6 -7`},
		{[]byte{0, 0, 145, 34, 0, 0, 253, 252, 0, 0, 251, 250, 254, 240, 249, 248}, `tst:TRICE8_8 -111 34 -3 -4 -5 -6 -7 -8`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 6}, `MSG: triceFifoMaxDepth = 408, select = 6`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 7}, `MSG: triceFifoMaxDepth = 408, select = 7`},
		{[]byte{255, 136, 255, 145}, `tst:TRICE16_1 -111`},
		{[]byte{0, 0, 255, 145, 255, 132, 255, 34}, `tst:TRICE16_2 -111 -222`},
		{[]byte{0, 0, 255, 145, 0, 0, 255, 34, 253, 249, 254, 179}, `tst:TRICE16_3 -111 -222 -333`},
		{[]byte{0, 0, 255, 145, 0, 0, 255, 34, 0, 0, 254, 179, 254, 93, 254, 68}, `tst:TRICE16_4 -111 -222 -333 -444`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 8}, `MSG: triceFifoMaxDepth = 408, select = 8`},
		{[]byte{0, 0, 1, 35, 254, 24, 202, 254}, `tst:TRICE32_1 0123cafe`},
		{[]byte{0, 0, 255, 255, 255, 249, 255, 145}, `tst:TRICE32_1 -111`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 255, 38, 255, 34}, `tst:TRICE32_2 -6f -de`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 253, 253, 255, 34}, `tst:TRICE32_2 -111 -222`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 0, 0, 255, 34, 0, 0, 255, 255, 254, 49, 254, 179}, `tst:TRICE32_3 -6f -de -14d`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 0, 0, 255, 34, 0, 0, 255, 255, 254, 108, 254, 179}, `tst:TRICE32_3 -111 -222 -333`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 0, 0, 255, 34, 0, 0, 255, 255, 0, 0, 254, 179, 0, 0, 255, 255, 255, 3, 254, 68}, `tst:TRICE32_4 -6f -de -14d -1bc`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 0, 0, 255, 34, 0, 0, 255, 255, 0, 0, 254, 179, 0, 0, 255, 255, 255, 170, 254, 68}, `tst:TRICE32_4 -111 -222 -333 -444`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 9}, `MSG: triceFifoMaxDepth = 408, select = 9`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 255, 248, 255, 145}, `tst:TRICE64_1 -111`},
		{[]byte{0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 145, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 255, 111, 255, 34}, `tst:TRICE64_2 -111 -222`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 10}, `MSG: triceFifoMaxDepth = 408, select = 10`},
		{[]byte{254, 160, 0, 0, 254, 18, 0, 0, 254, 143, 0, 0, 255, 163, 0, 0, 255, 87, 0, 0}, `e:Aw:Ba:cwr:drd:e`},
		{[]byte{254, 66, 0, 0, 254, 177, 0, 0, 255, 237, 0, 0, 254, 17, 0, 0, 255, 64, 0, 0, 255, 34, 0, 0}, `diag:fd:Gt:Htime:imessage:Jdbg:k`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 11}, `MSG: triceFifoMaxDepth = 408, select = 11`},
		{[]byte{254, 204, 0, 0, 254, 137, 0, 0, 254, 85, 0, 0, 254, 195, 0, 0, 254, 22, 0, 0, 253, 237, 0, 0, 255, 105, 0, 0}, `1234e:7m:12m:123`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 12}, `MSG: triceFifoMaxDepth = 408, select = 12`},
		{[]byte{255, 129, 0, 1}, `tst:TRICE8_1 1`},
		{[]byte{255, 28, 1, 2}, `tst:TRICE8_2 1 2`},
		{[]byte{0, 0, 1, 2, 255, 174, 0, 3}, `tst:TRICE8_3 1 2 3`},
		{[]byte{0, 0, 1, 2, 253, 245, 3, 4}, `tst:TRICE8_4 1 2 3 4`},
		{[]byte{0, 0, 1, 2, 0, 0, 3, 4, 254, 215, 0, 5}, `tst:TRICE8_5 1 2 3 4 5`},
		{[]byte{0, 0, 1, 2, 0, 0, 3, 4, 255, 92, 5, 6}, `tst:TRICE8_6 1 2 3 4 5 6`},
		{[]byte{0, 0, 1, 2, 0, 0, 3, 4, 0, 0, 5, 6, 254, 222, 0, 7}, `tst:TRICE8_7 1 2 3 4 5 6 7`},
		{[]byte{0, 0, 1, 2, 0, 0, 3, 4, 0, 0, 5, 6, 254, 240, 7, 8}, `tst:TRICE8_8 1 2 3 4 5 6 7 8`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 13}, `MSG: triceFifoMaxDepth = 408, select = 13`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 0, 0, 116, 114, 255, 188, 105, 110, 254, 255, 103, 10}, `an_example_string`},
		{[]byte{255, 49, 0, 10}, ``},
		{[]byte{254, 255, 97, 10}, `a`},
		{[]byte{0, 0, 97, 110, 254, 33, 0, 10}, `an`},
		{[]byte{0, 0, 97, 110, 254, 28, 95, 10}, `an_`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 254, 64, 0, 10}, `an_e`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 255, 193, 120, 10}, `an_ex`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 254, 97, 0, 10}, `an_exa`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 10}, `an_exam`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 255, 49, 0, 10}, `an_examp`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 254, 255, 108, 10}, `an_exampl`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 254, 33, 0, 10}, `an_example`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 254, 28, 95, 10}, `an_example_`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 254, 64, 0, 10}, `an_example_s`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 255, 193, 116, 10}, `an_example_st`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 0, 0, 116, 114, 254, 97, 0, 10}, `an_example_str`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 0, 0, 116, 114, 255, 188, 105, 10}, `an_example_stri`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 0, 0, 116, 114, 255, 188, 105, 110, 255, 49, 0, 10}, `an_example_strin`},
		{[]byte{0, 0, 97, 110, 0, 0, 95, 101, 0, 0, 120, 97, 255, 188, 109, 112, 0, 0, 108, 101, 0, 0, 95, 115, 0, 0, 116, 114, 255, 188, 105, 110, 254, 255, 103, 10}, `an_example_string`},
		{[]byte{137, 171, 205, 239, 0, 0, 1, 152, 186, 47, 0, 14}, `MSG: triceFifoMaxDepth = 408, select = 14`},
	}
	doTableTest(t, NewBareDecoder, bigEndian, bareTestTable, "unwrapped")
}
