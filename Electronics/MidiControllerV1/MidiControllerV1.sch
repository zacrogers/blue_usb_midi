EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "MidiController"
Date "2020-11-02"
Rev "1"
Comp "Inverse Audio"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Rotary_Encoder_Switch SW1
U 1 1 5F9F8590
P 2700 4100
F 0 "SW1" H 2700 4467 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 2700 4376 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 2550 4260 50  0001 C CNN
F 3 "~" H 2700 4360 50  0001 C CNN
	1    2700 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 5F9F990D
P 1950 1650
F 0 "J1" H 2007 2117 50  0000 C CNN
F 1 "USB_B_Micro" H 2007 2026 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 2100 1600 50  0001 C CNN
F 3 "~" H 2100 1600 50  0001 C CNN
	1    1950 1650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Female J2
U 1 1 5FA1EE3A
P 5900 2400
F 0 "J2" H 5928 2376 50  0000 L CNN
F 1 "KeypadConnector" H 5928 2285 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5900 2400 50  0001 C CNN
F 3 "~" H 5900 2400 50  0001 C CNN
	1    5900 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5FA234C8
P 2200 4350
F 0 "R3" H 2270 4396 50  0000 L CNN
F 1 "R" H 2270 4305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2130 4350 50  0001 C CNN
F 3 "~" H 2200 4350 50  0001 C CNN
	1    2200 4350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5FA24751
P 1800 4150
F 0 "R1" H 1870 4196 50  0000 L CNN
F 1 "R" H 1870 4105 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1730 4150 50  0001 C CNN
F 3 "~" H 1800 4150 50  0001 C CNN
	1    1800 4150
	-1   0    0    1   
$EndComp
$Comp
L Device:R R8
U 1 1 5FA24963
P 3250 3850
F 0 "R8" H 3320 3896 50  0000 L CNN
F 1 "R" H 3320 3805 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3180 3850 50  0001 C CNN
F 3 "~" H 3250 3850 50  0001 C CNN
	1    3250 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5FA27790
P 3250 4150
F 0 "C1" H 3365 4196 50  0000 L CNN
F 1 "C" H 3365 4105 50  0000 L CNN
F 2 "" H 3288 4000 50  0001 C CNN
F 3 "~" H 3250 4150 50  0001 C CNN
	1    3250 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5FA3A433
P 2850 1650
F 0 "R6" H 2920 1696 50  0000 L CNN
F 1 "R" H 2920 1605 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2780 1650 50  0001 C CNN
F 3 "~" H 2850 1650 50  0001 C CNN
	1    2850 1650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 5FA3A743
P 2500 1750
F 0 "R5" H 2570 1796 50  0000 L CNN
F 1 "R" H 2570 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2430 1750 50  0001 C CNN
F 3 "~" H 2500 1750 50  0001 C CNN
	1    2500 1750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 5FA3AAD7
P 3200 1800
F 0 "R7" H 3270 1846 50  0000 L CNN
F 1 "R" H 3270 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3130 1800 50  0001 C CNN
F 3 "~" H 3200 1800 50  0001 C CNN
	1    3200 1800
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5FAB830D
P 2350 1400
F 0 "#PWR0101" H 2350 1250 50  0001 C CNN
F 1 "+5V" H 2365 1573 50  0000 C CNN
F 2 "" H 2350 1400 50  0001 C CNN
F 3 "" H 2350 1400 50  0001 C CNN
	1    2350 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5FAB8AC1
P 1900 2050
F 0 "#PWR0102" H 1900 1800 50  0001 C CNN
F 1 "GND" H 1905 1877 50  0000 C CNN
F 2 "" H 1900 2050 50  0001 C CNN
F 3 "" H 1900 2050 50  0001 C CNN
	1    1900 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 2050 1900 2050
Connection ~ 1900 2050
Wire Wire Line
	1900 2050 1950 2050
Wire Wire Line
	1950 2050 2250 2050
Wire Wire Line
	2250 2050 2250 1850
Connection ~ 1950 2050
Wire Wire Line
	2700 1650 2250 1650
Wire Wire Line
	2250 1750 2350 1750
Wire Wire Line
	2250 1450 2350 1450
Wire Wire Line
	2350 1450 2350 1400
$Comp
L power:+5V #PWR0103
U 1 1 5FACC5B5
P 3200 1950
F 0 "#PWR0103" H 3200 1800 50  0001 C CNN
F 1 "+5V" H 3215 2123 50  0000 C CNN
F 2 "" H 3200 1950 50  0001 C CNN
F 3 "" H 3200 1950 50  0001 C CNN
	1    3200 1950
	-1   0    0    1   
