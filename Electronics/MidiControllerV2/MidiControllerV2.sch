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
P 5250 3600
F 0 "U?" H 5200 2011 50  0000 C CNN
F 1 "STM32F100C8Tx" H 5200 1920 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 4650 2200 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00251732.pdf" H 5250 3600 50  0001 C CNN
	1    5250 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5FD3D94D
P 9250 3600
F 0 "SW?" V 9204 3830 50  0000 L CNN
F 1 "Rotary_Encoder_Switch" V 9295 3830 50  0000 L CNN
F 2 "" H 9100 3760 50  0001 C CNN
F 3 "~" H 9250 3860 50  0001 C CNN
	1    9250 3600
	0    1    1    0   
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5FD3EE44
P 9350 5650
F 0 "SW?" V 9304 5880 50  0000 L CNN
F 1 "Rotary_Encoder_Switch" V 9395 5880 50  0000 L CNN
F 2 "" H 9200 5810 50  0001 C CNN
F 3 "~" H 9350 5910 50  0001 C CNN
	1    9350 5650
	0    1    1    0   
$EndComp
$Sheet
S 1350 6050 1250 1250
U 5FD400C3
F0 "Keypad" 50
F1 "Keypad.sch" 50
F2 "Row1" I R 2600 6400 50 
F3 "Row2" I R 2600 6500 50 
F4 "Row3" I R 2600 6600 50 
F5 "Row4" I R 2600 6700 50 
F6 "Col1" I R 2600 6900 50 
F7 "Col2" I R 2600 7000 50 
F8 "Col3" I R 2600 7100 50 
F9 "Col4" I R 2600 7200 50 
$EndSheet
$Comp
L Device:Crystal Y?
U 1 1 5FD42C7C
P 1850 3450
F 0 "Y?" H 1850 3718 50  0000 C CNN
F 1 "Crystal" H 1850 3627 50  0000 C CNN
F 2 "" H 1850 3450 50  0001 C CNN
F 3 "~" H 1850 3450 50  0001 C CNN
	1    1850 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FD43310
P 1450 3800
F 0 "C?" H 1565 3846 50  0000 L CNN
F 1 "C" H 1565 3755 50  0000 L CNN
F 2 "" H 1488 3650 50  0001 C CNN
F 3 "~" H 1450 3800 50  0001 C CNN
	1    1450 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FD43807
P 2200 3800
F 0 "C?" H 2315 3846 50  0000 L CNN
F 1 "C" H 2315 3755 50  0000 L CNN
F 2 "" H 2238 3650 50  0001 C CNN
F 3 "~" H 2200 3800 50  0001 C CNN
	1    2200 3800
	1    0    0    -1  
$EndComp
$Sheet
S 1400 4950 550  550 
U 5FD44F32
F0 "SSD1306Oled" 50
F1 "SSD1306Oled.sch" 50
F2 "GND" I R 1950 5050 50 
F3 "+3.3V" I R 1950 5150 50 
F4 "SDA" I R 1950 5250 50 
F5 "SCL" I R 1950 5350 50 
$EndSheet
$Comp
L Device:C C?
U 1 1 5FD4914D
P 8650 5650
F 0 "C?" H 8765 5696 50  0000 L CNN
F 1 "C" H 8765 5605 50  0000 L CNN
F 2 "" H 8688 5500 50  0001 C CNN
F 3 "~" H 8650 5650 50  0001 C CNN
	1    8650 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FD49153
P 8450 3600
F 0 "C?" H 8565 3646 50  0000 L CNN
F 1 "C" H 8565 3555 50  0000 L CNN
F 2 "" H 8488 3450 50  0001 C CNN
F 3 "~" H 8450 3600 50  0001 C CNN
	1    8450 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD4C704
P 8300 5650
F 0 "R?" H 8370 5696 50  0000 L CNN
F 1 "R" H 8370 5605 50  0000 L CNN
F 2 "" V 8230 5650 50  0001 C CNN
F 3 "~" H 8300 5650 50  0001 C CNN
	1    8300 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD4CDC5
