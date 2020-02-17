EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 10800 1650 2    50   ~ 0
KEY_8
Text Label 10800 1750 2    50   ~ 0
KEY_9
Text Label 10850 1850 2    50   ~ 0
KEY_10
Text Label 10850 1950 2    50   ~ 0
KEY_11
Text Label 10850 2050 2    50   ~ 0
KEY_12
Text Label 10850 2150 2    50   ~ 0
KEY_13
Text Label 10850 2250 2    50   ~ 0
KEY_14
Text Label 10850 2350 2    50   ~ 0
KEY_15
$Comp
L power:GND #PWR0101
U 1 1 5C4E18A5
P 8450 1400
F 0 "#PWR0101" H 8450 1150 50  0001 C CNN
F 1 "GND" H 8550 1400 50  0000 C CNN
F 2 "" H 8450 1400 50  0001 C CNN
F 3 "" H 8450 1400 50  0001 C CNN
	1    8450 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5C4E18B0
P 7250 2200
F 0 "#PWR0102" H 7250 1950 50  0001 C CNN
F 1 "GND" H 7255 2027 50  0000 C CNN
F 2 "" H 7250 2200 50  0001 C CNN
F 3 "" H 7250 2200 50  0001 C CNN
	1    7250 2200
	1    0    0    -1  
$EndComp
Text Label 8600 1650 2    50   ~ 0
KEY_0
Text Label 8600 1750 2    50   ~ 0
KEY_1
Text Label 8600 1850 2    50   ~ 0
KEY_2
Text Label 8600 1950 2    50   ~ 0
KEY_3
Text Label 8600 2050 2    50   ~ 0
KEY_4
Text Label 8600 2150 2    50   ~ 0
KEY_5
Text Label 8600 2250 2    50   ~ 0
KEY_6
Text Label 8600 2350 2    50   ~ 0
KEY_7
Text Label 6700 1850 0    50   ~ 0
MUX_0
Text Label 6700 1950 0    50   ~ 0
MUX_1
Text Label 6700 2050 0    50   ~ 0
MUX_2
Text Label 6700 1750 0    50   ~ 0
TOUCH_0
$Comp
L power:GND #PWR0106
U 1 1 5C5CC16C
P 9450 2200
F 0 "#PWR0106" H 9450 1950 50  0001 C CNN
F 1 "GND" H 9455 2027 50  0000 C CNN
F 2 "" H 9450 2200 50  0001 C CNN
F 3 "" H 9450 2200 50  0001 C CNN
	1    9450 2200
	1    0    0    -1  
$EndComp
Text Label 8900 1850 0    50   ~ 0
MUX_0
Text Label 8900 1950 0    50   ~ 0
MUX_1
Text Label 8900 2050 0    50   ~ 0
MUX_2
Text Label 8900 1750 0    50   ~ 0
TOUCH_1
Text Notes 8150 850  0    79   ~ 16
Capacitive Touch Sensing
Text Notes 3100 900  0    79   ~ 16
Teensy LC Headers
Wire Notes Line rgb(194, 0, 0)
	3300 2150 3300 2500
Wire Notes Line rgb(194, 0, 0)
	3300 2500 3450 2500
Wire Notes Line rgb(194, 0, 0)
	3050 2150 3050 2100
Text Notes 2750 2100 0    39   ~ 0
RGB lighting
$Comp
L Device:R R20
U 1 1 5C729DF3
P 1900 6250
F 0 "R20" H 1750 6300 50  0000 C CNN
F 1 "51k" H 1750 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 1830 6250 50  0001 C CNN
F 3 "~" H 1900 6250 50  0001 C CNN
	1    1900 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5C72A0CC
P 1900 6450
F 0 "#PWR0114" H 1900 6200 50  0001 C CNN
F 1 "GND" H 1905 6277 50  0000 C CNN
F 2 "" H 1900 6450 50  0001 C CNN
F 3 "" H 1900 6450 50  0001 C CNN
	1    1900 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6450 1900 6400
Text Label 1600 6000 0    50   ~ 0
AIR_0
Text Notes 8150 7650 0    50   ~ 0
2020/02/16
Text Notes 7400 7500 0    59   ~ 0
OpeNITHM controller board
Text Notes 10600 7650 0    59   ~ 0
2
Text Notes 7100 6900 0    197  ~ 39
OpeNITHM (Teensy Variant)
Text Notes 7150 7100 0    79   ~ 0
Design by VeroxZik based on work by WinEpic and mickabrig7
Wire Wire Line
	1900 6000 1900 6100
$Comp
L power:GND #PWR0116
U 1 1 5C56559A
P 2350 6450
F 0 "#PWR0116" H 2350 6200 50  0001 C CNN
F 1 "GND" H 2355 6277 50  0000 C CNN
F 2 "" H 2350 6450 50  0001 C CNN
F 3 "" H 2350 6450 50  0001 C CNN
	1    2350 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 6450 2350 6400
Text Label 2050 6000 0    50   ~ 0
AIR_1
Wire Wire Line
	2350 6000 2350 6100
