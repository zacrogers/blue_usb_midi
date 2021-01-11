EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F1:STM32F100C8Tx U?
U 1 1 5FD3C462
P 6300 3350
F 0 "U?" H 5650 5050 50  0000 C CNN
F 1 "STM32F100C8Tx" H 5900 4950 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 5700 1950 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00251732.pdf" H 6300 3350 50  0001 C CNN
	1    6300 3350
	1    0    0    -1  
$EndComp
$Sheet
S 1150 4800 750  1250
U 5FD400C3
F0 "Keypad" 50
F1 "Keypad.sch" 50
F2 "Row1" I R 1900 5150 50 
F3 "Row2" I R 1900 5250 50 
F4 "Row3" I R 1900 5350 50 
F5 "Row4" I R 1900 5450 50 
F6 "Col1" I R 1900 5650 50 
F7 "Col2" I R 1900 5750 50 
F8 "Col3" I R 1900 5850 50 
F9 "Col4" I R 1900 5950 50 
$EndSheet
$Comp
L Device:Crystal Y?
U 1 1 5FD42C7C
P 3500 1700
F 0 "Y?" H 3500 1968 50  0000 C CNN
F 1 "Crystal" H 3500 1877 50  0000 C CNN
F 2 "Crystal:Crystal_HC18-U_Vertical" H 3500 1700 50  0001 C CNN
F 3 "~" H 3500 1700 50  0001 C CNN
	1    3500 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FD43310
P 3200 2200
F 0 "C?" H 3315 2246 50  0000 L CNN
F 1 "C" H 3315 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3238 2050 50  0001 C CNN
F 3 "~" H 3200 2200 50  0001 C CNN
	1    3200 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FD43807
P 3750 2200
F 0 "C?" H 3865 2246 50  0000 L CNN
F 1 "C" H 3865 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3788 2050 50  0001 C CNN
F 3 "~" H 3750 2200 50  0001 C CNN
	1    3750 2200
	1    0    0    -1  
$EndComp
$Sheet
S 3350 5100 550  550 
U 5FD44F32
F0 "SSD1306Oled" 50
F1 "SSD1306Oled.sch" 50
F2 "GND" I R 3900 5200 50 
F3 "+3.3V" I R 3900 5300 50 
F4 "SDA" I R 3900 5400 50 
F5 "SCL" I R 3900 5500 50 
$EndSheet
$Comp
L Device:R R?
U 1 1 5FD5070C
P 9900 3250
F 0 "R?" H 9970 3296 50  0000 L CNN
F 1 "R" H 9970 3205 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 9830 3250 50  0001 C CNN
F 3 "~" H 9900 3250 50  0001 C CNN
	1    9900 3250
	-1   0    0    1   
$EndComp
$Comp
L Connector:USB_B_Micro J?
U 1 1 5FD59E0C
P 1400 1850
F 0 "J?" H 1457 2317 50  0000 C CNN
F 1 "USB_B_Micro" H 1457 2226 50  0000 C CNN
F 2 "" H 1550 1800 50  0001 C CNN
F 3 "~" H 1550 1800 50  0001 C CNN
	1    1400 1850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5FD5CD4E
P 3450 3800
F 0 "J?" H 3558 4081 50  0000 C CNN
F 1 "Conn_01x04_Male" H 3558 3990 50  0000 C CNN
F 2 "" H 3450 3800 50  0001 C CNN
F 3 "~" H 3450 3800 50  0001 C CNN
	1    3450 3800
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U?
U 1 1 5FD60FEB
P 2300 6850
F 0 "U?" H 2300 7092 50  0000 C CNN
F 1 "AMS1117-3.3" H 2300 7001 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2300 7050 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 2400 6600 50  0001 C CNN
	1    2300 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD6ECB4
P 8200 1450
F 0 "R?" H 8270 1496 50  0000 L CNN
F 1 "R" H 8270 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8130 1450 50  0001 C CNN
F 3 "~" H 8200 1450 50  0001 C CNN
	1    8200 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FFA53EE