P 9200 5050
F 0 "R?" H 9270 5096 50  0000 L CNN
F 1 "R" H 9270 5005 50  0000 L CNN
F 2 "" V 9130 5050 50  0001 C CNN
F 3 "~" H 9200 5050 50  0001 C CNN
	1    9200 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD4D1F0
P 9500 5050
F 0 "R?" H 9570 5096 50  0000 L CNN
F 1 "R" H 9570 5005 50  0000 L CNN
F 2 "" V 9430 5050 50  0001 C CNN
F 3 "~" H 9500 5050 50  0001 C CNN
	1    9500 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD5070C
P 8150 3600
F 0 "R?" H 8220 3646 50  0000 L CNN
F 1 "R" H 8220 3555 50  0000 L CNN
F 2 "" V 8080 3600 50  0001 C CNN
F 3 "~" H 8150 3600 50  0001 C CNN
	1    8150 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD50DFB
P 9100 2950
F 0 "R?" H 9170 2996 50  0000 L CNN
F 1 "R" H 9170 2905 50  0000 L CNN
F 2 "" V 9030 2950 50  0001 C CNN
F 3 "~" H 9100 2950 50  0001 C CNN
	1    9100 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD51B73
P 9400 2950
F 0 "R?" H 9470 2996 50  0000 L CNN
F 1 "R" H 9470 2905 50  0000 L CNN
F 2 "" V 9330 2950 50  0001 C CNN
F 3 "~" H 9400 2950 50  0001 C CNN
	1    9400 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J?
U 1 1 5FD59E0C
P 1850 1450
F 0 "J?" H 1907 1917 50  0000 C CNN
F 1 "USB_B_Micro" H 1907 1826 50  0000 C CNN
F 2 "" H 2000 1400 50  0001 C CNN
F 3 "~" H 2000 1400 50  0001 C CNN
	1    1850 1450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5FD5CD4E
P 4900 1000
F 0 "J?" H 5008 1281 50  0000 C CNN
F 1 "Conn_01x04_Male" H 5008 1190 50  0000 C CNN
F 2 "" H 4900 1000 50  0001 C CNN
F 3 "~" H 4900 1000 50  0001 C CNN
	1    4900 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD5F56A
P 2550 1450
F 0 "R?" H 2620 1496 50  0000 L CNN
F 1 "R" H 2620 1405 50  0000 L CNN
F 2 "" V 2480 1450 50  0001 C CNN
F 3 "~" H 2550 1450 50  0001 C CNN
	1    2550 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD5FD68
P 2900 1450
F 0 "R?" H 2970 1496 50  0000 L CNN
F 1 "R" H 2970 1405 50  0000 L CNN
F 2 "" V 2830 1450 50  0001 C CNN
F 3 "~" H 2900 1450 50  0001 C CNN
	1    2900 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD60336
P 2600 1950
F 0 "R?" H 2670 1996 50  0000 L CNN
F 1 "R" H 2670 1905 50  0000 L CNN
F 2 "" V 2530 1950 50  0001 C CNN
F 3 "~" H 2600 1950 50  0001 C CNN
	1    2600 1950
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U?
U 1 1 5FD60FEB
P 5450 6600
F 0 "U?" H 5450 6842 50  0000 C CNN
F 1 "AMS1117-3.3" H 5450 6751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5450 6800 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 5550 6350 50  0001 C CNN
	1    5450 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FD6ECB4
P 8000 1400
F 0 "R?" H 8070 1446 50  0000 L CNN
F 1 "R" H 8070 1355 50  0000 L CNN
F 2 "" V 7930 1400 50  0001 C CNN
F 3 "~" H 8000 1400 50  0001 C CNN
	1    8000 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5FD6F477
P 7650 1400
F 0 "D?" H 7643 1616 50  0000 C CNN
F 1 "LED" H 7643 1525 50  0000 C CNN
F 2 "" H 7650 1400 50  0001 C CNN
F 3 "~" H 7650 1400 50  0001 C CNN
	1    7650 1400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