$Comp
L power:GND #PWR0118
U 1 1 5C56F9CA
P 2800 6450
F 0 "#PWR0118" H 2800 6200 50  0001 C CNN
F 1 "GND" H 2805 6277 50  0000 C CNN
F 2 "" H 2800 6450 50  0001 C CNN
F 3 "" H 2800 6450 50  0001 C CNN
	1    2800 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 6450 2800 6400
Text Label 2500 6000 0    50   ~ 0
AIR_2
Wire Wire Line
	2800 6000 2800 6100
$Comp
L power:GND #PWR0120
U 1 1 5C575383
P 3250 6450
F 0 "#PWR0120" H 3250 6200 50  0001 C CNN
F 1 "GND" H 3255 6277 50  0000 C CNN
F 2 "" H 3250 6450 50  0001 C CNN
F 3 "" H 3250 6450 50  0001 C CNN
	1    3250 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 6450 3250 6400
Text Label 2950 6000 0    50   ~ 0
AIR_3
Wire Wire Line
	3250 6000 3250 6100
$Comp
L power:GND #PWR0122
U 1 1 5C57B691
P 3700 6450
F 0 "#PWR0122" H 3700 6200 50  0001 C CNN
F 1 "GND" H 3705 6277 50  0000 C CNN
F 2 "" H 3700 6450 50  0001 C CNN
F 3 "" H 3700 6450 50  0001 C CNN
	1    3700 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 6450 3700 6400
Text Label 3400 6000 0    50   ~ 0
AIR_4
Wire Wire Line
	3700 6000 3700 6100
$Comp
L power:GND #PWR0124
U 1 1 5C5820E4
P 4150 6450
F 0 "#PWR0124" H 4150 6200 50  0001 C CNN
F 1 "GND" H 4155 6277 50  0000 C CNN
F 2 "" H 4150 6450 50  0001 C CNN
F 3 "" H 4150 6450 50  0001 C CNN
	1    4150 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 6450 4150 6400
Text Label 3850 6000 0    50   ~ 0
AIR_5
Text Notes 5700 4600 0    50   ~ 0
 Connected to\n   off-board\nphototransistors
Text Notes 2400 5100 0    79   ~ 16
IR Sensors
$Comp
L Device:R R17
U 1 1 5C6561AE
P 7650 3200
F 0 "R17" V 7550 3200 50  0000 C CNN
F 1 "33" V 7750 3200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7580 3200 50  0001 C CNN
F 3 "~" H 7650 3200 50  0001 C CNN
	1    7650 3200
	0    1    1    0   
$EndComp
$Comp
L Device:R R18
U 1 1 5C656A75
P 7650 3550
F 0 "R18" V 7550 3550 50  0000 C CNN
F 1 "33" V 7750 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7580 3550 50  0001 C CNN
F 3 "~" H 7650 3550 50  0001 C CNN
	1    7650 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R19
U 1 1 5C656AD7
P 7650 3900
F 0 "R19" V 7550 3900 50  0000 C CNN
F 1 "33" V 7750 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7580 3900 50  0001 C CNN
F 3 "~" H 7650 3900 50  0001 C CNN
	1    7650 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 3200 7900 3200
Wire Wire Line
	7900 3200 7900 3450
Wire Wire Line
	7800 3900 7900 3900
Wire Wire Line
	7900 3900 7900 3650
Wire Wire Line
	7500 3200 7100 3200
Wire Wire Line
	7500 3550 7100 3550
Wire Wire Line
	7500 3900 7100 3900
Text Label 7100 3200 0    50   ~ 0
LED_0
Text Label 7100 3550 0    50   ~ 0
LED_1
Text Label 7100 3900 0    50   ~ 0
LED_2
$Comp
L Device:R R21
U 1 1 5C7370DB
P 2350 6250
F 0 "R21" H 2200 6300 50  0000 C CNN
F 1 "51k" H 2200 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2280 6250 50  0001 C CNN
F 3 "~" H 2350 6250 50  0001 C CNN
	1    2350 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R22
U 1 1 5C737141
P 2800 6250
F 0 "R22" H 2650 6300 50  0000 C CNN
F 1 "51k" H 2650 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2730 6250 50  0001 C CNN
F 3 "~" H 2800 6250 50  0001 C CNN
	1    2800 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R23
U 1 1 5C7371B3
P 3250 6250
F 0 "R23" H 3100 6300 50  0000 C CNN
F 1 "51k" H 3100 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3180 6250 50  0001 C CNN
F 3 "~" H 3250 6250 50  0001 C CNN
	1    3250 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R24
U 1 1 5C737282
P 3700 6250
F 0 "R24" H 3550 6300 50  0000 C CNN
F 1 "51k" H 3550 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3630 6250 50  0001 C CNN
F 3 "~" H 3700 6250 50  0001 C CNN
	1    3700 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 5C737302
P 4150 6250
F 0 "R25" H 4000 6300 50  0000 C CNN
F 1 "51k" H 4000 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4080 6250 50  0001 C CNN
F 3 "~" H 4150 6250 50  0001 C CNN
	1    4150 6250
	1    0    0    -1  
$EndComp
Text Notes 7550 2950 0    79   ~ 16
IR LEDs
Wire Notes Line
	6450 2850 6450 650 
Wire Notes Line
	9000 2950 9300 2950
Wire Notes Line
	9300 2800 9000 2800
Wire Notes Line
	9300 2950 9300 2800
