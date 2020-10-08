EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "OpeNITHM Controller Board"
Date "2020-06-03"
Rev "v2.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 8450 2050 2    50   ~ 0
KEY_0
Text Label 8450 1850 2    50   ~ 0
KEY_1
Text Label 8450 1650 2    50   ~ 0
KEY_2
Text Label 8450 1450 2    50   ~ 0
KEY_3
Text Label 10650 3550 2    50   ~ 0
KEY_4
Text Label 10650 3350 2    50   ~ 0
KEY_5
Text Notes 8150 850  0    79   ~ 16
Capacitive Touch Sensing
Text Notes 3100 900  0    79   ~ 16
Teensy LC Headers
Text Notes 2750 2100 0    39   ~ 0
RGB lighting
$Comp
L Device:R R22
U 1 1 5C729DF3
P 1900 7050
F 0 "R22" H 1750 7100 50  0000 C CNN
F 1 "R_AIR" H 1750 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 1830 7050 50  0001 C CNN
F 3 "~" H 1900 7050 50  0001 C CNN
	1    1900 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5C72A0CC
P 1900 7250
F 0 "#PWR0114" H 1900 7000 50  0001 C CNN
F 1 "GND" H 1905 7077 50  0000 C CNN
F 2 "" H 1900 7250 50  0001 C CNN
F 3 "" H 1900 7250 50  0001 C CNN
	1    1900 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 7250 1900 7200
Text Label 1600 6800 0    50   ~ 0
AIR_0
Text Notes 7100 6900 0    157  ~ 31
OpeNITHM (32 Key Teensy ver.)
Text Notes 7150 7100 0    79   ~ 0
Design by VeroxZik based on work by WinEpic and mickabrig7
Wire Wire Line
	1900 6800 1900 6900
$Comp
L power:GND #PWR0116
U 1 1 5C56559A
P 2350 7250
F 0 "#PWR0116" H 2350 7000 50  0001 C CNN
F 1 "GND" H 2355 7077 50  0000 C CNN
F 2 "" H 2350 7250 50  0001 C CNN
F 3 "" H 2350 7250 50  0001 C CNN
	1    2350 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 7250 2350 7200
Text Label 2050 6800 0    50   ~ 0
AIR_1
Wire Wire Line
	2350 6800 2350 6900
$Comp
L power:GND #PWR0118
U 1 1 5C56F9CA
P 2800 7250
F 0 "#PWR0118" H 2800 7000 50  0001 C CNN
F 1 "GND" H 2805 7077 50  0000 C CNN
F 2 "" H 2800 7250 50  0001 C CNN
F 3 "" H 2800 7250 50  0001 C CNN
	1    2800 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 7250 2800 7200
Text Label 2500 6800 0    50   ~ 0
AIR_2
Wire Wire Line
	2800 6800 2800 6900
$Comp
L power:GND #PWR0120
U 1 1 5C575383
P 3250 7250
F 0 "#PWR0120" H 3250 7000 50  0001 C CNN
F 1 "GND" H 3255 7077 50  0000 C CNN
F 2 "" H 3250 7250 50  0001 C CNN
F 3 "" H 3250 7250 50  0001 C CNN
	1    3250 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 7250 3250 7200
Text Label 2950 6800 0    50   ~ 0
AIR_3
Wire Wire Line
	3250 6800 3250 6900
$Comp
L power:GND #PWR0122
U 1 1 5C57B691
P 3700 7250
F 0 "#PWR0122" H 3700 7000 50  0001 C CNN
F 1 "GND" H 3705 7077 50  0000 C CNN
F 2 "" H 3700 7250 50  0001 C CNN
F 3 "" H 3700 7250 50  0001 C CNN
	1    3700 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 7250 3700 7200
Text Label 3400 6800 0    50   ~ 0
AIR_4
Wire Wire Line
	3700 6800 3700 6900
$Comp
L power:GND #PWR0124
U 1 1 5C5820E4
P 4150 7250
F 0 "#PWR0124" H 4150 7000 50  0001 C CNN
F 1 "GND" H 4155 7077 50  0000 C CNN
F 2 "" H 4150 7250 50  0001 C CNN
F 3 "" H 4150 7250 50  0001 C CNN
	1    4150 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 7250 4150 7200
Text Label 3850 6800 0    50   ~ 0
AIR_5
Text Notes 3850 3850 0    50   ~ 0
 Connected to\n   off-board\nphototransistors
Text Notes 2400 5900 0    79   ~ 16
IR Sensors
$Comp
L Device:R R18
U 1 1 5C656A75
P 7350 4950
F 0 "R18" V 7250 4950 50  0000 C CNN
F 1 "33" V 7450 4950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7280 4950 50  0001 C CNN
F 3 "~" H 7350 4950 50  0001 C CNN
	1    7350 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 4600 7600 4600
Wire Wire Line
	7600 4600 7600 4850
Wire Wire Line
	7500 5300 7600 5300
Wire Wire Line
	7600 5300 7600 5050
Wire Wire Line
	7200 4600 6800 4600
Wire Wire Line
	7200 4950 6800 4950
Wire Wire Line
	7200 5300 6800 5300
Text Label 6800 4600 0    50   ~ 0
LED_0
Text Label 6800 4950 0    50   ~ 0
LED_1
Text Label 6800 5300 0    50   ~ 0
LED_2
$Comp
L Device:R R20
U 1 1 5C7370DB
P 2350 7050
F 0 "R20" H 2200 7100 50  0000 C CNN
F 1 "R_AIR" H 2200 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2280 7050 50  0001 C CNN
F 3 "~" H 2350 7050 50  0001 C CNN
	1    2350 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R24
U 1 1 5C737141
P 2800 7050
F 0 "R24" H 2650 7100 50  0000 C CNN
F 1 "R_AIR" H 2650 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2730 7050 50  0001 C CNN
F 3 "~" H 2800 7050 50  0001 C CNN
	1    2800 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R21
U 1 1 5C7371B3
P 3250 7050
F 0 "R21" H 3100 7100 50  0000 C CNN
F 1 "R_AIR" H 3100 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3180 7050 50  0001 C CNN
F 3 "~" H 3250 7050 50  0001 C CNN
	1    3250 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 5C737282
P 3700 7050
F 0 "R25" H 3550 7100 50  0000 C CNN
F 1 "R_AIR" H 3550 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3630 7050 50  0001 C CNN
F 3 "~" H 3700 7050 50  0001 C CNN
	1    3700 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R23
U 1 1 5C737302
P 4150 7050
F 0 "R23" H 4000 7100 50  0000 C CNN
F 1 "R_AIR" H 4000 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4080 7050 50  0001 C CNN
F 3 "~" H 4150 7050 50  0001 C CNN
	1    4150 7050
	1    0    0    -1  
$EndComp
Text Notes 7250 4350 0    79   ~ 16
IR LEDs
Wire Notes Line
	6450 2850 6450 650 
Wire Notes Line
	8700 4350 9000 4350
Wire Notes Line
	9000 4200 8700 4200
Wire Notes Line
	9000 4350 9000 4200
Wire Notes Line
	8700 4350 8700 4200
Text Notes 8650 4250 0    31   ~ 0
A
Text Notes 8650 4350 0    31   ~ 0
K
Wire Notes Line
	8700 4600 9000 4600
Wire Notes Line
	9000 4450 8700 4450
Wire Notes Line
	9000 4600 9000 4450
Wire Notes Line
	8700 4600 8700 4450
Text Notes 8650 4500 0    31   ~ 0
A
Text Notes 8650 4600 0    31   ~ 0
K
Wire Notes Line
	8700 4850 9000 4850
Wire Notes Line
	9000 4700 8700 4700
Wire Notes Line
	9000 4850 9000 4700
Wire Notes Line
	8700 4850 8700 4700
Text Notes 8650 4750 0    31   ~ 0
A
Text Notes 8650 4850 0    31   ~ 0
K
Wire Notes Line
	8700 5100 9000 5100