P 9900 3100
F 0 "#PWR?" H 9900 2950 50  0001 C CNN
F 1 "+3.3V" H 9915 3273 50  0000 C CNN
F 2 "" H 9900 3100 50  0001 C CNN
F 3 "" H 9900 3100 50  0001 C CNN
	1    9900 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3800 9300 3800
$Comp
L power:GND #PWR?
U 1 1 5FFA43EA
P 9300 3800
F 0 "#PWR?" H 9300 3550 50  0001 C CNN
F 1 "GND" H 9305 3627 50  0000 C CNN
F 2 "" H 9300 3800 50  0001 C CNN
F 3 "" H 9300 3800 50  0001 C CNN
	1    9300 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3500 8900 3800
Wire Wire Line
	9000 3500 8900 3500
Wire Wire Line
	8500 3500 8500 3350
Connection ~ 8500 3500
$Comp
L power:+3.3V #PWR?
U 1 1 5FF950AD
P 8350 3300
F 0 "#PWR?" H 8350 3150 50  0001 C CNN
F 1 "+3.3V" H 8365 3473 50  0000 C CNN
F 2 "" H 8350 3300 50  0001 C CNN
F 3 "" H 8350 3300 50  0001 C CNN
	1    8350 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 3650 8500 3500
Wire Wire Line
	8800 3400 8800 3350
Wire Wire Line
	9000 3400 8800 3400
Wire Wire Line
	8800 3600 8800 3650
Wire Wire Line
	9000 3600 8800 3600
$Comp
L Device:C C?
U 1 1 5FD49153
P 9900 3550
F 0 "C?" H 10015 3596 50  0000 L CNN
F 1 "C" H 10015 3505 50  0000 L CNN
F 2 "" H 9938 3400 50  0001 C CNN
F 3 "~" H 9900 3550 50  0001 C CNN
	1    9900 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5FD3D94D
P 9300 3500
F 0 "SW?" H 9100 3900 50  0000 L CNN
F 1 "Encoder" H 9100 3800 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 9150 3660 50  0001 C CNN
F 3 "~" H 9300 3760 50  0001 C CNN
	1    9300 3500
	1    0    0    -1  
$EndComp
Connection ~ 9300 3800
Wire Wire Line
	9300 3800 9600 3800
Wire Wire Line
	9600 3600 9600 3800
Connection ~ 9600 3800
Wire Wire Line
	9600 3800 9900 3800
Wire Wire Line
	9900 3800 9900 3700
Wire Wire Line
	9600 3400 9900 3400
Connection ~ 9900 3400
$Comp
L Device:R R?
U 1 1 5FFC5E6A
P 8650 3350
F 0 "R?" V 8550 3350 50  0000 C CNN
F 1 "R" V 8650 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8580 3350 50  0001 C CNN
F 3 "~" H 8650 3350 50  0001 C CNN
	1    8650 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FFC6555
P 8650 3650
F 0 "R?" V 8443 3650 50  0000 C CNN
F 1 "R" V 8650 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8580 3650 50  0001 C CNN
F 3 "~" H 8650 3650 50  0001 C CNN
	1    8650 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 3500 8350 3500
Wire Wire Line
	8350 3500 8350 3300
$Comp
L Device:R R?
U 1 1 5FFCDF91
P 9900 5000
F 0 "R?" H 9970 5046 50  0000 L CNN
F 1 "R" H 9970 4955 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 9830 5000 50  0001 C CNN
F 3 "~" H 9900 5000 50  0001 C CNN
	1    9900 5000
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FFCDF97
P 9900 4850
F 0 "#PWR?" H 9900 4700 50  0001 C CNN
F 1 "+3.3V" H 9915 5023 50  0000 C CNN
F 2 "" H 9900 4850 50  0001 C CNN
F 3 "" H 9900 4850 50  0001 C CNN
	1    9900 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 5550 9300 5550
$Comp
L power:GND #PWR?
U 1 1 5FFCDF9E
P 9300 5550
F 0 "#PWR?" H 9300 5300 50  0001 C CNN
F 1 "GND" H 9305 5377 50  0000 C CNN
F 2 "" H 9300 5550 50  0001 C CNN
F 3 "" H 9300 5550 50  0001 C CNN
	1    9300 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 5250 8900 5550
Wire Wire Line
	9000 5250 8900 5250