Wire Notes Line
	9000 2950 9000 2800
Text Notes 8950 2850 0    31   ~ 0
A
Text Notes 8950 2950 0    31   ~ 0
K
Wire Notes Line
	9000 3200 9300 3200
Wire Notes Line
	9300 3050 9000 3050
Wire Notes Line
	9300 3200 9300 3050
Wire Notes Line
	9000 3200 9000 3050
Text Notes 8950 3100 0    31   ~ 0
A
Text Notes 8950 3200 0    31   ~ 0
K
Wire Notes Line
	9000 3450 9300 3450
Wire Notes Line
	9300 3300 9000 3300
Wire Notes Line
	9300 3450 9300 3300
Wire Notes Line
	9000 3450 9000 3300
Text Notes 8950 3350 0    31   ~ 0
A
Text Notes 8950 3450 0    31   ~ 0
K
Wire Notes Line
	9000 3700 9300 3700
Wire Notes Line
	9300 3550 9000 3550
Wire Notes Line
	9300 3700 9300 3550
Wire Notes Line
	9000 3700 9000 3550
Text Notes 8950 3600 0    31   ~ 0
A
Text Notes 8950 3700 0    31   ~ 0
K
Wire Notes Line
	9000 3950 9300 3950
Wire Notes Line
	9300 3800 9000 3800
Wire Notes Line
	9300 3950 9300 3800
Wire Notes Line
	9000 3950 9000 3800
Text Notes 8950 3850 0    31   ~ 0
A
Text Notes 8950 3950 0    31   ~ 0
K
Wire Notes Line
	9000 4200 9300 4200
Wire Notes Line
	9300 4050 9000 4050
Text Notes 9000 4150 0    51   ~ 0
LED #1
Wire Notes Line
	9300 4200 9300 4050
Wire Notes Line
	9000 4200 9000 4050
Text Notes 8950 4100 0    31   ~ 0
A
Text Notes 8950 4200 0    31   ~ 0
K
Wire Notes Line
	8850 2900 9000 2900
Wire Notes Line
	9000 3100 8850 3100
Wire Notes Line
	9000 3900 8850 3900
Wire Notes Line
	9000 4100 8850 4100
Wire Notes Line rgb(194, 0, 0)
	8750 3400 9000 3400
Wire Notes Line rgb(194, 0, 0)
	9000 4150 8750 4150
Wire Notes Line rgb(194, 0, 0)
	9000 3850 8750 3850
Wire Notes Line rgb(0, 194, 0)
	8650 2850 9000 2850
Wire Notes Line rgb(0, 194, 0)
	9000 3150 8650 3150
Wire Notes Line rgb(0, 194, 0)
	9000 3350 8650 3350
$Comp
L Connector_Generic:Conn_01x11 J4
U 1 1 5C5F7151
P 7950 1850
F 0 "J4" H 7950 2500 50  0000 C CNN
F 1 "Conn_01x11" H 7870 2476 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x11_P2.54mm_Vertical" H 7950 1850 50  0001 C CNN
F 3 "~" H 7950 1850 50  0001 C CNN
	1    7950 1850
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J3
U 1 1 5C65D754
P 7550 1750
F 0 "J3" H 7500 2200 50  0000 L CNN
F 1 "Conn_01x08" H 7630 1651 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 7550 1750 50  0001 C CNN
F 3 "~" H 7550 1750 50  0001 C CNN
	1    7550 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2150 7350 2150
Wire Wire Line
	8150 1650 8700 1650
Wire Wire Line
	8150 1750 8700 1750
Wire Wire Line
	8150 1850 8700 1850
Wire Wire Line
	8150 1950 8700 1950
Wire Wire Line
	8150 2050 8700 2050
Wire Wire Line
	8150 2150 8700 2150
Wire Wire Line
	8150 2250 8700 2250
Wire Wire Line
	8150 2350 8700 2350
Wire Wire Line
	8150 1450 8250 1450
Wire Wire Line
	8250 1450 8250 1300
Wire Wire Line
	8150 1350 8350 1350
Wire Wire Line
	8350 1350 8350 1550
Wire Wire Line
	8350 1550 8150 1550
Wire Wire Line
	8350 1350 8450 1350
Connection ~ 8350 1350
Wire Wire Line
	8450 1350 8450 1400
$Comp
L power:GND #PWR0105
U 1 1 5C6F9E43
P 7050 1500
F 0 "#PWR0105" H 7050 1250 50  0001 C CNN
F 1 "GND" H 7150 1500 50  0000 C CNN
F 2 "" H 7050 1500 50  0001 C CNN
F 3 "" H 7050 1500 50  0001 C CNN
	1    7050 1500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7350 1550 7250 1550
Wire Wire Line
	7350 1450 7150 1450
Wire Wire Line
	7150 1450 7150 1650
Wire Wire Line
	7150 1650 7350 1650
Wire Wire Line
	7150 1450 7050 1450
Connection ~ 7150 1450
Wire Wire Line
	7050 1450 7050 1500
Wire Wire Line
	6700 1750 7350 1750
Wire Wire Line
	6700 1850 7350 1850
Wire Wire Line
	6700 1950 7350 1950
Wire Wire Line
	6700 2050 7350 2050