Wire Notes Line
	9000 4950 8700 4950
Wire Notes Line
	9000 5100 9000 4950
Wire Notes Line
	8700 5100 8700 4950
Text Notes 8650 5000 0    31   ~ 0
A
Text Notes 8650 5100 0    31   ~ 0
K
Wire Notes Line
	8700 5350 9000 5350
Wire Notes Line
	9000 5200 8700 5200
Wire Notes Line
	9000 5350 9000 5200
Wire Notes Line
	8700 5350 8700 5200
Text Notes 8650 5250 0    31   ~ 0
A
Text Notes 8650 5350 0    31   ~ 0
K
Wire Notes Line
	8700 5600 9000 5600
Wire Notes Line
	9000 5450 8700 5450
Text Notes 8700 5550 0    51   ~ 0
LED #1
Wire Notes Line
	9000 5600 9000 5450
Wire Notes Line
	8700 5600 8700 5450
Text Notes 8650 5500 0    31   ~ 0
A
Text Notes 8650 5600 0    31   ~ 0
K
Wire Notes Line
	8550 4300 8700 4300
Wire Notes Line
	8700 4500 8550 4500
Wire Notes Line
	8700 5300 8550 5300
Wire Notes Line
	8700 5500 8550 5500
Wire Notes Line rgb(194, 0, 0)
	8450 4800 8700 4800
Wire Notes Line rgb(194, 0, 0)
	8700 5550 8450 5550
Wire Notes Line rgb(194, 0, 0)
	8700 5250 8450 5250
Wire Notes Line rgb(0, 194, 0)
	8350 4250 8700 4250
Wire Notes Line rgb(0, 194, 0)
	8700 4550 8350 4550
Wire Notes Line rgb(0, 194, 0)
	8700 4750 8350 4750
Wire Wire Line
	8050 2050 8550 2050
Wire Wire Line
	8050 1850 8550 1850
Wire Wire Line
	8050 1650 8550 1650
Wire Wire Line
	8050 1450 8550 1450
Wire Wire Line
	10250 3350 10750 3350
Text Notes 7350 1050 0    50   ~ 0
74HC4051 module
Wire Notes Line
	6600 4100 9100 4100
Wire Notes Line
	8550 5500 8550 4300
Wire Notes Line rgb(194, 0, 0)
	8450 5550 8450 4800
Wire Notes Line rgb(0, 194, 0)
	8350 5050 8350 4250
Wire Notes Line rgb(194, 0, 0)
	8700 5000 8450 5000
Wire Notes Line
	6600 4100 6600 5900
Wire Notes Line
	6600 5900 9100 5900
Wire Notes Line
	9100 5900 9100 4100
Wire Notes Line
	8100 4850 8550 4850
Wire Notes Line rgb(194, 0, 0)
	8100 4950 8450 4950
Wire Notes Line rgb(0, 194, 0)
	8100 5050 8700 5050
Text Notes 8700 5300 0    51   ~ 0
LED #2
Text Notes 8700 5050 0    51   ~ 0
LED #3
Text Notes 8700 4800 0    51   ~ 0
LED #4
Text Notes 8700 4550 0    51   ~ 0
LED #5
Text Notes 8700 4300 0    51   ~ 0
LED #6
Wire Notes Line
	6600 650  11050 650 
Wire Notes Line
	11050 4000 6600 4000
Wire Notes Line
	6600 4000 6600 650 
Wire Notes Line
	5950 7600 650  7600
Wire Wire Line
	4150 6800 4150 6900
Wire Wire Line
	3850 6800 4150 6800
Wire Wire Line
	3400 6800 3700 6800
Wire Wire Line
	2950 6800 3250 6800
Wire Wire Line
	2500 6800 2800 6800
Wire Wire Line
	2050 6800 2350 6800
Wire Wire Line
	1600 6800 1900 6800
Wire Notes Line
	800  6150 1100 6150
Wire Notes Line
	1100 6000 800  6000
Wire Notes Line
	1100 6150 1100 6000
Wire Notes Line
	800  6150 800  6000
Wire Notes Line
	800  6400 1100 6400
Wire Notes Line
	1100 6250 800  6250
Wire Notes Line
	1100 6400 1100 6250
Wire Notes Line
	800  6400 800  6250
Wire Notes Line
	800  6650 1100 6650
Wire Notes Line
	1100 6500 800  6500
Wire Notes Line
	1100 6650 1100 6500
Wire Notes Line
	800  6650 800  6500
Wire Notes Line
	800  6900 1100 6900
Wire Notes Line
	1100 6750 800  6750
Wire Notes Line
	1100 6900 1100 6750
Wire Notes Line
	800  6900 800  6750
Wire Notes Line
	800  7150 1100 7150
Wire Notes Line
	1100 7000 800  7000
Wire Notes Line
	1100 7150 1100 7000
Wire Notes Line
	800  7150 800  7000
Wire Notes Line
	800  7400 1100 7400
Wire Notes Line
	1100 7250 800  7250
Wire Notes Line
	1100 7400 1100 7250
Wire Notes Line
	800  7400 800  7250
Text Notes 1150 6050 2    31   ~ 0
C
Text Notes 1150 6150 2    31   ~ 0
E
Text Notes 1150 6300 2    31   ~ 0
C
Text Notes 1150 6400 2    31   ~ 0
E
Text Notes 1150 6550 2    31   ~ 0
C
Text Notes 1150 6650 2    31   ~ 0
E
Text Notes 1150 6800 2    31   ~ 0
C
Text Notes 1150 6900 2    31   ~ 0
E
Text Notes 1150 7050 2    31   ~ 0
C
Text Notes 1150 7150 2    31   ~ 0
E
Text Notes 1150 7300 2    31   ~ 0
C
Text Notes 1150 7400 2    31   ~ 0
E
Wire Notes Line rgb(194, 0, 0)
	1100 7300 1250 7300
Wire Notes Line rgb(194, 0, 0)
	1250 7300 1250 6050
Wire Notes Line rgb(194, 0, 0)
	1100 7050 1250 7050
Wire Notes Line rgb(194, 0, 0)
	1100 6800 1250 6800
Wire Notes Line rgb(194, 0, 0)
	1100 6550 1250 6550
Wire Notes Line rgb(194, 0, 0)
	1100 6300 1250 6300
Wire Notes Line
	1100 7350 1500 7350
Wire Notes Line
	1500 6350 1900 6350
Wire Notes Line
	1100 7100 1450 7100
Wire Notes Line
	1450 6300 2350 6300
Wire Notes Line
	1100 6850 1400 6850
Wire Notes Line
	1400 6250 2800 6250
Wire Notes Line
	1100 6600 1350 6600
Wire Notes Line
	1350 6200 3250 6200
Wire Notes Line
	1100 6350 1300 6350
Wire Notes Line
	1300 6150 3700 6150
Wire Notes Line
	1100 6100 4150 6100
Wire Notes Line rgb(194, 0, 0)
	1100 6050 4600 6050
Wire Notes Line
	1500 7350 1500 6350
Wire Notes Line
	1450 7100 1450 6300
Wire Notes Line
	1400 6850 1400 6250
Wire Notes Line
	1350 6600 1350 6200
Wire Notes Line
	1300 6350 1300 6150
Wire Notes Line
	5950 7600 5950 5650
Wire Notes Line
	6450 2850 650  2850
Wire Notes Line
	650  5650 650  7600
Text Notes 850  6150 0    28   ~ 0
  IR\nSensor\n  #6
Wire Notes Line
	650  650  6450 650 
$Comp
L Connector_Generic:Conn_01x14 J1
U 1 1 5CF04ACE
P 2350 1950
F 0 "J1" H 2300 2700 50  0000 L CNN
F 1 "Conn_01x14" H 2430 1851 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x14_P2.54mm_Vertical" H 2350 1950 50  0001 C CNN
F 3 "~" H 2350 1950 50  0001 C CNN
	1    2350 1950
	1    0    0    -1  