Wire Wire Line
	8500 5250 8500 5100
Connection ~ 8500 5250
$Comp
L power:+3.3V #PWR?
U 1 1 5FFCDFA8
P 8350 5050
F 0 "#PWR?" H 8350 4900 50  0001 C CNN
F 1 "+3.3V" H 8365 5223 50  0000 C CNN
F 2 "" H 8350 5050 50  0001 C CNN
F 3 "" H 8350 5050 50  0001 C CNN
	1    8350 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 5400 8500 5250
Wire Wire Line
	8800 5150 8800 5100
Wire Wire Line
	9000 5150 8800 5150
Wire Wire Line
	8800 5350 8800 5400
Wire Wire Line
	9000 5350 8800 5350
$Comp
L Device:C C?
U 1 1 5FFCDFB3
P 9900 5300
F 0 "C?" H 10015 5346 50  0000 L CNN
F 1 "C" H 10015 5255 50  0000 L CNN
F 2 "" H 9938 5150 50  0001 C CNN
F 3 "~" H 9900 5300 50  0001 C CNN
	1    9900 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5FFCDFB9
P 9300 5250
F 0 "SW?" H 9100 5650 50  0000 L CNN
F 1 "Encoder" H 9100 5550 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 9150 5410 50  0001 C CNN
F 3 "~" H 9300 5510 50  0001 C CNN
	1    9300 5250
	1    0    0    -1  
$EndComp
Connection ~ 9300 5550
Wire Wire Line
	9300 5550 9600 5550
Wire Wire Line
	9600 5350 9600 5550
Connection ~ 9600 5550
Wire Wire Line
	9600 5550 9900 5550
Wire Wire Line
	9900 5550 9900 5450
Wire Wire Line
	9600 5150 9900 5150
Connection ~ 9900 5150
$Comp
L Device:R R?
U 1 1 5FFCDFC7
P 8650 5100
F 0 "R?" V 8443 5100 50  0000 C CNN
F 1 "R" V 8534 5100 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8580 5100 50  0001 C CNN
F 3 "~" H 8650 5100 50  0001 C CNN
	1    8650 5100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FFCDFCD
P 8650 5400
F 0 "R?" V 8443 5400 50  0000 C CNN
F 1 "R" V 8534 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8580 5400 50  0001 C CNN
F 3 "~" H 8650 5400 50  0001 C CNN
	1    8650 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 5250 8350 5250
Wire Wire Line
	8350 5250 8350 5050
Text GLabel 8800 3000 0    50   Input ~ 0
ENC1A
Text GLabel 8800 3850 0    50   Input ~ 0
ENC1B
Wire Wire Line
	8800 3850 8800 3650
Connection ~ 8800 3650
Wire Wire Line
	8800 3350 8800 3000
Connection ~ 8800 3350
Text GLabel 8800 4750 0    50   Input ~ 0
ENC2A
Text GLabel 8800 5600 0    50   Input ~ 0
ENC2B
Wire Wire Line
	8800 5600 8800 5400
Connection ~ 8800 5400
Wire Wire Line
	8800 5100 8800 4750
Connection ~ 8800 5100
Text GLabel 5600 2850 0    50   Input ~ 0
ENC1_SW
Text GLabel 10200 5150 2    50   Input ~ 0
ENC2_SW
Wire Wire Line
	10200 5150 9900 5150
Wire Wire Line
	9900 3400 10200 3400
$Comp
L power:GND #PWR?
U 1 1 5FFDBBA0
P 1300 2250
F 0 "#PWR?" H 1300 2000 50  0001 C CNN
F 1 "GND" H 1305 2077 50  0000 C CNN
F 2 "" H 1300 2250 50  0001 C CNN
F 3 "" H 1300 2250 50  0001 C CNN
	1    1300 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2250 1400 2250
Wire Wire Line
	1700 2250 1700 2050
Connection ~ 1300 2250
Connection ~ 1400 2250
Wire Wire Line
	1400 2250 1700 2250