$Comp
L Connector_Generic:Conn_01x11 J6
U 1 1 5C783A73
P 10150 1850
F 0 "J6" H 10150 2500 50  0000 C CNN
F 1 "Conn_01x11" H 10070 2476 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x11_P2.54mm_Vertical" H 10150 1850 50  0001 C CNN
F 3 "~" H 10150 1850 50  0001 C CNN
	1    10150 1850
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J5
U 1 1 5C783A7A
P 9750 1750
F 0 "J5" H 9700 2200 50  0000 L CNN
F 1 "Conn_01x08" H 9830 1651 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 9750 1750 50  0001 C CNN
F 3 "~" H 9750 1750 50  0001 C CNN
	1    9750 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5C7A778A
P 9250 1500
F 0 "#PWR0108" H 9250 1250 50  0001 C CNN
F 1 "GND" H 9350 1500 50  0000 C CNN
F 2 "" H 9250 1500 50  0001 C CNN
F 3 "" H 9250 1500 50  0001 C CNN
	1    9250 1500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9550 1550 9450 1550
Wire Wire Line
	9450 1550 9450 1350
Wire Wire Line
	9550 1450 9350 1450
Wire Wire Line
	9350 1450 9350 1650
Wire Wire Line
	9350 1650 9550 1650
Wire Wire Line
	9350 1450 9250 1450
Connection ~ 9350 1450
Wire Wire Line
	9250 1450 9250 1500
$Comp
L power:GND #PWR0126
U 1 1 5C7BFCD4
P 10650 1400
F 0 "#PWR0126" H 10650 1150 50  0001 C CNN
F 1 "GND" H 10750 1400 50  0000 C CNN
F 2 "" H 10650 1400 50  0001 C CNN
F 3 "" H 10650 1400 50  0001 C CNN
	1    10650 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 1450 10450 1450
Wire Wire Line
	10450 1450 10450 1300
Wire Wire Line
	10350 1350 10550 1350
Wire Wire Line
	10550 1350 10550 1550
Wire Wire Line
	10550 1550 10350 1550
Wire Wire Line
	10550 1350 10650 1350
Connection ~ 10550 1350
Wire Wire Line
	10650 1350 10650 1400
Wire Wire Line
	10350 1650 10950 1650
Wire Wire Line
	10350 1750 10950 1750
Wire Wire Line
	10350 1850 10950 1850
Wire Wire Line
	10350 1950 10950 1950
Wire Wire Line
	10350 2050 10950 2050
Wire Wire Line
	10350 2150 10950 2150
Wire Wire Line
	10350 2250 10950 2250
Wire Wire Line
	10350 2350 10950 2350
Wire Wire Line
	9550 1750 8900 1750
Wire Wire Line
	8900 1850 9550 1850
Wire Wire Line
	9550 1950 8900 1950
Wire Wire Line
	8900 2050 9550 2050
Wire Wire Line
	9450 2150 9550 2150
Text Notes 7400 1100 0    50   ~ 0
74HC4051 module
Text Notes 9600 1100 0    50   ~ 0
74HC4051 module
Wire Notes Line
	6600 2700 11050 2700
Wire Notes Line
	8850 4100 8850 2900
Wire Notes Line rgb(194, 0, 0)
	8750 4150 8750 3400
Wire Notes Line rgb(0, 194, 0)
	8650 3650 8650 2850
Wire Notes Line rgb(194, 0, 0)
	9000 3600 8750 3600
Wire Notes Line
	6600 2700 6600 4500
Wire Notes Line
	6600 4500 11050 4500
Wire Notes Line
	11050 4500 11050 2700
Wire Notes Line
	8400 3450 8850 3450
Wire Notes Line rgb(194, 0, 0)
	8400 3550 8750 3550
Wire Notes Line rgb(0, 194, 0)
	8400 3650 9000 3650
Text Notes 9000 3900 0    51   ~ 0
LED #2
Text Notes 9000 3650 0    51   ~ 0
LED #3
Text Notes 9000 3400 0    51   ~ 0
LED #4
Text Notes 9000 3150 0    51   ~ 0
LED #5
Text Notes 9000 2900 0    51   ~ 0
LED #6
Wire Wire Line
	9450 2200 9450 2150
Wire Wire Line
	7250 2200 7250 2150
Wire Notes Line
	6600 650  11050 650 
Wire Notes Line
	11050 2550 11050 650 
Wire Notes Line
	11050 2550 6600 2550
Wire Notes Line
	6600 2550 6600 650 
Wire Notes Line
	6450 6800 650  6800
Wire Wire Line
	4150 6000 4150 6100
Wire Wire Line
	3850 6000 4150 6000
Wire Wire Line
	3400 6000 3700 6000
Wire Wire Line
	2950 6000 3250 6000
Wire Wire Line
	2500 6000 2800 6000
Wire Wire Line
	2050 6000 2350 6000
Wire Wire Line
	1600 6000 1900 6000
Wire Notes Line
	800  5350 1100 5350
Wire Notes Line
	1100 5200 800  5200
Wire Notes Line
	1100 5350 1100 5200
Wire Notes Line
	800  5350 800  5200
Wire Notes Line
	800  5600 1100 5600