$EndComp
Text Notes 2450 1400 0    59   ~ 0
GND
Text Notes 2450 1500 0    59   ~ 0
0
Text Notes 2450 1600 0    59   ~ 0
1
Text Notes 2450 1700 0    59   ~ 0
2
Text Notes 2450 1800 0    59   ~ 0
3
Text Notes 2450 1900 0    59   ~ 0
4
Text Notes 2450 2000 0    59   ~ 0
5
Text Notes 2450 2100 0    59   ~ 0
6
Text Notes 2450 2200 0    59   ~ 0
7
Text Notes 2450 2300 0    59   ~ 0
8
Text Notes 2450 2400 0    59   ~ 0
9
Text Notes 2450 2500 0    59   ~ 0
10
Text Notes 2450 2600 0    59   ~ 0
11
Text Notes 2450 2700 0    59   ~ 0
12
Text Notes 4400 1400 0    59   ~ 0
VIN
Text Notes 4400 1500 0    59   ~ 0
GND
Text Notes 4400 1600 0    59   ~ 0
3V3
Text Notes 4400 1700 0    59   ~ 0
23
Text Notes 4400 1800 0    59   ~ 0
22
Text Notes 4400 1900 0    59   ~ 0
21
Text Notes 4400 2000 0    59   ~ 0
20
Text Notes 4400 2100 0    59   ~ 0
19
Text Notes 4400 2200 0    59   ~ 0
18
Text Notes 4400 2300 0    59   ~ 0
17
Text Notes 4400 2400 0    59   ~ 0
16
Text Notes 4400 2500 0    59   ~ 0
15
Text Notes 4400 2600 0    59   ~ 0
14
$Comp
L power:+5V #PWR0103
U 1 1 5D108EF7
P 3950 1250
F 0 "#PWR0103" H 3950 1100 50  0001 C CNN
F 1 "+5V" H 3965 1423 50  0000 C CNN
F 2 "" H 3950 1250 50  0001 C CNN
F 3 "" H 3950 1250 50  0001 C CNN
	1    3950 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 1250 3950 1350
Wire Wire Line
	4100 1350 3950 1350
$Comp
L power:+3.3V #PWR0107
U 1 1 5D159C8C
P 3700 1250
F 0 "#PWR0107" H 3700 1100 50  0001 C CNN
F 1 "+3.3V" H 3715 1423 50  0000 C CNN
F 2 "" H 3700 1250 50  0001 C CNN
F 3 "" H 3700 1250 50  0001 C CNN
	1    3700 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1550 3700 1550
Wire Wire Line
	3700 1550 3700 1250
Text Label 3450 2350 0    50   ~ 0
TOUCH_0
Wire Wire Line
	3450 2350 4100 2350
Text Label 1050 4400 0    50   ~ 0
KEY_8
Text Label 1050 4500 0    50   ~ 0
KEY_9
Text Label 1050 4600 0    50   ~ 0
KEY_10
Text Label 1050 4700 0    50   ~ 0
KEY_11
Text Label 1050 4800 0    50   ~ 0
KEY_12
Text Label 1050 4900 0    50   ~ 0
KEY_13
Text Label 1050 5000 0    50   ~ 0
KEY_14
Text Label 1050 5100 0    50   ~ 0
KEY_15
Text Label 1150 4000 2    50   ~ 0
LED_0_OUT
Text Label 1150 4100 2    50   ~ 0
LED_1_OUT
Text Label 1150 4200 2    50   ~ 0
LED_2_OUT
Wire Wire Line
	3300 3900 3300 3850
Wire Wire Line
	3300 4100 3300 4150
Text Label 3400 4000 2    50   ~ 0
RGB_DO_BUF
$Comp
L power:GND #PWR0112
U 1 1 5D492DBE
P 3300 4150
F 0 "#PWR0112" H 3300 3900 50  0001 C CNN
F 1 "GND" H 3305 3977 50  0000 C CNN
F 2 "" H 3300 4150 50  0001 C CNN
F 3 "" H 3300 4150 50  0001 C CNN
	1    3300 4150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5400 4000 6200 4000
Wire Wire Line
	5500 4200 6200 4200
Wire Wire Line
	5450 4100 6200 4100
Text Label 4050 4000 2    50   ~ 0
AIR_0
Text Label 4050 4100 2    50   ~ 0
AIR_1
Text Label 4050 4200 2    50   ~ 0
AIR_2
Text Label 5950 4000 0    50   ~ 0
AIR_3
Text Label 5950 4100 0    50   ~ 0
AIR_4
Text Label 5950 4200 0    50   ~ 0
AIR_5
$Comp
L power:+3.3V #PWR0113
U 1 1 5D5F2DAE
P 4650 3850
F 0 "#PWR0113" H 4650 3700 50  0001 C CNN
F 1 "+3.3V" H 4665 4023 50  0000 C CNN
F 2 "" H 4650 3850 50  0001 C CNN
F 3 "" H 4650 3850 50  0001 C CNN
	1    4650 3850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2150 2150 1500 2150
Text Label 1500 2150 0    50   ~ 0
LED_1
Text Label 1500 1850 0    50   ~ 0
MUX_2
Wire Wire Line
	2150 1750 1500 1750
Wire Wire Line
	1500 1850 2150 1850
Text Notes 4400 2700 0    59   ~ 0
13
Wire Wire Line
	3450 2150 4100 2150
Wire Wire Line
	3450 1950 4100 1950
Wire Wire Line
	3450 2050 4100 2050
Wire Wire Line
	3450 1650 4100 1650
Wire Wire Line
	3450 1750 4100 1750
Wire Wire Line
	3450 1850 4100 1850
Text Label 3450 2150 0    50   ~ 0
AIR_0
Text Label 3450 1950 0    50   ~ 0
AIR_1
Text Label 3450 1750 0    50   ~ 0
AIR_2
Text Label 3450 2050 0    50   ~ 0
AIR_3
Text Label 3450 1850 0    50   ~ 0
AIR_4
Text Label 3450 1650 0    50   ~ 0
AIR_5
$Comp
L power:GND #PWR0115
U 1 1 5DB1769B
P 3550 1400
F 0 "#PWR0115" H 3550 1150 50  0001 C CNN
F 1 "GND" H 3450 1400 50  0000 C CNN
F 2 "" H 3550 1400 50  0001 C CNN
F 3 "" H 3550 1400 50  0001 C CNN
	1    3550 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1350 3550 1350
Wire Wire Line
	3550 1400 3550 1350
Wire Wire Line
	4100 1450 3850 1450
Wire Wire Line
	3850 1450 3850 1350
$Comp
L power:GND #PWR0117
U 1 1 5DB75E51
P 1600 1250
F 0 "#PWR0117" H 1600 1000 50  0001 C CNN
F 1 "GND" H 1500 1250 50  0000 C CNN
F 2 "" H 1600 1250 50  0001 C CNN
F 3 "" H 1600 1250 50  0001 C CNN
	1    1600 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1200 1600 1200
Wire Wire Line
	1600 1250 1600 1200
Wire Wire Line
	2150 1350 1900 1350
Wire Wire Line
	1900 1350 1900 1200
$Comp
L Connector_Generic:Conn_01x14 J2
U 1 1 5CF048BA
P 4300 1950
F 0 "J2" H 4250 2700 50  0000 L CNN
F 1 "Conn_01x14" H 4380 1851 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x14_P2.54mm_Vertical" H 4300 1950 50  0001 C CNN
F 3 "~" H 4300 1950 50  0001 C CNN
	1    4300 1950
	1    0    0    -1  
$EndComp
Text Label 3450 2250 0    50   ~ 0
RGB_DO
Wire Wire Line
	3450 2250 4100 2250
Wire Notes Line
	3250 6200 3250 6800
Wire Notes Line
	4150 6100 4150 6800
Wire Notes Line
	3700 6150 3700 6800
Wire Notes Line
	2800 6250 2800 6800
Wire Notes Line
	2350 6300 2350 6800