$Comp
L Device:R R?
U 1 1 5FFDF02F
P 1850 1950
F 0 "R?" V 1950 1950 50  0000 C CNN
F 1 "R" V 1850 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1780 1950 50  0001 C CNN
F 3 "~" H 1850 1950 50  0001 C CNN
	1    1850 1950
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FFE3909
P 1850 1850
F 0 "R?" V 1750 1850 50  0000 C CNN
F 1 "R" V 1850 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1780 1850 50  0001 C CNN
F 3 "~" H 1850 1850 50  0001 C CNN
	1    1850 1850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FFE8918
P 2000 1700
F 0 "R?" V 2100 1700 50  0000 C CNN
F 1 "R" V 2000 1700 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1930 1700 50  0001 C CNN
F 3 "~" H 2000 1700 50  0001 C CNN
	1    2000 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1650 1700 1550
Wire Wire Line
	1700 1550 1850 1550
$Comp
L power:+5V #PWR?
U 1 1 5FFEB3CB
P 1850 1550
F 0 "#PWR?" H 1850 1400 50  0001 C CNN
F 1 "+5V" H 1865 1723 50  0000 C CNN
F 2 "" H 1850 1550 50  0001 C CNN
F 3 "" H 1850 1550 50  0001 C CNN
	1    1850 1550
	1    0    0    -1  
$EndComp
Connection ~ 1850 1550
Wire Wire Line
	1850 1550 2000 1550
Wire Wire Line
	2100 1850 2000 1850
Connection ~ 2000 1850
Wire Wire Line
	2000 1950 2100 1950
Text GLabel 3200 1700 0    50   Input ~ 0
OSCIN
Text GLabel 3750 1700 2    50   Input ~ 0
OSCOUT
$Comp
L power:GND #PWR?
U 1 1 6000CFD7
P 2300 7300
F 0 "#PWR?" H 2300 7050 50  0001 C CNN
F 1 "GND" H 2305 7127 50  0000 C CNN
F 2 "" H 2300 7300 50  0001 C CNN
F 3 "" H 2300 7300 50  0001 C CNN
	1    2300 7300
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6000D376
P 1300 6850
F 0 "#PWR?" H 1300 6700 50  0001 C CNN
F 1 "+5V" V 1315 6978 50  0000 L CNN
F 2 "" H 1300 6850 50  0001 C CNN
F 3 "" H 1300 6850 50  0001 C CNN
	1    1300 6850
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 6000E2EF
P 3350 6850
F 0 "#PWR?" H 3350 6700 50  0001 C CNN
F 1 "+3.3V" V 3365 6978 50  0000 L CNN
F 2 "" H 3350 6850 50  0001 C CNN
F 3 "" H 3350 6850 50  0001 C CNN
	1    3350 6850
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 60010165
P 1850 7000
F 0 "C?" H 1965 7046 50  0000 L CNN
F 1 "C" H 1965 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 1888 6850 50  0001 C CNN
F 3 "~" H 1850 7000 50  0001 C CNN
	1    1850 7000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60010A99
P 1500 7000
F 0 "C?" H 1615 7046 50  0000 L CNN
F 1 "C" H 1615 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 1538 6850 50  0001 C CNN
F 3 "~" H 1500 7000 50  0001 C CNN
	1    1500 7000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6001457C
P 3100 7000
F 0 "C?" H 3215 7046 50  0000 L CNN
F 1 "C" H 3215 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3138 6850 50  0001 C CNN
F 3 "~" H 3100 7000 50  0001 C CNN
	1    3100 7000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60014582
P 2750 7000
F 0 "C?" H 2865 7046 50  0000 L CNN
F 1 "C" H 2865 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 2788 6850 50  0001 C CNN
F 3 "~" H 2750 7000 50  0001 C CNN
	1    2750 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 6850 1500 6850
Connection ~ 1500 6850
Wire Wire Line
	1500 6850 1850 6850
Connection ~ 1850 6850
Wire Wire Line
	1850 6850 2000 6850
Wire Wire Line
	2600 6850 2750 6850
Connection ~ 2750 6850
Wire Wire Line
	2750 6850 3100 6850
Connection ~ 3100 6850
Wire Wire Line
	3100 6850 3350 6850
Wire Wire Line
	2300 7300 2750 7300
Wire Wire Line
	3100 7300 3100 7150