Wire Notes Line
	1100 5450 800  5450
Wire Notes Line
	1100 5600 1100 5450
Wire Notes Line
	800  5600 800  5450
Wire Notes Line
	800  5850 1100 5850
Wire Notes Line
	1100 5700 800  5700
Wire Notes Line
	1100 5850 1100 5700
Wire Notes Line
	800  5850 800  5700
Wire Notes Line
	800  6100 1100 6100
Wire Notes Line
	1100 5950 800  5950
Wire Notes Line
	1100 6100 1100 5950
Wire Notes Line
	800  6100 800  5950
Wire Notes Line
	800  6350 1100 6350
Wire Notes Line
	1100 6200 800  6200
Wire Notes Line
	1100 6350 1100 6200
Wire Notes Line
	800  6350 800  6200
Wire Notes Line
	800  6600 1100 6600
Wire Notes Line
	1100 6450 800  6450
Wire Notes Line
	1100 6600 1100 6450
Wire Notes Line
	800  6600 800  6450
Text Notes 1150 5250 2    31   ~ 0
C
Text Notes 1150 5350 2    31   ~ 0
E
Text Notes 1150 5500 2    31   ~ 0
C
Text Notes 1150 5600 2    31   ~ 0
E
Text Notes 1150 5750 2    31   ~ 0
C
Text Notes 1150 5850 2    31   ~ 0
E
Text Notes 1150 6000 2    31   ~ 0
C
Text Notes 1150 6100 2    31   ~ 0
E
Text Notes 1150 6250 2    31   ~ 0
C
Text Notes 1150 6350 2    31   ~ 0
E
Text Notes 1150 6500 2    31   ~ 0
C
Text Notes 1150 6600 2    31   ~ 0
E
Wire Notes Line rgb(194, 0, 0)
	1100 6500 1250 6500
Wire Notes Line rgb(194, 0, 0)
	1250 6500 1250 5250
Wire Notes Line rgb(194, 0, 0)
	1100 6250 1250 6250
Wire Notes Line rgb(194, 0, 0)
	1100 6000 1250 6000
Wire Notes Line rgb(194, 0, 0)
	1100 5750 1250 5750
Wire Notes Line rgb(194, 0, 0)
	1100 5500 1250 5500
Wire Notes Line
	1100 6550 1500 6550
Wire Notes Line
	1500 5550 1900 5550
Wire Notes Line
	1100 6300 1450 6300
Wire Notes Line
	1450 5500 2350 5500
Wire Notes Line
	1100 6050 1400 6050
Wire Notes Line
	1400 5450 2800 5450
Wire Notes Line
	1100 5800 1350 5800
Wire Notes Line
	1350 5400 3250 5400
Wire Notes Line
	1100 5550 1300 5550
Wire Notes Line
	1300 5350 3700 5350
Wire Notes Line
	1100 5300 4150 5300
Wire Notes Line rgb(194, 0, 0)
	1100 5250 4600 5250
Wire Notes Line
	1500 6550 1500 5550
Wire Notes Line
	1450 6300 1450 5500
Wire Notes Line
	1400 6050 1400 5450
Wire Notes Line
	1350 5800 1350 5400
Wire Notes Line
	1300 5550 1300 5350
Wire Notes Line
	6450 6800 6450 4850
Wire Notes Line
	6450 2850 650  2850
Wire Notes Line
	650  4850 650  6800
Text Notes 850  5350 0    28   ~ 0
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
Wire Wire Line
	1150 3650 1800 3650
Wire Wire Line
	1150 3750 1800 3750
Wire Wire Line
	1150 3850 1800 3850
Wire Wire Line
	1150 3950 1800 3950
Wire Wire Line
	1150 4050 1800 4050
Wire Wire Line
	1150 4150 1800 4150
Wire Wire Line
	1150 4250 1800 4250
Wire Wire Line
	1150 4350 1800 4350
Text Label 3450 2350 0    50   ~ 0
TOUCH_0
Wire Wire Line
	3450 2350 4100 2350
Wire Wire Line
	3800 3650 4450 3650
Wire Wire Line
	3800 3750 4450 3750
Wire Wire Line
	3800 3850 4450 3850
Wire Wire Line
	3800 3950 4450 3950
Wire Wire Line
	3800 4050 4450 4050
Wire Wire Line
	3800 4150 4450 4150
Wire Wire Line
	3800 4250 4450 4250
Wire Wire Line
	3800 4350 4450 4350
Text Label 1150 3650 0    50   ~ 0
KEY_0
Text Label 1150 3750 0    50   ~ 0
KEY_1
Text Label 1150 3850 0    50   ~ 0
KEY_2
Text Label 1150 3950 0    50   ~ 0
KEY_3
Text Label 1150 4050 0    50   ~ 0
KEY_4
Text Label 1150 4150 0    50   ~ 0
KEY_5
Text Label 1150 4250 0    50   ~ 0
KEY_6
Text Label 1150 4350 0    50   ~ 0
KEY_7
Text Label 3800 3650 0    50   ~ 0
KEY_8
Text Label 3800 3750 0    50   ~ 0
KEY_9
Text Label 3800 3850 0    50   ~ 0
KEY_10
Text Label 3800 3950 0    50   ~ 0
KEY_11
Text Label 3800 4050 0    50   ~ 0
KEY_12
Text Label 3800 4150 0    50   ~ 0
KEY_13
Text Label 3800 4250 0    50   ~ 0
KEY_14
Text Label 3800 4350 0    50   ~ 0
KEY_15
Text Label 2450 3650 0    50   ~ 0
LED_0_OUT
Text Label 2450 3750 0    50   ~ 0
LED_1_OUT
Text Label 2450 3850 0    50   ~ 0
LED_2_OUT
Wire Wire Line
	3350 4050 3350 4000