Wire Notes Line
	1900 6350 1900 6800
Wire Notes Line
	1500 1400 1250 1400
Text Notes 1300 1300 2    39   ~ 0
Capacitive touch
Text Label 7700 4850 0    50   ~ 0
LED_0_OUT
Text Label 7700 4950 0    50   ~ 0
LED_1_OUT
Text Label 7700 5050 0    50   ~ 0
LED_2_OUT
Wire Wire Line
	7600 4850 8100 4850
Wire Wire Line
	7500 4950 8100 4950
Wire Wire Line
	7600 5050 8100 5050
$Comp
L Connector_Generic:Conn_01x05 J9
U 1 1 5E11B7BB
P 6000 1600
F 0 "J9" H 5950 1950 50  0000 L CNN
F 1 "Conn_01x05" H 6080 1551 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 6000 1600 50  0001 C CNN
F 3 "~" H 6000 1600 50  0001 C CNN
	1    6000 1600
	1    0    0    -1  
$EndComp
Text Notes 6100 1450 0    59   ~ 0
17
Text Notes 6100 1550 0    59   ~ 0
3V3
Text Notes 6100 1650 0    59   ~ 0
GND
Text Notes 6100 1750 0    59   ~ 0
PROG
Text Notes 6100 1850 0    59   ~ 0
26
Text Label 5150 1400 0    50   ~ 0
RGB_DO_BUF
Wire Wire Line
	5150 1400 5800 1400
Wire Wire Line
	2150 1450 1500 1450
Text Label 1500 1450 0    50   ~ 0
TOUCH_1
Wire Notes Line rgb(181, 36, 0)
	1500 2000 1000 2000
Wire Notes Line rgb(181, 36, 0)
	1000 1950 1000 2000
Text Notes 800  1950 0    39   ~ 0
IR LEDs
Wire Notes Line rgb(181, 36, 0)
	1500 2200 1350 2200
Wire Notes Line rgb(181, 36, 0)
	1350 2200 1350 2000
Wire Notes Line rgb(99, 255, 8)
	5000 1350 5000 1300
Text Notes 4700 1300 0    39   ~ 0
RGB lighting
Wire Notes Line rgb(99, 255, 8)
	5000 1350 5150 1350
Wire Notes Line
	5950 5650 650  5650
Text Notes 4050 3200 0    79   ~ 16
External Pin Headers
Wire Notes Line
	650  650  650  2850
Wire Notes Line
	6450 5500 650  5500
Wire Notes Line
	650  2950 650  5500
Wire Notes Line
	6450 2950 650  2950
Wire Notes Line
	6450 2950 6450 5500
Wire Notes Line
	1200 3900 700  3900
Text Notes 750  3700 0    50   ~ 0
Connected to off-board \nIR LEDs
Wire Notes Line
	950  3700 950  3900
Wire Notes Line
	2900 4400 3450 4400
Wire Notes Line
	2900 4400 2900 3600
Wire Notes Line
	3450 4400 3450 3600
Wire Notes Line
	2900 3600 3450 3600
Text Notes 2250 3750 0    50   ~ 0
Connected to\nRGB Strip
Wire Notes Line
	2650 3700 2900 3700
Text Notes 6800 5800 0    50   ~ 0
A - Anode (Long Pin)\nK - Cathode (Short Pin, Flat Side)
Text Notes 4600 6100 0    50   ~ 0
To +3.3V
Text Notes 4500 7450 0    50   ~ 0
If using Phototransistor:\nC - Collector\nE - Emitter\n\nIf using Photodiode:\nC - Cathode (Short Pin, Flat Side)\nE - Anode (Long Pin)
Text Notes 850  6400 0    28   ~ 0
  IR\nSensor\n  #5
Text Notes 850  6650 0    28   ~ 0
  IR\nSensor\n  #4
Text Notes 850  6900 0    28   ~ 0
  IR\nSensor\n  #3
Text Notes 850  7150 0    28   ~ 0
  IR\nSensor\n  #2
Text Notes 850  7400 0    28   ~ 0
  IR\nSensor\n  #1
Text Notes 3150 1700 2    39   ~ 0
Light sensors
Wire Notes Line rgb(255, 0, 255)
	3100 1850 3100 1700
Wire Notes Line rgb(255, 0, 255)
	3300 1850 3100 1850
Wire Notes Line rgb(255, 0, 255)
	3450 1700 3300 1700
Wire Notes Line rgb(255, 0, 255)
	3450 1800 3300 1800
Wire Notes Line rgb(255, 0, 255)
	3450 1900 3300 1900
Wire Notes Line rgb(255, 0, 255)
	3300 2100 3450 2100
Wire Notes Line rgb(255, 0, 255)
	3450 1600 3300 1600
Wire Notes Line rgb(255, 0, 255)
	3300 1600 3300 2100
Wire Notes Line rgb(255, 0, 255)
	3450 2000 3300 2000
Wire Notes Line rgb(181, 36, 0)
	1500 2100 1350 2100
Wire Notes Line rgb(255, 153, 9)
	1500 1600 1000 1600
Wire Notes Line rgb(255, 153, 90)
	1000 1550 1000 1600
Text Notes 800  1550 0    39   ~ 0
IR LEDs
Wire Notes Line rgb(255, 153, 9)
	1500 1800 1350 1800
Wire Notes Line rgb(255, 153, 9)
	1350 1800 1350 1600
Wire Notes Line rgb(255, 153, 9)
	1500 1700 1350 1700
Wire Wire Line
	1500 1650 2150 1650
Text Label 1500 1750 0    50   ~ 0
MUX_1
Text Label 1500 1650 0    50   ~ 0
MUX_0
Text Notes 3250 2250 2    39   ~ 0
Capacitive touch
$Comp
L power:GND #PWR0104
U 1 1 5E9D5F1A
P 5650 3750
F 0 "#PWR0104" H 5650 3500 50  0001 C CNN
F 1 "GND" H 5655 3577 50  0000 C CNN
F 2 "" H 5650 3750 50  0001 C CNN
F 3 "" H 5650 3750 50  0001 C CNN
	1    5650 3750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5650 3700 5650 3750
Wire Notes Line
	1250 1300 1250 1500
Text Label 8450 3550 2    50   ~ 0
KEY_24
Text Label 8450 3350 2    50   ~ 0
KEY_25
Text Label 8450 3150 2    50   ~ 0
KEY_26
Text Label 8450 2950 2    50   ~ 0
KEY_27
Text Label 10650 2050 2    50   ~ 0
KEY_28
Text Label 10650 1850 2    50   ~ 0
KEY_29
Text Label 10650 1650 2    50   ~ 0
KEY_30
Text Label 10650 1450 2    50   ~ 0
KEY_31
Text Label 8450 3650 2    50   ~ 0
KEY_16
Text Label 8450 3450 2    50   ~ 0
KEY_17
Text Label 8450 3250 2    50   ~ 0
KEY_18
Text Label 8450 3050 2    50   ~ 0
KEY_19
Text Label 10650 2150 2    50   ~ 0
KEY_20
Text Label 10650 1950 2    50   ~ 0
KEY_21
Text Label 10650 1750 2    50   ~ 0
KEY_22
Wire Wire Line
	8050 3650 8550 3650
Wire Wire Line
	8050 3450 8550 3450
Wire Wire Line
	8050 3250 8550 3250
Wire Wire Line
	8050 3050 8550 3050
Wire Wire Line
	10250 2150 10750 2150
Wire Wire Line
	10250 1950 10750 1950
Wire Wire Line
	10250 1750 10750 1750
Wire Wire Line
	8050 3550 8550 3550
Wire Wire Line
	8050 3350 8550 3350
Wire Wire Line
	8050 3150 8550 3150
Wire Wire Line
	8050 2950 8550 2950
Wire Wire Line
	10250 2050 10750 2050
Wire Wire Line
	10250 1850 10750 1850
Wire Wire Line
	10250 1650 10750 1650
Wire Wire Line
	10250 1450 10750 1450