Wire Wire Line
	2750 7150 2750 7300
Connection ~ 2750 7300
Wire Wire Line
	2750 7300 3100 7300
Wire Wire Line
	2300 7300 2300 7150
Connection ~ 2300 7300
Wire Wire Line
	2300 7300 1850 7300
Wire Wire Line
	1850 7300 1850 7150
Wire Wire Line
	1850 7300 1500 7300
Wire Wire Line
	1500 7300 1500 7150
Connection ~ 1850 7300
Text GLabel 3900 5400 2    50   Input ~ 0
OLED_SDA
Text GLabel 3900 5500 2    50   Input ~ 0
OLED_SCL
Text GLabel 1900 5150 2    50   Input ~ 0
KP_R1
Text GLabel 1900 5250 2    50   Input ~ 0
KP_R2
Text GLabel 1900 5350 2    50   Input ~ 0
KP_R3
Text GLabel 1900 5450 2    50   Input ~ 0
KP_R4
Text GLabel 1900 5650 2    50   Input ~ 0
KP_C1
Text GLabel 1900 5750 2    50   Input ~ 0
KP_C2
Text GLabel 1900 5850 2    50   Input ~ 0
KP_C3
Text GLabel 1900 5950 2    50   Input ~ 0
KP_C4
Text GLabel 6900 3350 2    50   Input ~ 0
KP_R1
Text GLabel 6900 3450 2    50   Input ~ 0
KP_R2
Text GLabel 6900 3550 2    50   Input ~ 0
KP_R3
Text GLabel 6900 3650 2    50   Input ~ 0
KP_R4
Text GLabel 5600 4350 0    50   Input ~ 0
KP_C1
Text GLabel 5600 4450 0    50   Input ~ 0
KP_C2
Text GLabel 5600 4550 0    50   Input ~ 0
KP_C3
Text GLabel 6900 3850 2    50   Input ~ 0
ENC2A
Text GLabel 6900 3750 2    50   Input ~ 0
ENC2B
Text GLabel 5600 3250 0    50   Input ~ 0
ENC2_SW
Text GLabel 6900 3150 2    50   Input ~ 0
ENC1B
Text GLabel 6900 3250 2    50   Input ~ 0
ENC1A
Text GLabel 2100 1950 2    50   Input ~ 0
USBD-
Text GLabel 2100 1850 2    50   Input ~ 0
USBD+
Text GLabel 6900 4350 2    50   Input ~ 0
USBD+
Text GLabel 6900 4250 2    50   Input ~ 0
USBD-
Text GLabel 3650 3900 2    50   Input ~ 0
SWDIO
Text GLabel 3650 4000 2    50   Input ~ 0
SWDCLK
Text GLabel 6900 4450 2    50   Input ~ 0
SWDIO
Text GLabel 6900 4550 2    50   Input ~ 0
SWDCLK
$Comp
L power:GND #PWR?
U 1 1 60061291
P 6100 5000
F 0 "#PWR?" H 6100 4750 50  0001 C CNN
F 1 "GND" H 6105 4827 50  0000 C CNN
F 2 "" H 6100 5000 50  0001 C CNN
F 3 "" H 6100 5000 50  0001 C CNN
	1    6100 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5000 6100 4850
Wire Wire Line
	6100 4850 6200 4850
Connection ~ 6100 4850
Connection ~ 6200 4850
Wire Wire Line
	6200 4850 6300 4850
Connection ~ 6300 4850
Wire Wire Line
	6300 4850 6400 4850
Text GLabel 5600 3850 0    50   Input ~ 0
OLED_SDA
Text GLabel 5600 3750 0    50   Input ~ 0
OLED_SCL
$Comp
L Switch:SW_DPST SW?
U 1 1 600A51C9
P 9850 1450
F 0 "SW?" H 9850 1775 50  0000 C CNN
F 1 "SW_DPST" H 9850 1684 50  0000 C CNN
F 2 "" H 9850 1450 50  0001 C CNN
F 3 "~" H 9850 1450 50  0001 C CNN
	1    9850 1450
	1    0    0    -1  