Wire Wire Line
	3350 4350 3350 4400
Text Label 3450 4250 2    50   ~ 0
RGB_CO
Text Label 3450 4150 2    50   ~ 0
RGB_DO_OUT
$Comp
L power:+5V #PWR0111
U 1 1 5D492DB8
P 3350 4000
F 0 "#PWR0111" H 3350 3850 50  0001 C CNN
F 1 "+5V" H 3365 4173 50  0000 C CNN
F 2 "" H 3350 4000 50  0001 C CNN
F 3 "" H 3350 4000 50  0001 C CNN
	1    3350 4000
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5D492DBE
P 3350 4400
F 0 "#PWR0112" H 3350 4150 50  0001 C CNN
F 1 "GND" H 3355 4227 50  0000 C CNN
F 2 "" H 3350 4400 50  0001 C CNN
F 3 "" H 3350 4400 50  0001 C CNN
	1    3350 4400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 4050 3350 4050
Wire Wire Line
	2300 4150 3450 4150
Wire Wire Line
	2300 4250 3450 4250
Wire Wire Line
	2300 4350 3350 4350
Wire Wire Line
	4950 3750 5550 3750
Wire Wire Line
	4950 3850 5550 3850
Wire Wire Line
	4950 4050 5550 4050
Wire Wire Line
	4950 4250 5550 4250
Wire Wire Line
	4950 3950 5550 3950
Wire Wire Line
	4950 4150 5550 4150
Text Label 5300 3750 0    50   ~ 0
AIR_0
Text Label 5300 3850 0    50   ~ 0
AIR_1
Text Label 5300 3950 0    50   ~ 0
AIR_2
Text Label 5300 4050 0    50   ~ 0
AIR_3
Text Label 5300 4150 0    50   ~ 0
AIR_4
Text Label 5300 4250 0    50   ~ 0
AIR_5
$Comp
L power:+3.3V #PWR0113
U 1 1 5D5F2DAE
P 5400 3600
F 0 "#PWR0113" H 5400 3450 50  0001 C CNN
F 1 "+3.3V" H 5415 3773 50  0000 C CNN
F 2 "" H 5400 3600 50  0001 C CNN
F 3 "" H 5400 3600 50  0001 C CNN
	1    5400 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3650 5400 3650
Wire Wire Line
	5400 3650 5400 3600
Wire Wire Line
	2850 3650 2300 3650
Wire Wire Line
	2850 3850 2300 3850
Wire Wire Line
	2850 3750 2300 3750
Wire Wire Line
	2150 2050 1500 2050
Text Label 1500 2050 0    50   ~ 0
LED_1
Wire Wire Line
	1500 2150 2150 2150
Text Label 1500 2150 0    50   ~ 0
LED_0
Text Label 1500 1450 0    50   ~ 0
MUX_2
Wire Wire Line
	2150 1550 1500 1550
Wire Wire Line
	1500 1450 2150 1450
Text Notes 4400 2700 0    59   ~ 0
13
Text Label 3450 2550 0    50   ~ 0
RGB_CO
Wire Wire Line
	3450 2550 4100 2550
Text Label 1500 2550 0    50   ~ 0
RGB_DO
Wire Wire Line
	1500 2550 2150 2550
Wire Wire Line
	3450 1950 4100 1950
Wire Wire Line
	3450 2050 4100 2050
Wire Wire Line
	3450 1650 4100 1650
Wire Wire Line
	3450 1850 4100 1850
Wire Wire Line
	3450 2150 4100 2150
Wire Wire Line
	3450 1750 4100 1750
Text Label 3450 1950 0    50   ~ 0
AIR_0
Text Label 3450 2050 0    50   ~ 0
AIR_1
Text Label 3450 2150 0    50   ~ 0
AIR_2
Text Label 3450 1650 0    50   ~ 0
AIR_3
Text Label 3450 1750 0    50   ~ 0
AIR_4
Text Label 3450 1850 0    50   ~ 0
AIR_5
Wire Wire Line
	1500 1950 2150 1950
Text Label 1500 1950 0    50   ~ 0
LED_2
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
	3250 5400 3250 6000
Wire Notes Line
	4150 5300 4150 6000
Wire Notes Line
	3700 5350 3700 6000
Wire Notes Line
	2800 5450 2800 6000
Wire Notes Line
	2350 5500 2350 6000
Wire Notes Line
	1900 5550 1900 6000
Wire Notes Line
	1500 1700 1250 1700
Text Notes 1300 1600 2    39   ~ 0
Capacitive touch
Wire Notes Line
	1250 1800 1500 1800
Wire Notes Line
	1250 1600 1250 1800
Wire Wire Line
	7250 1550 7250 1400