Wire Wire Line
	2150 1550 1500 1550
Text Label 1500 1550 0    50   ~ 0
TOUCH_2
Text Label 3450 2450 0    50   ~ 0
TOUCH_3
Wire Wire Line
	3450 2450 4100 2450
Wire Notes Line
	1500 1500 1250 1500
Wire Notes Line
	3200 2250 3200 2400
Wire Notes Line
	3450 2400 3200 2400
Wire Notes Line
	3450 2300 3200 2300
Wire Notes Line rgb(90, 238, 7)
	3300 2200 3450 2200
Wire Notes Line rgb(90, 238, 7)
	3050 2150 3050 2100
Wire Notes Line rgb(90, 238, 7)
	3050 2150 3300 2150
$Comp
L power:GND #PWR0101
U 1 1 5F3571E9
P 7000 2200
F 0 "#PWR0101" H 7000 1950 50  0001 C CNN
F 1 "GND" H 7100 2200 50  0000 C CNN
F 2 "" H 7000 2200 50  0001 C CNN
F 3 "" H 7000 2200 50  0001 C CNN
	1    7000 2200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7300 2300 7200 2300
Wire Wire Line
	7300 2200 7200 2200
Wire Wire Line
	7200 2200 7200 2300
$Comp
L 74HC4051:74HC4051 U1
U 1 1 5F3AC78D
P 7700 1800
F 0 "U1" H 7675 2473 50  0000 C CNN
F 1 "74HC4051" H 7675 2474 50  0001 C CNN
F 2 "74HC4051:74HC4051_Sparkfun_Aliexpress" H 6700 2650 50  0001 C CNN
F 3 "" H 6700 2650 50  0001 C CNN
	1    7700 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2100 7200 2100
Wire Wire Line
	7200 2100 7200 2200
Connection ~ 7200 2200
Wire Wire Line
	7300 2000 7200 2000
Wire Wire Line
	7200 2000 7200 2100
Connection ~ 7200 2100
Wire Wire Line
	7300 1900 7200 1900
Wire Wire Line
	7200 1900 7200 2000
Connection ~ 7200 2000
$Comp
L power:+3.3V #PWR0102
U 1 1 5F3EE8E4
P 7100 1300
F 0 "#PWR0102" H 7100 1150 50  0001 C CNN
F 1 "+3.3V" H 7115 1473 50  0000 C CNN
F 2 "" H 7100 1300 50  0001 C CNN
F 3 "" H 7100 1300 50  0001 C CNN
	1    7100 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1300 7200 1300
Wire Wire Line
	7200 1300 7100 1300
Wire Wire Line
	7300 1400 7200 1400
Wire Wire Line
	7200 1400 7200 1300
Connection ~ 7200 1300
Text Label 6750 1600 0    50   ~ 0
MUX_0
Text Label 6750 1700 0    50   ~ 0
MUX_1
Text Label 6750 1800 0    50   ~ 0
MUX_2
Text Label 6750 1500 0    50   ~ 0
TOUCH_0
Wire Wire Line
	6750 1500 7300 1500
Wire Wire Line
	6750 1600 7300 1600
Wire Wire Line
	6750 1700 7300 1700
Wire Wire Line
	6750 1800 7300 1800
Wire Wire Line
	10250 3550 10750 3550
Wire Wire Line
	7000 2200 7000 2100
Wire Wire Line
	7000 2100 7200 2100
Text Notes 9550 1050 0    50   ~ 0
74HC4051 module
$Comp
L power:GND #PWR0105
U 1 1 5F74916F
P 9200 2200
F 0 "#PWR0105" H 9200 1950 50  0001 C CNN
F 1 "GND" H 9300 2200 50  0000 C CNN
F 2 "" H 9200 2200 50  0001 C CNN
F 3 "" H 9200 2200 50  0001 C CNN
	1    9200 2200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9500 2300 9400 2300
Wire Wire Line
	9500 2200 9400 2200
Wire Wire Line
	9400 2200 9400 2300
$Comp
L 74HC4051:74HC4051 U2
U 1 1 5F749178
P 9900 1800
F 0 "U2" H 9875 2473 50  0000 C CNN
F 1 "74HC4051" H 9875 2474 50  0001 C CNN
F 2 "74HC4051:74HC4051_Sparkfun_Aliexpress" H 8900 2650 50  0001 C CNN
F 3 "" H 8900 2650 50  0001 C CNN
	1    9900 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2100 9400 2100
Wire Wire Line
	9400 2100 9400 2200
Connection ~ 9400 2200
Wire Wire Line
	9500 2000 9400 2000
Wire Wire Line
	9400 2000 9400 2100
Connection ~ 9400 2100
Wire Wire Line
	9500 1900 9400 1900
Wire Wire Line
	9400 1900 9400 2000
Connection ~ 9400 2000
$Comp
L power:+3.3V #PWR0106
U 1 1 5F749187
P 9300 1300
F 0 "#PWR0106" H 9300 1150 50  0001 C CNN
F 1 "+3.3V" H 9315 1473 50  0000 C CNN
F 2 "" H 9300 1300 50  0001 C CNN
F 3 "" H 9300 1300 50  0001 C CNN
	1    9300 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 1300 9400 1300
Wire Wire Line
	9400 1300 9300 1300
Wire Wire Line
	9500 1400 9400 1400
Wire Wire Line
	9400 1400 9400 1300
Connection ~ 9400 1300
Text Label 8950 1600 0    50   ~ 0
MUX_0
Text Label 8950 1700 0    50   ~ 0
MUX_1
Text Label 8950 1800 0    50   ~ 0
MUX_2
Text Label 8950 1500 0    50   ~ 0
TOUCH_1
Wire Wire Line
	8950 1500 9500 1500
Wire Wire Line
	8950 1600 9500 1600
Wire Wire Line
	8950 1700 9500 1700
Wire Wire Line
	8950 1800 9500 1800
Wire Wire Line
	9200 2200 9200 2100
Wire Wire Line
	9200 2100 9400 2100
Text Notes 7350 2550 0    50   ~ 0
74HC4051 module
$Comp
L power:GND #PWR0108
U 1 1 5F77C0CF
P 7000 3700
F 0 "#PWR0108" H 7000 3450 50  0001 C CNN
F 1 "GND" H 7100 3700 50  0000 C CNN
F 2 "" H 7000 3700 50  0001 C CNN
F 3 "" H 7000 3700 50  0001 C CNN
	1    7000 3700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7300 3800 7200 3800
Wire Wire Line
	7300 3700 7200 3700
Wire Wire Line
	7200 3700 7200 3800
$Comp
L 74HC4051:74HC4051 U3
U 1 1 5F77C0D8
P 7700 3300
F 0 "U3" H 7675 3973 50  0000 C CNN
F 1 "74HC4051" H 7675 3974 50  0001 C CNN
F 2 "74HC4051:74HC4051_Sparkfun_Aliexpress" H 6700 4150 50  0001 C CNN
F 3 "" H 6700 4150 50  0001 C CNN
	1    7700 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3600 7200 3600
Wire Wire Line
	7200 3600 7200 3700
Connection ~ 7200 3700
Wire Wire Line
	7300 3500 7200 3500
Wire Wire Line
	7200 3500 7200 3600
Connection ~ 7200 3600
Wire Wire Line
	7300 3400 7200 3400
Wire Wire Line
	7200 3400 7200 3500
Connection ~ 7200 3500
$Comp
L power:+3.3V #PWR0109
U 1 1 5F77C0E7
P 7100 2800
F 0 "#PWR0109" H 7100 2650 50  0001 C CNN
F 1 "+3.3V" H 7115 2973 50  0000 C CNN
F 2 "" H 7100 2800 50  0001 C CNN
F 3 "" H 7100 2800 50  0001 C CNN
	1    7100 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2800 7200 2800
Wire Wire Line
	7200 2800 7100 2800
Wire Wire Line
	7300 2900 7200 2900
Wire Wire Line
	7200 2900 7200 2800
