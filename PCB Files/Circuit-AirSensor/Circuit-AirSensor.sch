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
$Comp
L Device:LED D6
U 1 1 5DDA15CD
P 4700 2650
F 0 "D6" H 4691 2866 50  0000 C CNN
F 1 "IR LED" H 4691 2775 50  0000 C CNN
F 2 "AirSensor_Local:LED_D5.0mm_FlatTop" H 4700 2650 50  0001 C CNN
F 3 "~" H 4700 2650 50  0001 C CNN
	1    4700 2650
	1    0    0    -1  
$EndComp
Text Notes 2250 1300 0    100  ~ 0
Transmit Side
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5DDA1783
P 3450 1900
F 0 "J1" H 3400 2150 50  0000 L CNN
F 1 "Conn_01x03" H 3530 1851 50  0001 L CNN
F 2 "AirSensor_Local:SMD_3Pin" H 3450 1900 50  0001 C CNN
F 3 "~" H 3450 1900 50  0001 C CNN
	1    3450 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5DDA1969
P 4700 3150
F 0 "D5" H 4691 3366 50  0000 C CNN
F 1 "IR LED" H 4691 3275 50  0000 C CNN
F 2 "AirSensor_Local:LED_D5.0mm_FlatTop" H 4700 3150 50  0001 C CNN
F 3 "~" H 4700 3150 50  0001 C CNN
	1    4700 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5DDA19C8
P 4700 3650
F 0 "D4" H 4691 3866 50  0000 C CNN
F 1 "IR LED" H 4691 3775 50  0000 C CNN
F 2 "AirSensor_Local:LED_D5.0mm_FlatTop" H 4700 3650 50  0001 C CNN
F 3 "~" H 4700 3650 50  0001 C CNN
	1    4700 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5DDA1ADB
P 4700 4150
F 0 "D3" H 4691 4366 50  0000 C CNN
F 1 "IR LED" H 4691 4275 50  0000 C CNN
F 2 "AirSensor_Local:LED_D5.0mm_FlatTop" H 4700 4150 50  0001 C CNN
F 3 "~" H 4700 4150 50  0001 C CNN
	1    4700 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5DDA1AE2
P 4700 4650
F 0 "D2" H 4691 4866 50  0000 C CNN
F 1 "IR LED" H 4691 4775 50  0000 C CNN
F 2 "AirSensor_Local:LED_D5.0mm_FlatTop" H 4700 4650 50  0001 C CNN
F 3 "~" H 4700 4650 50  0001 C CNN
	1    4700 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5DDA1AE9
P 4700 5150
F 0 "D1" H 4691 5366 50  0000 C CNN
F 1 "IR LED" H 4691 5275 50  0000 C CNN
F 2 "AirSensor_Local:LED_D5.0mm_FlatTop" H 4700 5150 50  0001 C CNN
F 3 "~" H 4700 5150 50  0001 C CNN
	1    4700 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 3150 2200 3150
Wire Wire Line
	2200 3150 2200 2850
Wire Wire Line
	2400 4150 2200 4150
Wire Wire Line
	2200 4150 2200 3850
Wire Wire Line
	3050 2000 3250 2000
Wire Wire Line
	3250 1900 2950 1900
Wire Wire Line
	3250 1800 2850 1800
Wire Wire Line
	2200 2850 3050 2850
Wire Wire Line
	2200 3850 3050 3850
Wire Wire Line
	2650 2650 3050 2650
Wire Wire Line
	2650 3650 3050 3650
Wire Wire Line
	2400 2650 2200 2650
Wire Wire Line
	2200 2650 2200 2350
Wire Wire Line
	2200 2350 2850 2350
Wire Wire Line
	2650 3150 2850 3150
Wire Wire Line
	2400 3650 2200 3650
Wire Wire Line
	2200 3650 2200 3350
Wire Wire Line
	2200 3350 2950 3350
Wire Wire Line
	2650 4150 2950 4150
Wire Wire Line
	2650 4650 2950 4650
Wire Wire Line
	2650 5150 2850 5150
Wire Wire Line
	2400 4650 2200 4650
Wire Wire Line
	2200 4650 2200 4350
Wire Wire Line
	2200 4350 2850 4350
Wire Wire Line
	2400 5150 2200 5150
Wire Wire Line
	2200 5150 2200 4850
Wire Wire Line
	2200 4850 2950 4850
Text Notes 3550 1800 0    50   ~ 0
LED0
Text Notes 3550 1900 0    50   ~ 0
LED1
Text Notes 3550 2000 0    50   ~ 0
LED2
Text Notes 6000 1800 2    50   ~ 0
AIR0
Text Notes 6000 1900 2    50   ~ 0
AIR1
Text Notes 6000 2000 2    50   ~ 0
AIR2
Text Notes 6000 2100 2    50   ~ 0
AIR3
Text Notes 6000 2200 2    50   ~ 0
AIR4
$Comp
L Connector_Generic:Conn_01x07 J2
U 1 1 5DDAC609
P 6100 2000
F 0 "J2" H 6050 2450 50  0000 L CNN
F 1 "Conn_01x07" H 6180 1951 50  0001 L CNN
F 2 "AirSensor_Local:SMD_7Pin" H 6100 2000 50  0001 C CNN
F 3 "~" H 6100 2000 50  0001 C CNN
	1    6100 2000
	-1   0    0    -1  
$EndComp
Text Notes 6000 2300 2    50   ~ 0
AIR5
Text Notes 6000 1700 2    50   ~ 0
3V3
Wire Wire Line
	6300 2300 6400 2300
Wire Wire Line
	6400 2300 6400 2650
Wire Wire Line
	6400 2650 7100 2650