$Comp
L power:+3.3V #PWR0119
U 1 1 5DDA652E
P 7250 1400
F 0 "#PWR0119" H 7250 1250 50  0001 C CNN
F 1 "+3.3V" H 7265 1573 50  0000 C CNN
F 2 "" H 7250 1400 50  0001 C CNN
F 3 "" H 7250 1400 50  0001 C CNN
	1    7250 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0121
U 1 1 5DDCFA29
P 8250 1300
F 0 "#PWR0121" H 8250 1150 50  0001 C CNN
F 1 "+3.3V" H 8265 1473 50  0000 C CNN
F 2 "" H 8250 1300 50  0001 C CNN
F 3 "" H 8250 1300 50  0001 C CNN
	1    8250 1300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0123
U 1 1 5DDF8FA8
P 10450 1300
F 0 "#PWR0123" H 10450 1150 50  0001 C CNN
F 1 "+3.3V" H 10465 1473 50  0000 C CNN
F 2 "" H 10450 1300 50  0001 C CNN
F 3 "" H 10450 1300 50  0001 C CNN
	1    10450 1300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0125
U 1 1 5DE224A3
P 9450 1350
F 0 "#PWR0125" H 9450 1200 50  0001 C CNN
F 1 "+3.3V" H 9465 1523 50  0000 C CNN
F 2 "" H 9450 1350 50  0001 C CNN
F 3 "" H 9450 1350 50  0001 C CNN
	1    9450 1350
	1    0    0    -1  
$EndComp
Text Label 8000 3450 0    50   ~ 0
LED_0_OUT
Text Label 8000 3550 0    50   ~ 0
LED_1_OUT
Text Label 8000 3650 0    50   ~ 0
LED_2_OUT
Wire Wire Line
	7900 3450 8400 3450
Wire Wire Line
	7800 3550 8400 3550
Wire Wire Line
	7900 3650 8400 3650
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J7
U 1 1 5E036596
P 2000 3950
F 0 "J7" H 2050 4375 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 2050 4376 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Horizontal" H 2000 3950 50  0001 C CNN
F 3 "~" H 2000 3950 50  0001 C CNN
	1    2000 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J8
U 1 1 5E0481E5
P 4650 3950
F 0 "J8" H 4700 4375 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 4700 4376 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Horizontal" H 4650 3950 50  0001 C CNN
F 3 "~" H 4650 3950 50  0001 C CNN
	1    4650 3950
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 5E0B19FC
P 8000 5300
F 0 "JP1" H 8000 5400 50  0000 C CNN
F 1 "SolderJumper_3_Open" H 8000 5414 50  0001 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm" H 8000 5300 50  0001 C CNN
F 3 "~" H 8000 5300 50  0001 C CNN
	1    8000 5300
	1    0    0    -1  
$EndComp
Text Label 8600 5700 2    50   ~ 0
RGB_DO_OUT
Wire Wire Line
	8000 5700 8000 5450
Wire Wire Line
	8000 5700 8600 5700
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
Text Label 5200 1400 0    50   ~ 0
RGB_DO_BUF
Wire Wire Line
	5200 1400 5800 1400
Text Label 9000 5300 2    50   ~ 0
RGB_DO_BUF
Wire Wire Line
	8200 5300 9000 5300
Text Label 7150 5300 0    50   ~ 0
RGB_DO
Wire Wire Line
	7150 5300 7800 5300
Wire Wire Line
	2150 1750 1500 1750
Text Label 1500 1750 0    50   ~ 0
TOUCH_1
Wire Notes Line rgb(181, 36, 0)
	1500 1900 1000 1900
Wire Notes Line rgb(181, 36, 0)
	1000 1850 1000 1900
Wire Notes Line rgb(90, 238, 7)
	1100 2500 1500 2500
Text Notes 800  1850 0    39   ~ 0
IR LEDs
Wire Notes Line rgb(181, 36, 0)
	1500 2100 1350 2100
Wire Notes Line rgb(181, 36, 0)
	1350 2100 1350 1900
Wire Notes Line rgb(194, 0, 0)
	5050 1350 5050 1300
Text Notes 4750 1300 0    39   ~ 0
RGB lighting
Wire Notes Line rgb(194, 0, 0)
	5050 1350 5200 1350
Wire Notes Line
	6450 4850 650  4850
Text Notes 3150 3200 0    79   ~ 16
External Pin Headers
Wire Notes Line
	650  650  650  2850
Wire Notes Line
	6450 4700 650  4700
Wire Notes Line
	650  3000 650  4700
Wire Notes Line
	6450 3000 650  3000
Wire Notes Line
	6450 3000 6450 4700
Wire Notes Line
	5650 3350 5650 4650
Wire Notes Line
	5650 4650 5150 4650
Wire Notes Line
	5150 3350 5150 4650
Wire Notes Line
	5650 3350 5150 3350
Wire Notes Line
	5650 3500 5950 3500
Wire Notes Line
	5950 3500 5950 4350
Wire Notes Line
	2400 3950 2900 3950
Wire Notes Line
	2900 3950 2900 3500
Wire Notes Line
	2400 3950 2400 3500
Wire Notes Line
	2400 3500 2900 3500