Connection ~ 7200 2800
Text Label 6750 3100 0    50   ~ 0
MUX_0
Text Label 6750 3200 0    50   ~ 0
MUX_1
Text Label 6750 3300 0    50   ~ 0
MUX_2
Text Label 6750 3000 0    50   ~ 0
TOUCH_2
Wire Wire Line
	6750 3000 7300 3000
Wire Wire Line
	6750 3100 7300 3100
Wire Wire Line
	6750 3200 7300 3200
Wire Wire Line
	6750 3300 7300 3300
Wire Wire Line
	7000 3700 7000 3600
Wire Wire Line
	7000 3600 7200 3600
Text Notes 9550 2550 0    50   ~ 0
74HC4051 module
$Comp
L power:GND #PWR0110
U 1 1 5F79AB81
P 9200 3700
F 0 "#PWR0110" H 9200 3450 50  0001 C CNN
F 1 "GND" H 9300 3700 50  0000 C CNN
F 2 "" H 9200 3700 50  0001 C CNN
F 3 "" H 9200 3700 50  0001 C CNN
	1    9200 3700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9500 3800 9400 3800
Wire Wire Line
	9500 3700 9400 3700
Wire Wire Line
	9400 3700 9400 3800
$Comp
L 74HC4051:74HC4051 U4
U 1 1 5F79AB8A
P 9900 3300
F 0 "U4" H 9875 3973 50  0000 C CNN
F 1 "74HC4051" H 9875 3974 50  0001 C CNN
F 2 "74HC4051:74HC4051_Sparkfun_Aliexpress" H 8900 4150 50  0001 C CNN
F 3 "" H 8900 4150 50  0001 C CNN
	1    9900 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 3600 9400 3600
Wire Wire Line
	9400 3600 9400 3700
Connection ~ 9400 3700
Wire Wire Line
	9500 3500 9400 3500
Wire Wire Line
	9400 3500 9400 3600
Connection ~ 9400 3600
Wire Wire Line
	9500 3400 9400 3400
Wire Wire Line
	9400 3400 9400 3500
Connection ~ 9400 3500
$Comp
L power:+3.3V #PWR0119
U 1 1 5F79AB99
P 9300 2800
F 0 "#PWR0119" H 9300 2650 50  0001 C CNN
F 1 "+3.3V" H 9315 2973 50  0000 C CNN
F 2 "" H 9300 2800 50  0001 C CNN
F 3 "" H 9300 2800 50  0001 C CNN
	1    9300 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2800 9400 2800
Wire Wire Line
	9400 2800 9300 2800
Wire Wire Line
	9500 2900 9400 2900
Wire Wire Line
	9400 2900 9400 2800
Connection ~ 9400 2800
Text Label 8950 3100 0    50   ~ 0
MUX_0
Text Label 8950 3200 0    50   ~ 0
MUX_1
Text Label 8950 3300 0    50   ~ 0
MUX_2
Text Label 8950 3000 0    50   ~ 0
TOUCH_3
Wire Wire Line
	8950 3000 9500 3000
Wire Wire Line
	8950 3100 9500 3100
Wire Wire Line
	8950 3200 9500 3200
Wire Wire Line
	8950 3300 9500 3300
Wire Wire Line
	9200 3700 9200 3600
Wire Wire Line
	9200 3600 9400 3600
$Comp
L Connector_Generic:Conn_02x12_Odd_Even J7
U 1 1 5F3152FE
P 1750 4500
F 0 "J7" H 1800 5125 50  0000 C CNN
F 1 "Conn_02x12_Odd_Even" H 1800 5126 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x12_P2.54mm_Horizontal" H 1750 4500 50  0001 C CNN
F 3 "~" H 1750 4500 50  0001 C CNN
	1    1750 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x12_Odd_Even J8
U 1 1 5FD12E81
P 4950 4500
F 0 "J8" H 5000 5125 50  0000 C CNN
F 1 "Conn_02x12_Odd_Even" H 5000 5126 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x12_P2.54mm_Horizontal" H 4950 4500 50  0001 C CNN
F 3 "~" H 4950 4500 50  0001 C CNN
	1    4950 4500
	1    0    0    -1  
$EndComp
Wire Notes Line
	700  4250 700  3900
Wire Notes Line
	1200 4250 1200 3900
Wire Notes Line
	1200 4250 700  4250
Text Label 2650 4400 2    50   ~ 0
KEY_0
Text Label 2650 4500 2    50   ~ 0
KEY_1
Text Label 2650 4600 2    50   ~ 0
KEY_2
Text Label 2650 4700 2    50   ~ 0
KEY_3
Text Label 2650 4800 2    50   ~ 0
KEY_4
Text Label 2650 4900 2    50   ~ 0
KEY_5
Text Label 2650 5000 2    50   ~ 0
KEY_6
Text Label 2650 5100 2    50   ~ 0
KEY_7
Wire Notes Line
	1000 5150 1000 4300
Wire Notes Line
	1000 5150 1350 5150
Text Notes 950  5400 0    50   ~ 0
Connected to\nCopper Pads
Wire Notes Line
	950  5300 900  5300
Wire Notes Line
	900  5300 900  4700
Wire Notes Line
	900  4700 1000 4700
Wire Notes Line
	1000 4300 1350 4300
Wire Notes Line
	1350 5150 1350 4300
Wire Wire Line
	6000 4400 5250 4400
Wire Wire Line
	6000 4500 5250 4500
Wire Wire Line
	6000 4600 5250 4600
Wire Wire Line
	6000 4700 5250 4700
Wire Wire Line
	6000 4800 5250 4800
Wire Wire Line
	6000 4900 5250 4900
Wire Wire Line
	6000 5000 5250 5000
Wire Wire Line
	6000 5100 5250 5100
Text Label 6000 4400 2    50   ~ 0
KEY_24
Text Label 6000 4500 2    50   ~ 0
KEY_25
Text Label 6000 4600 2    50   ~ 0
KEY_26
Text Label 6000 4700 2    50   ~ 0
KEY_27
Text Label 6000 4800 2    50   ~ 0
KEY_28
Text Label 6000 4900 2    50   ~ 0
KEY_29
Text Label 6000 5000 2    50   ~ 0
KEY_30
Text Label 6000 5100 2    50   ~ 0
KEY_31
Text Label 4000 4400 0    50   ~ 0
KEY_16
Text Label 4000 4500 0    50   ~ 0
KEY_17
Text Label 4000 4600 0    50   ~ 0
KEY_18
Text Label 4000 4700 0    50   ~ 0
KEY_19
Text Label 4000 4800 0    50   ~ 0
KEY_20
Text Label 4000 4900 0    50   ~ 0
KEY_21
Text Label 4000 5000 0    50   ~ 0
KEY_22
Text Label 4000 5100 0    50   ~ 0
KEY_23
Wire Notes Line
	3950 5150 3950 4300
Wire Notes Line
	3950 5150 4350 5150
Wire Wire Line
	4000 4800 4750 4800
Wire Wire Line
	4000 4700 4750 4700
Wire Wire Line
	4000 4600 4750 4600
Wire Wire Line
	4000 4500 4750 4500
Wire Wire Line
	4000 5100 4750 5100
Wire Wire Line
	4000 5000 4750 5000
Wire Wire Line
	4000 4900 4750 4900
Wire Wire Line
	4000 4400 4750 4400
Text Notes 3900 5400 0    50   ~ 0
Connected to\nCopper Pads
Wire Notes Line
	3900 5300 3850 5300
Wire Notes Line
	3850 5300 3850 4700
Wire Notes Line
	3850 4700 3950 4700
Wire Notes Line
	3950 4300 4350 4300
Wire Notes Line
	4350 5150 4350 4300
Wire Notes Line
	6050 5150 6050 4300
Wire Notes Line
	6050 5150 5650 5150
Text Notes 6100 5400 2    50   ~ 0
Connected to\nCopper Pads
Wire Notes Line
	6100 5300 6150 5300