$EndComp
Text GLabel 3350 1650 2    50   Input ~ 0
USBD+
Text GLabel 2700 1750 2    50   Input ~ 0
USBD-
Wire Wire Line
	3350 1650 3200 1650
Connection ~ 3200 1650
Wire Wire Line
	3200 1650 3000 1650
Wire Wire Line
	1800 4500 1800 4300
$Comp
L power:+3.3V #PWR0104
U 1 1 5FB3EC46
P 1950 4500
F 0 "#PWR0104" H 1950 4350 50  0001 C CNN
F 1 "+3.3V" H 1965 4673 50  0000 C CNN
F 2 "" H 1950 4500 50  0001 C CNN
F 3 "" H 1950 4500 50  0001 C CNN
	1    1950 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	2350 4100 2400 4100
Text GLabel 1650 4000 0    50   Input ~ 0
ENC1A
Text GLabel 2150 4200 0    50   Input ~ 0
ENC1B
Wire Wire Line
	1650 4000 1800 4000
Connection ~ 1800 4000
Wire Wire Line
	2150 4200 2200 4200
Connection ~ 2200 4200
Wire Wire Line
	1800 4000 2400 4000
Wire Wire Line
	1800 4500 1950 4500
Connection ~ 1950 4500
Wire Wire Line
	1950 4500 2200 4500
$Comp
L power:+3.3V #PWR0105
U 1 1 5FB5D1F8
P 3250 3700
F 0 "#PWR0105" H 3250 3550 50  0001 C CNN
F 1 "+3.3V" H 3265 3873 50  0000 C CNN
F 2 "" H 3250 3700 50  0001 C CNN
F 3 "" H 3250 3700 50  0001 C CNN
	1    3250 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 4000 3250 4000
Connection ~ 3250 4000
Wire Wire Line
	2200 4200 2400 4200
Wire Wire Line
	2350 4400 2350 4100
$Comp
L power:GND #PWR0106
U 1 1 5FB3F6A0
P 2350 4500
F 0 "#PWR0106" H 2350 4250 50  0001 C CNN
F 1 "GND" H 2355 4327 50  0000 C CNN
F 2 "" H 2350 4500 50  0001 C CNN
F 3 "" H 2350 4500 50  0001 C CNN
	1    2350 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 4400 3050 4400
Wire Wire Line
	3250 4400 3250 4300
Wire Wire Line
	2350 4500 2350 4400
Connection ~ 2350 4400
Wire Wire Line
	3000 4200 3050 4200
Wire Wire Line
	3050 4200 3050 4400
Connection ~ 3050 4400
Wire Wire Line
	3050 4400 3250 4400
Text GLabel 5700 2100 0    50   Input ~ 0
KP_R1
Text GLabel 5700 2200 0    50   Input ~ 0
KP_R2
Text GLabel 5700 2300 0    50   Input ~ 0
KP_R3
Text GLabel 5700 2400 0    50   Input ~ 0
KP_R4
Text GLabel 5700 2500 0    50   Input ~ 0
KP_C1
Text GLabel 5700 2600 0    50   Input ~ 0
KP_C2
Text GLabel 5700 2700 0    50   Input ~ 0
KP_C3
Text GLabel 5700 2800 0    50   Input ~ 0
KP_C4
Text GLabel 8600 3300 0    50   Input ~ 0
USBD+
Text GLabel 8600 3200 0    50   Input ~ 0
USBD-
Text GLabel 9300 3900 2    50   Input ~ 0
ENC1A
Text GLabel 9300 4000 2    50   Input ~ 0
ENC1B
Text GLabel 3450 4000 2    50   Input ~ 0
ENC1_SW
Wire Wire Line
	3450 4000 3250 4000
Text GLabel 9300 4200 2    50   Input ~ 0
ENC1_SW
Text GLabel 9300 3800 2    50   Input ~ 0
KP_R1
Text GLabel 9300 3700 2    50   Input ~ 0
KP_R2
Text GLabel 9300 3600 2    50   Input ~ 0
KP_R3
Text GLabel 9300 3500 2    50   Input ~ 0
KP_R4
Text GLabel 8600 2500 0    50   Input ~ 0
KP_C1
Text GLabel 8600 2600 0    50   Input ~ 0
KP_C2
Text GLabel 8600 2700 0    50   Input ~ 0
KP_C3
Text GLabel 8600 2800 0    50   Input ~ 0
KP_C4
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 5FC6F5A9
P 6050 4950
F 0 "J3" H 6078 4926 50  0000 L CNN
F 1 "OledConnector" H 6078 4835 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6050 4950 50  0001 C CNN
F 3 "~" H 6050 4950 50  0001 C CNN
	1    6050 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5FC70B0F