Wire Wire Line
	6300 2200 6500 2200
Wire Wire Line
	6500 2200 6500 3150
Wire Wire Line
	6500 3150 7100 3150
Wire Wire Line
	6300 2100 6600 2100
Wire Wire Line
	6600 2100 6600 3650
Wire Wire Line
	6600 3650 7100 3650
Wire Wire Line
	6300 2000 6700 2000
Wire Wire Line
	6700 2000 6700 4150
Wire Wire Line
	6700 4150 7100 4150
Wire Wire Line
	6300 1900 6800 1900
Wire Wire Line
	6800 1900 6800 4650
Wire Wire Line
	6800 4650 7100 4650
Wire Wire Line
	6300 1800 6900 1800
Wire Wire Line
	6900 1800 6900 5150
Wire Wire Line
	6900 5150 7100 5150
Wire Wire Line
	6300 1700 7650 1700
Wire Wire Line
	7650 5150 7350 5150
Wire Wire Line
	7350 4650 7650 4650
Wire Wire Line
	7350 4150 7650 4150
Wire Wire Line
	7350 3650 7650 3650
Wire Wire Line
	7350 3150 7650 3150
Wire Wire Line
	7350 2650 7650 2650
Text Notes 6300 1300 0    100  ~ 0
Receive Side
Connection ~ 7650 2650
Connection ~ 7650 3150
Wire Wire Line
	7650 3150 7650 3650
Wire Wire Line
	7650 3650 7650 4150
Connection ~ 7650 3650
Connection ~ 7650 4150
Wire Wire Line
	7650 2650 7650 3150
Wire Wire Line
	7650 1700 7650 2650
Wire Wire Line
	7650 4150 7650 4650
Wire Wire Line
	7650 4650 7650 5150
Connection ~ 7650 4650
Wire Wire Line
	4550 3150 4350 3150
Wire Wire Line
	4550 4150 4350 4150
Wire Wire Line
	4550 2650 4350 2650
Wire Wire Line
	4550 3650 4350 3650
Wire Wire Line
	4550 4650 4350 4650
Wire Wire Line
	4550 5150 4350 5150
Text Label 4400 2650 0    50   ~ 0
D6-
Text Label 4400 3150 0    50   ~ 0
D5-
Text Label 4400 3650 0    50   ~ 0
D4-
Text Label 4400 4150 0    50   ~ 0
D3-
Text Label 4400 4650 0    50   ~ 0
D2-
Text Label 4400 5150 0    50   ~ 0
D1-
Connection ~ 2950 4650
Wire Wire Line
	2950 4650 2950 4850
Wire Wire Line
	2950 4150 2950 4650
Connection ~ 2950 4150
Connection ~ 2850 3150
Connection ~ 3050 2650
Wire Wire Line
	3050 2650 3050 2000
Wire Wire Line
	3050 3650 3050 3850
Connection ~ 3050 3650
Wire Wire Line
	3050 2850 3050 3650
Wire Wire Line
	3050 2650 3050 2850
Wire Wire Line
	2850 1800 2850 2350
Wire Wire Line
	2850 2350 2850 3150
Connection ~ 2850 2350
Wire Wire Line
	2950 1900 2950 3350
Wire Wire Line
	2950 3350 2950 4150
Connection ~ 2850 4350
Wire Wire Line
	2850 3150 2850 4350
Wire Wire Line
	2850 4350 2850 5150
Connection ~ 2950 3350
Connection ~ 3050 2850
Wire Wire Line
	4850 2650 5050 2650
Wire Wire Line
	4850 3650 5050 3650
Wire Wire Line
	4850 3150 5050 3150
Wire Wire Line
	4850 4150 5050 4150
Wire Wire Line
	4850 4650 5050 4650
Wire Wire Line
	4850 5150 5050 5150
Text Label 4850 5150 0    50   ~ 0
D1+
Text Label 4850 4650 0    50   ~ 0
D2+
Text Label 4850 4150 0    50   ~ 0
D3+
Text Label 4850 3650 0    50   ~ 0
D4+
Text Label 4850 3150 0    50   ~ 0
D5+
Text Label 4850 2650 0    50   ~ 0
D6+
Text Label 6950 2650 0    50   ~ 0
D1+
Text Label 6950 3150 0    50   ~ 0
D2+
Text Label 6950 3650 0    50   ~ 0
D3+
Text Label 6950 4150 0    50   ~ 0
D4+
Text Label 6950 4650 0    50   ~ 0
D5+
Text Label 6950 5150 0    50   ~ 0
D6+
Text Label 7400 2650 0    50   ~ 0
D6-
Text Label 7400 3150 0    50   ~ 0
D5-
Text Label 7400 3650 0    50   ~ 0
D4-
Text Label 7400 4150 0    50   ~ 0
D3-
Text Label 7400 4650 0    50   ~ 0
D2-
Text Label 7400 5150 0    50   ~ 0
D1-
$Comp
L Mechanical:MountingHole MH2
U 1 1 5DDF80B5
P 10300 1250
F 0 "MH2" H 10400 1296 50  0000 L CNN
F 1 "MountingHole" H 10400 1205 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_3.2mm_M3_ISO14580" H 10300 1250 50  0001 C CNN
F 3 "~" H 10300 1250 50  0001 C CNN
	1    10300 1250
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole MH1
U 1 1 5DDFB9B2
P 10300 900
F 0 "MH1" H 10400 946 50  0000 L CNN
F 1 "MountingHole" H 10400 855 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_3.2mm_M3_ISO14580" H 10300 900 50  0001 C CNN
F 3 "~" H 10300 900 50  0001 C CNN
	1    10300 900 
	1    0    0    -1  
$EndComp
$EndSCHEMATC