Wire Notes Line
	6150 5300 6150 4700
Wire Notes Line
	6150 4700 6050 4700
Wire Notes Line
	6050 4300 5650 4300
Wire Notes Line
	5650 5150 5650 4300
Wire Wire Line
	4750 4000 4650 4000
Wire Wire Line
	4750 4300 4500 4300
Wire Wire Line
	4500 4300 4500 4200
Wire Wire Line
	3800 4200 4500 4200
Wire Wire Line
	4750 4100 4600 4100
Wire Wire Line
	4600 4100 4600 4000
Wire Wire Line
	4600 4000 3800 4000
Wire Wire Line
	4750 4200 4550 4200
Wire Wire Line
	4550 4200 4550 4100
Wire Wire Line
	3800 4100 4550 4100
Wire Wire Line
	5450 4200 5450 4100
Wire Wire Line
	5250 4200 5450 4200
Wire Wire Line
	5400 4100 5400 4000
Wire Wire Line
	5250 4100 5400 4100
Wire Wire Line
	5500 4300 5500 4200
Wire Wire Line
	5250 4300 5500 4300
Wire Wire Line
	5250 4000 5350 4000
Wire Wire Line
	5350 4000 5350 3700
Wire Wire Line
	5350 3700 5650 3700
Wire Notes Line
	2750 5150 2750 4300
Wire Notes Line
	2750 5150 2350 5150
Text Notes 2800 5400 2    50   ~ 0
Connected to\nCopper Pads
Wire Notes Line
	2800 5300 2850 5300
Wire Notes Line
	2850 5300 2850 4700
Wire Notes Line
	2750 4300 2350 4300
Wire Notes Line
	2350 5150 2350 4300
Wire Wire Line
	2300 4300 2300 4200
Wire Wire Line
	2300 4100 3300 4100
Wire Notes Line
	2850 4700 2750 4700
Wire Wire Line
	2200 4100 2200 4000
Wire Wire Line
	2200 4000 3400 4000
Wire Wire Line
	2150 4000 2150 3900
Wire Wire Line
	2150 3900 3300 3900
Wire Wire Line
	2150 4000 2050 4000
Wire Wire Line
	2050 4100 2200 4100
Wire Wire Line
	2050 4300 2300 4300
Wire Wire Line
	4650 3850 4650 4000
Wire Notes Line
	3750 3900 3750 4250
Wire Notes Line
	3750 4250 4100 4250
Wire Notes Line
	4100 4250 4100 3900
Wire Notes Line
	4100 3900 3750 3900
Wire Notes Line
	3800 3900 3800 3750
Wire Notes Line
	3800 3750 3950 3750
Wire Notes Line
	5900 3900 5900 4250
Wire Notes Line
	5900 4250 6250 4250
Wire Notes Line
	6250 4250 6250 3900
Wire Notes Line
	6250 3900 5900 3900
Text Notes 5800 3800 0    50   ~ 0
 Connected to\n   off-board\nphototransistors
Wire Notes Line
	6100 3900 6100 3800
Wire Wire Line
	1550 4400 1050 4400
Wire Wire Line
	1550 4500 1050 4500
Wire Wire Line
	1550 4600 1050 4600
Wire Wire Line
	1550 4700 1050 4700
Wire Wire Line
	1550 4800 1050 4800
Wire Wire Line
	1550 4900 1050 4900
Wire Wire Line
	1550 5000 1050 5000
Wire Wire Line
	1550 5100 1050 5100
Wire Wire Line
	2050 4400 2650 4400
Wire Wire Line
	2050 4500 2650 4500
Wire Wire Line
	2050 4600 2650 4600
Wire Wire Line
	2050 4700 2650 4700
Wire Wire Line
	2050 4800 2650 4800
Wire Wire Line
	2050 4900 2650 4900
Wire Wire Line
	2050 5000 2650 5000
Wire Wire Line
	2050 5100 2650 5100
Wire Notes Line
	11050 4000 11050 650 
Wire Wire Line
	10250 3250 10750 3250
Wire Wire Line
	10250 3450 10750 3450
Wire Wire Line
	10250 3650 10750 3650
Wire Wire Line
	8050 1550 8550 1550
Wire Wire Line
	8050 1750 8550 1750
Wire Wire Line
	8050 1950 8550 1950
Text Label 10650 3250 2    50   ~ 0
KEY_14
Text Label 10650 3450 2    50   ~ 0
KEY_13
Text Label 10650 3650 2    50   ~ 0
KEY_12
Text Label 8450 1550 2    50   ~ 0
KEY_11
Text Label 8450 1750 2    50   ~ 0
KEY_10
Text Label 8400 1950 2    50   ~ 0
KEY_9
Wire Wire Line
	10250 1550 10750 1550
Text Label 10650 1550 2    50   ~ 0
KEY_23
Text Label 10650 3050 2    50   ~ 0
KEY_15
Wire Wire Line
	10250 2950 10750 2950
Wire Wire Line
	10250 3150 10750 3150
Text Label 10650 2950 2    50   ~ 0
KEY_7
Text Label 10650 3150 2    50   ~ 0
KEY_6
Wire Wire Line
	10250 3050 10750 3050
$Comp
L Device:R R19
U 1 1 5C656AD7
P 7350 5300
F 0 "R19" V 7250 5300 50  0000 C CNN
F 1 "33" V 7450 5300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7280 5300 50  0001 C CNN
F 3 "~" H 7350 5300 50  0001 C CNN
	1    7350 5300
	0    1    1    0   
$EndComp
$Comp
L Device:R R17
U 1 1 5C6561AE
P 7350 4600
F 0 "R17" V 7250 4600 50  0000 C CNN
F 1 "33" V 7450 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7280 4600 50  0001 C CNN
F 3 "~" H 7350 4600 50  0001 C CNN
	1    7350 4600
	0    1    1    0   
$EndComp
Text Label 1500 2050 0    50   ~ 0
LED_2
Wire Wire Line
	1500 2050 2150 2050
Wire Wire Line
	8050 2150 8550 2150
Text Label 8400 2150 2    50   ~ 0
KEY_8
Text Label 1500 2250 0    50   ~ 0
LED_0
Wire Wire Line
	1500 2250 2150 2250
Wire Notes Line rgb(90, 238, 7)
	1100 1900 1100 1850
Text Notes 800  1850 0    39   ~ 0
RGB lighting
Wire Notes Line rgb(90, 238, 7)
	1100 1900 1500 1900
Wire Wire Line
	1500 1950 2150 1950
Text Label 1500 1950 0    50   ~ 0
RGB_DO
$Comp
L Mechanical:MountingHole H1
U 1 1 61C7D45F
P 6200 6950
F 0 "H1" H 6300 6996 50  0000 L CNN
F 1 "MountingHole" H 6300 6905 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 6200 6950 50  0001 C CNN
F 3 "~" H 6200 6950 50  0001 C CNN
	1    6200 6950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 61C7E905
P 6200 7150
F 0 "H2" H 6300 7196 50  0000 L CNN
F 1 "MountingHole" H 6300 7105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 6200 7150 50  0001 C CNN
F 3 "~" H 6200 7150 50  0001 C CNN
	1    6200 7150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 61C9AB4E
P 6200 7350
F 0 "H3" H 6300 7396 50  0000 L CNN
F 1 "MountingHole" H 6300 7305 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 6200 7350 50  0001 C CNN
F 3 "~" H 6200 7350 50  0001 C CNN
	1    6200 7350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 61CB6DDB
P 6200 7550
F 0 "H4" H 6300 7596 50  0000 L CNN
F 1 "MountingHole" H 6300 7505 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580" H 6200 7550 50  0001 C CNN
F 3 "~" H 6200 7550 50  0001 C CNN
	1    6200 7550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial LOGO1
U 1 1 61D0BFCA
P 6200 6600
F 0 "LOGO1" H 6285 6600 50  0000 L CNN
F 1 "Logo" H 6285 6555 50  0001 L CNN
F 2 "OpeNITHM:openithm-logo" H 6200 6600 50  0001 C CNN
F 3 "~" H 6200 6600 50  0001 C CNN
	1    6200 6600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial LOGO2