$EndComp
Text GLabel 10300 1450 2    50   Input ~ 0
RESET
$Comp
L Device:C C?
U 1 1 600A85A7
P 9850 1900
F 0 "C?" V 9598 1900 50  0000 C CNN
F 1 "C" V 9689 1900 50  0000 C CNN
F 2 "" H 9888 1750 50  0001 C CNN
F 3 "~" H 9850 1900 50  0001 C CNN
	1    9850 1900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 600A9CEC
P 9650 1950
F 0 "#PWR?" H 9650 1700 50  0001 C CNN
F 1 "GND" H 9655 1777 50  0000 C CNN
F 2 "" H 9650 1950 50  0001 C CNN
F 3 "" H 9650 1950 50  0001 C CNN
	1    9650 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1950 9650 1900
Connection ~ 9650 1550
Wire Wire Line
	9650 1550 9650 1350
Wire Wire Line
	9700 1900 9650 1900
Connection ~ 9650 1900
Wire Wire Line
	9650 1900 9650 1550
Wire Wire Line
	10050 1350 10050 1450
Wire Wire Line
	10050 1900 10000 1900
Connection ~ 10050 1550
Wire Wire Line
	10050 1550 10050 1900
Wire Wire Line
	10300 1450 10050 1450
Connection ~ 10050 1450
Wire Wire Line
	10050 1450 10050 1550
$Comp
L Device:R R?
U 1 1 600B0C27
P 10150 1200
F 0 "R?" H 10220 1246 50  0000 L CNN
F 1 "R" H 10220 1155 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 10080 1200 50  0001 C CNN
F 3 "~" H 10150 1200 50  0001 C CNN
	1    10150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1350 10150 1350
Connection ~ 10050 1350
$Comp
L power:+3.3V #PWR?
U 1 1 600B35CD
P 10150 1050
F 0 "#PWR?" H 10150 900 50  0001 C CNN
F 1 "+3.3V" H 10165 1223 50  0000 C CNN
F 2 "" H 10150 1050 50  0001 C CNN
F 3 "" H 10150 1050 50  0001 C CNN
	1    10150 1050
	1    0    0    -1  
$EndComp
Text GLabel 5600 2050 0    50   Input ~ 0
RESET
Text GLabel 5600 2250 0    50   Input ~ 0
BOOT0
Text GLabel 5600 3350 0    50   Input ~ 0
BOOT1
$Comp
L Device:LED D?
U 1 1 600C84D3
P 8200 1750
F 0 "D?" V 8239 1633 50  0000 R CNN
F 1 "LED" V 8148 1633 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 8200 1750 50  0001 C CNN
F 3 "~" H 8200 1750 50  0001 C CNN
	1    8200 1750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 600CF4BD
P 8200 1900
F 0 "#PWR?" H 8200 1650 50  0001 C CNN
F 1 "GND" H 8205 1727 50  0000 C CNN
F 2 "" H 8200 1900 50  0001 C CNN
F 3 "" H 8200 1900 50  0001 C CNN
	1    8200 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 600CFE46
P 8200 1300
F 0 "#PWR?" H 8200 1150 50  0001 C CNN
F 1 "+3.3V" H 8215 1473 50  0000 C CNN
F 2 "" H 8200 1300 50  0001 C CNN
F 3 "" H 8200 1300 50  0001 C CNN
	1    8200 1300
	1    0    0    -1  
$EndComp
Text GLabel 5600 4650 0    50   Input ~ 0
KP_C4
$Comp
L power:GND #PWR?
U 1 1 601061A7
P 4100 3800
F 0 "#PWR?" H 4100 3550 50  0001 C CNN
F 1 "GND" H 4105 3627 50  0000 C CNN
F 2 "" H 4100 3800 50  0001 C CNN
F 3 "" H 4100 3800 50  0001 C CNN
	1    4100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3800 3650 3800
$Comp
L power:+3.3V #PWR?
U 1 1 6010C3A6
P 3650 3700
F 0 "#PWR?" H 3650 3550 50  0001 C CNN
F 1 "+3.3V" V 3665 3828 50  0000 L CNN
F 2 "" H 3650 3700 50  0001 C CNN
F 3 "" H 3650 3700 50  0001 C CNN
	1    3650 3700
	0    1    1    0   