Text Notes 700  3350 0    50   ~ 0
Connected to off-board Charlieplexed LEDs
Wire Notes Line
	2400 3300 2600 3300
Wire Notes Line
	2600 3300 2600 3500
Wire Notes Line
	6600 4650 6600 5850
Wire Notes Line
	6600 4650 11050 4650
Text Notes 7350 4900 0    79   ~ 16
RGB Power Selection
Wire Notes Line
	6600 5850 11050 5850
Wire Notes Line
	11050 4650 11050 5850
Wire Notes Line
	1050 4450 1050 3500
Wire Notes Line
	1050 3500 1450 3500
Wire Notes Line
	1050 4450 1450 4450
Wire Notes Line
	1450 4450 1450 3500
Text Notes 950  4600 0    50   ~ 0
Connected to Copper Pads
Wire Notes Line
	950  4550 900  4550
Wire Notes Line
	900  4550 900  3950
Wire Notes Line
	900  3950 1050 3950
Wire Notes Line
	3750 4450 3750 3500
Wire Notes Line
	3750 4450 4150 4450
Wire Notes Line
	4150 4450 4150 3500
Text Notes 3650 4600 0    50   ~ 0
Connected to Copper Pads
Wire Notes Line
	3650 4550 3600 4550
Wire Notes Line
	3600 4550 3600 3950
Wire Notes Line
	3600 3950 3750 3950
Wire Notes Line
	3750 3500 4150 3500
Wire Notes Line
	2950 4650 3500 4650
Wire Notes Line
	2950 4650 2950 3750
Wire Notes Line
	3500 4650 3500 3750
Wire Notes Line
	2950 3750 3500 3750
Text Notes 2300 4600 0    50   ~ 0
Connected to\nRGB Strip
Wire Notes Line
	2700 4550 2950 4550
Text Notes 9600 4450 0    50   ~ 0
A - Anode (Long Pin)\nK - Cathode (Short Pin, Flat Side)
Text Notes 9050 5750 0    50   ~ 0
Solder 1 and 2 together to use 3.3V logic\nSolder 2 and 3 together to use built-in 5V buffer
Text Notes 4600 5300 0    50   ~ 0
To +3.3V
Text Notes 4950 6650 0    50   ~ 0
If using Phototransistor:\nC - Collector\nE - Emitter\n\nIf using Photodiode:\nC - Cathode (Short Pin, Flat Side)\nE - Anode (Long Pin)
Text Notes 850  5600 0    28   ~ 0
  IR\nSensor\n  #5
Text Notes 850  5850 0    28   ~ 0
  IR\nSensor\n  #4
Text Notes 850  6100 0    28   ~ 0
  IR\nSensor\n  #3
Text Notes 850  6350 0    28   ~ 0
  IR\nSensor\n  #2
Text Notes 850  6600 0    28   ~ 0
  IR\nSensor\n  #1
Text Notes 800  2450 0    39   ~ 0
RGB lighting
Wire Notes Line rgb(90, 238, 7)
	1100 2500 1100 2450
Text Notes 3150 1700 2    39   ~ 0
Light sensors
Wire Notes Line
	3100 1850 3100 1700
Wire Notes Line
	3300 1850 3100 1850
Wire Notes Line
	3450 1700 3300 1700
Wire Notes Line
	3450 1800 3300 1800
Wire Notes Line
	3450 1900 3300 1900
Wire Notes Line
	3300 2100 3450 2100
Wire Notes Line
	3450 1600 3300 1600
Wire Notes Line
	3300 1600 3300 2100
Wire Notes Line
	3450 2000 3300 2000
Wire Notes Line rgb(181, 36, 0)
	1500 2000 1350 2000
Wire Notes Line rgb(255, 153, 9)
	1500 1400 1000 1400
Wire Notes Line rgb(255, 153, 90)
	1000 1350 1000 1400
Text Notes 800  1350 0    39   ~ 0
IR LEDs
Wire Notes Line rgb(255, 153, 9)
	1500 1600 1350 1600
Wire Notes Line rgb(255, 153, 9)
	1350 1600 1350 1400
Wire Notes Line rgb(255, 153, 9)
	1500 1500 1350 1500
Wire Wire Line
	1500 1650 2150 1650
Text Label 1500 1550 0    50   ~ 0
MUX_1
Text Label 1500 1650 0    50   ~ 0
MUX_0
Wire Notes Line rgb(194, 0, 0)
	3050 2150 3300 2150
Text Notes 3250 2250 2    39   ~ 0
Capacitive touch
Wire Notes Line rgb(194, 0, 0)
	3300 2200 3450 2200
Wire Notes Line rgb(255, 153, 9)
	3450 2300 3200 2300
Wire Notes Line rgb(255, 153, 90)
	3200 2250 3200 2300
$Comp
L power:GND #PWR0104
U 1 1 5E9D5F1A
P 5400 4400
F 0 "#PWR0104" H 5400 4150 50  0001 C CNN
F 1 "GND" H 5405 4227 50  0000 C CNN
F 2 "" H 5400 4400 50  0001 C CNN
F 3 "" H 5400 4400 50  0001 C CNN
	1    5400 4400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4950 4350 5400 4350
Wire Wire Line
	5400 4350 5400 4400
$EndSCHEMATC