P 5850 5150
F 0 "#PWR0107" H 5850 4900 50  0001 C CNN
F 1 "GND" H 5855 4977 50  0000 C CNN
F 2 "" H 5850 5150 50  0001 C CNN
F 3 "" H 5850 5150 50  0001 C CNN
	1    5850 5150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5FC72124
P 5850 5050
F 0 "#PWR0108" H 5850 4900 50  0001 C CNN
F 1 "+5V" V 5865 5178 50  0000 L CNN
F 2 "" H 5850 5050 50  0001 C CNN
F 3 "" H 5850 5050 50  0001 C CNN
	1    5850 5050
	0    -1   -1   0   
$EndComp
Text GLabel 5850 4950 0    50   Input ~ 0
LCD_SDA
Text GLabel 5850 4850 0    50   Input ~ 0
LCD_SCL
Text GLabel 8600 3900 0    50   Input ~ 0
LCD_SDA
Text GLabel 8600 3800 0    50   Input ~ 0
LCD_SCL
$Comp
L Connector:Conn_01x20_Female J4
U 1 1 5FAF82EE
P 8800 3400
F 0 "J4" H 8250 4550 50  0000 L CNN
F 1 "BluePillHeaderA" H 8250 4450 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 8800 3400 50  0001 C CNN
F 3 "~" H 8800 3400 50  0001 C CNN
	1    8800 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x20_Female J5
U 1 1 5FB0BDEC
P 9100 3500
F 0 "J5" H 9050 2250 50  0000 C CNN
F 1 "BluepillHeaderB" H 8800 2350 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 9100 3500 50  0001 C CNN
F 3 "~" H 9100 3500 50  0001 C CNN
	1    9100 3500
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 5FB2633F
P 8600 4400
F 0 "#PWR0109" H 8600 4250 50  0001 C CNN
F 1 "+3.3V" V 8615 4528 50  0000 L CNN
F 2 "" H 8600 4400 50  0001 C CNN
F 3 "" H 8600 4400 50  0001 C CNN
	1    8600 4400
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0110
U 1 1 5FB26BDC
P 9300 2700
F 0 "#PWR0110" H 9300 2550 50  0001 C CNN
F 1 "+3.3V" V 9315 2828 50  0000 L CNN
F 2 "" H 9300 2700 50  0001 C CNN
F 3 "" H 9300 2700 50  0001 C CNN
	1    9300 2700
	0    1    1    0   
$EndComp
$Comp
L power:GNDREF #PWR0111
U 1 1 5FB27943
P 8150 4300
F 0 "#PWR0111" H 8150 4050 50  0001 C CNN
F 1 "GNDREF" H 8155 4127 50  0000 C CNN
F 2 "" H 8150 4300 50  0001 C CNN
F 3 "" H 8150 4300 50  0001 C CNN
	1    8150 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0112
U 1 1 5FB28652
P 9850 2500
F 0 "#PWR0112" H 9850 2250 50  0001 C CNN
F 1 "GNDREF" H 9855 2327 50  0000 C CNN
F 2 "" H 9850 2500 50  0001 C CNN
F 3 "" H 9850 2500 50  0001 C CNN
	1    9850 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 2500 9850 2500
Wire Wire Line
	9300 2600 9300 2500
Connection ~ 9300 2500
Wire Wire Line
	8600 4300 8150 4300
$Comp
L power:+5V #PWR0113
U 1 1 5FB34965
P 8600 4200
F 0 "#PWR0113" H 8600 4050 50  0001 C CNN
F 1 "+5V" V 8615 4328 50  0000 L CNN
F 2 "" H 8600 4200 50  0001 C CNN
F 3 "" H 8600 4200 50  0001 C CNN
	1    8600 4200
	0    -1   -1   0   
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW2
U 1 1 5FB5AD88
P 2800 5600
F 0 "SW2" H 2800 5967 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 2800 5876 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 2650 5760 50  0001 C CNN
F 3 "~" H 2800 5860 50  0001 C CNN
	1    2800 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5FB5AD8E
P 2300 5850
F 0 "R4" H 2370 5896 50  0000 L CNN
F 1 "R" H 2370 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2230 5850 50  0001 C CNN
F 3 "~" H 2300 5850 50  0001 C CNN
	1    2300 5850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5FB5AD94
P 1900 5650
F 0 "R2" H 1970 5696 50  0000 L CNN
F 1 "R" H 1970 5605 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1830 5650 50  0001 C CNN
F 3 "~" H 1900 5650 50  0001 C CNN
	1    1900 5650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R9
U 1 1 5FB5AD9A
P 3350 5350
F 0 "R9" H 3420 5396 50  0000 L CNN
F 1 "R" H 3420 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3280 5350 50  0001 C CNN
F 3 "~" H 3350 5350 50  0001 C CNN
	1    3350 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5FB5ADA0