$EndComp
Text GLabel 10200 3400 2    50   Input ~ 0
ENC1_SW
$Comp
L power:+3.3V #PWR?
U 1 1 60113338
P 3900 5300
F 0 "#PWR?" H 3900 5150 50  0001 C CNN
F 1 "+3.3V" V 3915 5428 50  0000 L CNN
F 2 "" H 3900 5300 50  0001 C CNN
F 3 "" H 3900 5300 50  0001 C CNN
	1    3900 5300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60113D3E
P 4450 5200
F 0 "#PWR?" H 4450 4950 50  0001 C CNN
F 1 "GND" H 4455 5027 50  0000 C CNN
F 2 "" H 4450 5200 50  0001 C CNN
F 3 "" H 4450 5200 50  0001 C CNN
	1    4450 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 5200 3900 5200
$Comp
L power:+3.3V #PWR?
U 1 1 6011B7FC
P 6500 1750
F 0 "#PWR?" H 6500 1600 50  0001 C CNN
F 1 "+3.3V" H 6515 1923 50  0000 C CNN
F 2 "" H 6500 1750 50  0001 C CNN
F 3 "" H 6500 1750 50  0001 C CNN
	1    6500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 1750 6500 1850
Wire Wire Line
	6100 1850 6200 1850
Connection ~ 6500 1850
Connection ~ 6200 1850
Wire Wire Line
	6200 1850 6300 1850
Connection ~ 6300 1850
Wire Wire Line
	6300 1850 6400 1850
Connection ~ 6400 1850
Wire Wire Line
	6400 1850 6500 1850
Text GLabel 5600 2450 0    50   Input ~ 0
OSCIN
Text GLabel 5600 2550 0    50   Input ~ 0
OSCOUT
Wire Wire Line
	3200 2350 3500 2350
$Comp
L power:GND #PWR?
U 1 1 601602D4
P 3500 2350
F 0 "#PWR?" H 3500 2100 50  0001 C CNN
F 1 "GND" H 3505 2177 50  0000 C CNN
F 2 "" H 3500 2350 50  0001 C CNN
F 3 "" H 3500 2350 50  0001 C CNN
	1    3500 2350
	1    0    0    -1  
$EndComp
Connection ~ 3500 2350
Wire Wire Line
	3500 2350 3750 2350
$Comp
L Device:R R?
U 1 1 601654BC
P 3500 2000
F 0 "R?" V 3400 2000 50  0000 C CNN
F 1 "R" V 3500 2000 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" V 3430 2000 50  0001 C CNN
F 3 "~" H 3500 2000 50  0001 C CNN
	1    3500 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 2000 3750 2000
Wire Wire Line
	3750 2000 3750 2050
Wire Wire Line
	3200 2050 3200 2000
Wire Wire Line
	3200 2000 3350 2000
Wire Wire Line
	3350 1700 3200 1700
Wire Wire Line
	3200 1700 3200 2000
Connection ~ 3200 2000
Wire Wire Line
	3650 1700 3750 1700
Wire Wire Line
	3750 1700 3750 2000
Connection ~ 3750 2000
$Comp
L Device:C C?
U 1 1 60195DB1
P 4800 6950
F 0 "C?" H 4915 6996 50  0000 L CNN
F 1 "C" H 4915 6905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 4838 6800 50  0001 C CNN
F 3 "~" H 4800 6950 50  0001 C CNN
	1    4800 6950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60196800
P 5150 6950
F 0 "C?" H 5265 6996 50  0000 L CNN
F 1 "C" H 5265 6905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5188 6800 50  0001 C CNN
F 3 "~" H 5150 6950 50  0001 C CNN
	1    5150 6950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60199A0C
P 5550 6950
F 0 "C?" H 5665 6996 50  0000 L CNN
F 1 "C" H 5665 6905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5588 6800 50  0001 C CNN
F 3 "~" H 5550 6950 50  0001 C CNN
	1    5550 6950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60199A12
P 5900 6950
F 0 "C?" H 6015 6996 50  0000 L CNN
F 1 "C" H 6015 6905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5938 6800 50  0001 C CNN
F 3 "~" H 5900 6950 50  0001 C CNN
	1    5900 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 602008E8