U 1 1 5EDBDB31
P 6200 6750
F 0 "LOGO2" H 6285 6750 50  0000 L CNN
F 1 "Logo" H 6285 6705 50  0001 L CNN
F 2 "OpeNITHM:openithm-logo" H 6200 6750 50  0001 C CNN
F 3 "~" H 6200 6750 50  0001 C CNN
	1    6200 6750
	1    0    0    -1  
$EndComp
Text Notes 4500 6650 0    50   ~ 0
NOTE:\nR_AIR is highly dependent on your \nIR leds and phototransistor/diodes.\nThey may range from \n10k Ohm to 2M Ohm.
Wire Wire Line
	2050 4200 2300 4200
$Comp
L power:+5V #PWR0121
U 1 1 5F2974C6
P 3300 3850
F 0 "#PWR0121" H 3300 3700 50  0001 C CNN
F 1 "+5V" H 3315 4023 50  0000 C CNN
F 2 "" H 3300 3850 50  0001 C CNN
F 3 "" H 3300 3850 50  0001 C CNN
	1    3300 3850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 4200 2300 4100
Connection ~ 2300 4200
Wire Notes Line rgb(90, 238, 7)
	3300 2200 3300 2150
Wire Wire Line
	1550 4300 1400 4300
Wire Wire Line
	1400 4300 1400 4200
Wire Wire Line
	750  4200 1400 4200
Wire Wire Line
	1550 4200 1450 4200
Wire Wire Line
	1450 4200 1450 4100
Wire Wire Line
	750  4100 1450 4100
Wire Wire Line
	1550 4100 1500 4100
Wire Wire Line
	1500 4100 1500 4000
Wire Wire Line
	750  4000 1500 4000
Wire Wire Line
	1550 4000 1550 3900
Wire Wire Line
	1550 3900 1450 3900
Wire Notes Line
	11050 4100 11050 5900
Wire Notes Line
	9200 5900 11050 5900
Wire Notes Line
	9200 4100 11050 4100
Wire Notes Line
	9200 4100 9200 5900
Text Notes 9300 4300 0    79   ~ 16
Extra Pin Breakout
$Comp
L Connector_Generic:Conn_02x07_Odd_Even J3
U 1 1 5F1F3A47
P 10300 5100
F 0 "J3" H 10350 5525 50  0000 C CNN
F 1 "Conn_02x07_Odd_Even" H 10350 5526 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x07_P2.54mm_Horizontal" H 10300 5100 50  0001 C CNN
F 3 "~" H 10300 5100 50  0001 C CNN
	1    10300 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5F5D50D2
P 10700 5500
F 0 "#PWR0123" H 10700 5250 50  0001 C CNN
F 1 "GND" H 10705 5327 50  0000 C CNN
F 2 "" H 10700 5500 50  0001 C CNN
F 3 "" H 10700 5500 50  0001 C CNN
	1    10700 5500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10600 5400 10700 5400
Wire Wire Line
	10700 5400 10700 5500
Wire Wire Line
	10600 5300 10700 5300
Wire Wire Line
	10700 5300 10700 5400
Connection ~ 10700 5400
Wire Wire Line
	10600 5200 10700 5200
Wire Wire Line
	10700 5200 10700 5300
Connection ~ 10700 5300
Wire Wire Line
	10600 5100 10700 5100
Wire Wire Line
	10700 5100 10700 5200
Connection ~ 10700 5200
Wire Wire Line
	10600 5000 10700 5000
Wire Wire Line
	10700 5000 10700 5100
Connection ~ 10700 5100
Wire Wire Line
	10600 4900 10700 4900
Wire Wire Line
	10700 4900 10700 5000
Connection ~ 10700 5000
Wire Wire Line
	10600 4800 10700 4800
Wire Wire Line
	10700 4800 10700 4900
Connection ~ 10700 4900
Wire Wire Line
	2150 2450 1500 2450
Wire Wire Line
	2150 2550 1500 2550
Text Label 1500 2550 0    50   ~ 0
SPARE_5
Wire Wire Line
	2150 2650 1500 2650
Text Label 1500 2650 0    50   ~ 0
SPARE_6
Wire Wire Line
	4100 2550 3450 2550
Text Label 3450 2550 0    50   ~ 0
SPARE_2
Wire Wire Line
	4100 2650 3450 2650
Text Label 3450 2650 0    50   ~ 0
SPARE_0
Wire Wire Line
	2150 2350 1500 2350
Text Label 1500 2350 0    50   ~ 0
SPARE_3
Text Label 1500 2450 0    50   ~ 0
SPARE_4
Wire Wire Line
	5800 1800 5150 1800
Text Label 5150 1800 0    50   ~ 0
SPARE_1
Wire Wire Line
	10100 4900 9450 4900
Wire Wire Line
	10100 5000 9450 5000
Text Label 9450 5000 0    50   ~ 0
SPARE_2
Wire Wire Line
	10100 5100 9450 5100
Text Label 9450 5100 0    50   ~ 0
SPARE_3
Wire Wire Line
	10100 4800 9450 4800
Text Label 9450 4800 0    50   ~ 0
SPARE_0
Text Label 9450 4900 0    50   ~ 0
SPARE_1
Wire Wire Line
	10100 5200 9450 5200
Text Label 9450 5200 0    50   ~ 0
SPARE_4
Wire Wire Line
	10100 5300 9450 5300
Text Label 9450 5300 0    50   ~ 0
SPARE_5
Wire Wire Line
	10100 5400 9450 5400
Text Label 9450 5400 0    50   ~ 0
SPARE_6
$Comp
L power:VCC #PWR0111
U 1 1 5F918C4D
P 1450 3900
F 0 "#PWR0111" H 1450 3750 50  0001 C CNN
F 1 "VCC" H 1465 4073 50  0000 C CNN
F 2 "" H 1450 3900 50  0001 C CNN
F 3 "" H 1450 3900 50  0001 C CNN
	1    1450 3900
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP1
U 1 1 5FA0B943
P 1100 3250
F 0 "JP1" H 1100 3363 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 1100 3364 50  0001 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 1100 3250 50  0001 C CNN
F 3 "~" H 1100 3250 50  0001 C CNN
	1    1100 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0125
U 1 1 5FA2E042
P 800 3250
F 0 "#PWR0125" H 800 3100 50  0001 C CNN
F 1 "+5V" H 815 3423 50  0000 C CNN
F 2 "" H 800 3250 50  0001 C CNN
F 3 "" H 800 3250 50  0001 C CNN
	1    800  3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0126
U 1 1 5FA2E048
P 1400 3250
F 0 "#PWR0126" H 1400 3100 50  0001 C CNN
F 1 "+3.3V" H 1415 3423 50  0000 C CNN
F 2 "" H 1400 3250 50  0001 C CNN
F 3 "" H 1400 3250 50  0001 C CNN
	1    1400 3250
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0127
U 1 1 5FA91A52
P 1550 3400
F 0 "#PWR0127" H 1550 3250 50  0001 C CNN
F 1 "VCC" H 1565 3573 50  0000 C CNN
F 2 "" H 1550 3400 50  0001 C CNN
F 3 "" H 1550 3400 50  0001 C CNN
	1    1550 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3400 1100 3450
Wire Wire Line
	1550 3450 1550 3400
Wire Wire Line
	1400 3250 1300 3250
Wire Wire Line
	900  3250 800  3250
Wire Wire Line
	1100 3450 1550 3450
Wire Notes Line
	700  3000 1650 3000
Wire Notes Line
	1650 3000 1650 3500
Wire Notes Line
	1650 3500 700  3500
Wire Notes Line
	700  3500 700  3000
Wire Notes Line
	1650 3100 1800 3100
Text Notes 1800 3200 0    50   ~ 0
VCC\nSelection
$EndSCHEMATC