P 3350 5650
F 0 "C2" H 3465 5696 50  0000 L CNN
F 1 "C" H 3465 5605 50  0000 L CNN
F 2 "" H 3388 5500 50  0001 C CNN
F 3 "~" H 3350 5650 50  0001 C CNN
	1    3350 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6000 1900 5800
$Comp
L power:+3.3V #PWR0114
U 1 1 5FB5ADA7
P 2050 6000
F 0 "#PWR0114" H 2050 5850 50  0001 C CNN
F 1 "+3.3V" H 2065 6173 50  0000 C CNN
F 2 "" H 2050 6000 50  0001 C CNN
F 3 "" H 2050 6000 50  0001 C CNN
	1    2050 6000
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 5600 2500 5600
Text GLabel 1750 5500 0    50   Input ~ 0
ENC2A
Text GLabel 2250 5700 0    50   Input ~ 0
ENC2B
Wire Wire Line
	1750 5500 1900 5500
Connection ~ 1900 5500
Wire Wire Line
	2250 5700 2300 5700
Connection ~ 2300 5700
Wire Wire Line
	1900 5500 2500 5500
Wire Wire Line
	1900 6000 2050 6000
Connection ~ 2050 6000
Wire Wire Line
	2050 6000 2300 6000
$Comp
L power:+3.3V #PWR0115
U 1 1 5FB5ADB8
P 3350 5200
F 0 "#PWR0115" H 3350 5050 50  0001 C CNN
F 1 "+3.3V" H 3365 5373 50  0000 C CNN
F 2 "" H 3350 5200 50  0001 C CNN
F 3 "" H 3350 5200 50  0001 C CNN
	1    3350 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5500 3350 5500
Connection ~ 3350 5500
Wire Wire Line
	2300 5700 2500 5700
Wire Wire Line
	2450 5900 2450 5600
$Comp
L power:GND #PWR0116
U 1 1 5FB5ADC2
P 2450 6000
F 0 "#PWR0116" H 2450 5750 50  0001 C CNN
F 1 "GND" H 2455 5827 50  0000 C CNN
F 2 "" H 2450 6000 50  0001 C CNN
F 3 "" H 2450 6000 50  0001 C CNN
	1    2450 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 5900 3150 5900
Wire Wire Line
	3350 5900 3350 5800
Wire Wire Line
	2450 6000 2450 5900
Connection ~ 2450 5900
Wire Wire Line
	3100 5700 3150 5700
Wire Wire Line
	3150 5700 3150 5900
Connection ~ 3150 5900
Wire Wire Line
	3150 5900 3350 5900
Text GLabel 3550 5500 2    50   Input ~ 0
ENC2_SW
Wire Wire Line
	3550 5500 3350 5500
Text GLabel 9300 3300 2    50   Input ~ 0
ENC2A
Text GLabel 9300 3400 2    50   Input ~ 0
ENC2B
Text GLabel 9300 3100 2    50   Input ~ 0
ENC2_SW
Wire Wire Line
	2650 1750 2700 1750
Text Notes 8600 4800 0    89   ~ 0
MCU Headers
Text Notes 2450 2500 0    89   ~ 0
USB
Text Notes 2350 6750 0    89   ~ 0
Encoders\n
Text Notes 5450 5700 0    89   ~ 0
OLED Header
Text Notes 5400 3250 0    89   ~ 0
Keypad Header\n
Wire Notes Line
	3750 1050 3750 2650
Wire Notes Line
	3750 2650 1450 2650
Wire Notes Line
	1450 2650 1450 1050
Wire Notes Line
	1700 1050 1700 1100
Wire Notes Line
	1450 1050 3750 1050
Wire Notes Line
	4150 3250 4150 7050
Wire Notes Line
	4150 7050 1200 7050
Wire Notes Line
	1200 7050 1200 3250
Wire Notes Line
	1200 3250 4150 3250
Wire Notes Line
	10300 2000 10300 5000
Wire Notes Line
	10300 5000 7750 5000
Wire Notes Line
	7750 5000 7750 2000
Wire Notes Line
	7700 2000 10300 2000
Wire Notes Line
	6850 1750 6850 3500
Wire Notes Line
	6850 3500 5000 3500
Wire Notes Line
	5000 3500 5000 1750
Wire Notes Line
	4950 1750 6850 1750
Wire Notes Line
	5150 5850 6700 5850
Wire Notes Line
	6700 5850 6700 4550
Wire Notes Line
	6700 4550 5150 4550
Wire Notes Line
	5150 4550 5150 5850
$EndSCHEMATC