P 5350 7200
F 0 "#PWR?" H 5350 6950 50  0001 C CNN
F 1 "GND" H 5355 7027 50  0000 C CNN
F 2 "" H 5350 7200 50  0001 C CNN
F 3 "" H 5350 7200 50  0001 C CNN
	1    5350 7200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 60200EC5
P 5350 6650
F 0 "#PWR?" H 5350 6500 50  0001 C CNN
F 1 "+3.3V" H 5365 6823 50  0000 C CNN
F 2 "" H 5350 6650 50  0001 C CNN
F 3 "" H 5350 6650 50  0001 C CNN
	1    5350 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 7200 5150 7200
Wire Wire Line
	4800 7200 4800 7100
Wire Wire Line
	5350 7200 5550 7200
Wire Wire Line
	5900 7200 5900 7100
Connection ~ 5350 7200
Wire Wire Line
	5550 7100 5550 7200
Connection ~ 5550 7200
Wire Wire Line
	5550 7200 5900 7200
Wire Wire Line
	5150 7200 5150 7100
Connection ~ 5150 7200
Wire Wire Line
	5150 7200 4800 7200
Wire Wire Line
	5350 6650 5150 6650
Wire Wire Line
	4800 6650 4800 6800
Wire Wire Line
	5900 6650 5900 6800
Wire Wire Line
	5350 6650 5550 6650
Connection ~ 5350 6650
Wire Wire Line
	5550 6800 5550 6650
Connection ~ 5550 6650
Wire Wire Line
	5550 6650 5900 6650
Wire Wire Line
	5150 6800 5150 6650
Connection ~ 5150 6650
Wire Wire Line
	5150 6650 4800 6650
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 6028C521
P 1850 3750
F 0 "J?" H 1850 4100 50  0000 C CNN
F 1 "BOOT1_H" H 2000 4000 50  0000 C CNN
F 2 "" H 1850 3750 50  0001 C CNN
F 3 "~" H 1850 3750 50  0001 C CNN
	1    1850 3750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 6028CD9A
P 1650 3750
F 0 "J?" H 1850 3400 50  0000 R CNN
F 1 "BOOT0_H" H 1850 3500 50  0000 R CNN
F 2 "" H 1650 3750 50  0001 C CNN
F 3 "~" H 1650 3750 50  0001 C CNN
	1    1650 3750
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 602985DA
P 2200 3750
F 0 "R?" V 1993 3750 50  0000 C CNN
F 1 "R" V 2084 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2130 3750 50  0001 C CNN
F 3 "~" H 2200 3750 50  0001 C CNN
	1    2200 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 60298F10
P 1300 3750
F 0 "R?" V 1093 3750 50  0000 C CNN
F 1 "R" V 1184 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1230 3750 50  0001 C CNN
F 3 "~" H 1300 3750 50  0001 C CNN
	1    1300 3750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60299A15
P 2050 3950
F 0 "#PWR?" H 2050 3700 50  0001 C CNN
F 1 "GND" H 2055 3777 50  0000 C CNN
F 2 "" H 2050 3950 50  0001 C CNN
F 3 "" H 2050 3950 50  0001 C CNN
	1    2050 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 3850 2050 3950
Wire Wire Line
	1450 3950 1450 3850
Wire Wire Line
	2050 3950 1450 3950
Connection ~ 2050 3950
Wire Wire Line
	2050 3650 2050 3550
Wire Wire Line
	2050 3550 1450 3550
Wire Wire Line
	1450 3550 1450 3650
$Comp
L power:+3.3V #PWR?
U 1 1 602AA6D0
P 1450 3350
F 0 "#PWR?" H 1450 3200 50  0001 C CNN
F 1 "+3.3V" H 1465 3523 50  0000 C CNN
F 2 "" H 1450 3350 50  0001 C CNN
F 3 "" H 1450 3350 50  0001 C CNN
	1    1450 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3350 1450 3550
Connection ~ 1450 3550
Text GLabel 1150 3750 0    50   Input ~ 0
BOOT0
Text GLabel 2350 3750 2    50   Input ~ 0
BOOT1
$EndSCHEMATC
