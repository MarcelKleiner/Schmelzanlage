EESchema Schematic File Version 4
LIBS:LCD_F303Nucleo-cache
EELAYER 29 0
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
L Connector_Generic:Conn_01x22 J2
U 1 1 5EE0E1F3
P 2950 6550
F 0 "J2" V 3075 6496 50  0000 C CNN
F 1 "Conn_01x22" V 3166 6496 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x22_P2.54mm_Vertical" H 2950 6550 50  0001 C CNN
F 3 "~" H 2950 6550 50  0001 C CNN
	1    2950 6550
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 1950 2200 2350
Wire Wire Line
	2400 1950 2400 2350
Wire Wire Line
	2600 1950 2600 2350
Wire Wire Line
	2800 1950 2800 2350
Wire Wire Line
	3000 1950 3000 2350
Wire Wire Line
	3200 1950 3200 2350
Wire Wire Line
	3600 1950 3600 2350
Wire Wire Line
	3800 1950 3800 2350
Wire Wire Line
	4000 1950 4000 2350
Wire Wire Line
	2300 1950 2300 2350
Wire Wire Line
	2500 1950 2500 2350
Wire Wire Line
	2700 1950 2700 2250
Wire Wire Line
	2900 1950 2900 2250
Wire Wire Line
	3100 1950 3100 2350
Wire Wire Line
	3300 1950 3300 2350
Wire Wire Line
	3500 1950 3500 2350
Wire Wire Line
	3700 1950 3700 2350
Wire Wire Line
	3900 1950 3900 2350
$Comp
L power:GND #PWR0101
U 1 1 5EE14EA1
P 2200 2350
F 0 "#PWR0101" H 2200 2100 50  0001 C CNN
F 1 "GND" H 2205 2177 50  0000 C CNN
F 2 "" H 2200 2350 50  0001 C CNN
F 3 "" H 2200 2350 50  0001 C CNN
	1    2200 2350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5EE15374
P 2300 2350
F 0 "#PWR0102" H 2300 2200 50  0001 C CNN
F 1 "+5V" H 2315 2523 50  0000 C CNN
F 2 "" H 2300 2350 50  0001 C CNN
F 3 "" H 2300 2350 50  0001 C CNN
	1    2300 2350
	-1   0    0    1   
$EndComp
Text Label 2500 2350 1    50   ~ 0
C_D
Text Label 2700 2250 1    50   ~ 0
WR
Text Label 3900 2350 1    50   ~ 0
MD2
Text Label 3700 2350 1    50   ~ 0
RESET
Text Label 2400 2350 1    50   ~ 0
V0
Text Label 2600 2350 1    50   ~ 0
RD
Text Label 4000 2350 1    50   ~ 0
FS
Text Label 3800 2350 1    50   ~ 0
VEE
Text Label 3600 2350 1    50   ~ 0
CE
Text Label 2800 2350 1    50   ~ 0
DB0
Text Label 2900 2250 1    50   ~ 0
DB1
Text Label 3000 2350 1    50   ~ 0
DB2
Text Label 3200 2350 1    50   ~ 0
DB4
Text Label 3100 2350 1    50   ~ 0
DB3
Text Label 3300 2350 1    50   ~ 0
DB5
Text Label 3500 2350 1    50   ~ 0
DB7
$Comp
L MK_Schnitstellen_IC:ST2378ETTR U1
U 1 1 5EE19C36
P 2650 4250
F 0 "U1" V 2671 3506 50  0000 R CNN
F 1 "ST2378ETTR" V 2580 3506 50  0000 R CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 2300 4950 50  0001 C CNN
F 3 "" H 2300 4950 50  0001 C CNN
	1    2650 4250
	1    0    0    -1  
$EndComp
$Comp
L LCD_F303Nucleo-rescue:MCP4541T-MK_Potentiometer U2
U 1 1 5EE1BA8C
P 6050 4500
F 0 "U2" H 6050 5181 50  0000 C CNN
F 1 "MCP4541T" H 6050 5090 50  0000 C CNN
F 2 "Package_SO:MSOP-8_3x3mm_P0.65mm" H 5200 5500 50  0001 C CNN
F 3 "" H 5200 5500 50  0001 C CNN
	1    6050 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4300 6950 4300
Wire Wire Line
	6650 4500 6950 4500
Wire Wire Line
	6650 4700 6800 4700
Text Label 6950 4300 2    50   ~ 0
VEE
Text Label 6950 4500 2    50   ~ 0
V0
Text Label 7000 4700 2    50   ~ 0
VSS
Wire Wire Line
	3350 6350 3350 5950
Wire Wire Line
	3850 6350 3850 5950
$Comp
L power:+3.3V #PWR0103
U 1 1 5EE21B17
P 3350 5950
F 0 "#PWR0103" H 3350 5800 50  0001 C CNN
F 1 "+3.3V" H 3200 6050 50  0000 C CNN
F 2 "" H 3350 5950 50  0001 C CNN
F 3 "" H 3350 5950 50  0001 C CNN
	1    3350 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5EE21DD8
P 3850 5950
F 0 "#PWR0104" H 3850 5800 50  0001 C CNN
F 1 "+5V" H 3950 6050 50  0000 C CNN
F 2 "" H 3850 5950 50  0001 C CNN
F 3 "" H 3850 5950 50  0001 C CNN
	1    3850 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 6350 3950 6200
Wire Wire Line
	3950 6200 4200 6200
Wire Wire Line
	4200 6200 4200 6300
$Comp
L power:GND #PWR0105
U 1 1 5EE22B8E
P 4200 6300
F 0 "#PWR0105" H 4200 6050 50  0001 C CNN
F 1 "GND" H 4205 6127 50  0000 C CNN
F 2 "" H 4200 6300 50  0001 C CNN
F 3 "" H 4200 6300 50  0001 C CNN
	1    4200 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5EE23291
P 6050 5050
F 0 "#PWR0106" H 6050 4800 50  0001 C CNN
F 1 "GND" H 6055 4877 50  0000 C CNN
F 2 "" H 6050 5050 50  0001 C CNN
F 3 "" H 6050 5050 50  0001 C CNN
	1    6050 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 5000 6050 5050
$Comp
L power:+3.3V #PWR0107
U 1 1 5EE243AB
P 6050 3750
F 0 "#PWR0107" H 6050 3600 50  0001 C CNN
F 1 "+3.3V" H 5900 3850 50  0000 C CNN
F 2 "" H 6050 3750 50  0001 C CNN
F 3 "" H 6050 3750 50  0001 C CNN
	1    6050 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3750 6050 3800
$Comp
L power:GND #PWR0108
U 1 1 5EE250F5
P 6800 4950
F 0 "#PWR0108" H 6800 4700 50  0001 C CNN
F 1 "GND" H 6805 4777 50  0000 C CNN
F 2 "" H 6800 4950 50  0001 C CNN
F 3 "" H 6800 4950 50  0001 C CNN
	1    6800 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 4950 6800 4700
Connection ~ 6800 4700
Wire Wire Line
	6800 4700 7000 4700
$Comp
L power:GND #PWR0109
U 1 1 5EE26F68
P 5350 4700
F 0 "#PWR0109" H 5350 4450 50  0001 C CNN
F 1 "GND" H 5355 4527 50  0000 C CNN
F 2 "" H 5350 4700 50  0001 C CNN
F 3 "" H 5350 4700 50  0001 C CNN
	1    5350 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4700 5350 4600
Wire Wire Line
	5350 4600 5450 4600
Wire Wire Line
	5450 4500 5000 4500
Wire Wire Line
	5450 4400 5300 4400
$Comp
L Device:R R2
U 1 1 5EE2A446
P 5300 4150
F 0 "R2" H 5370 4196 50  0000 L CNN
F 1 "4.7k" H 5370 4105 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5230 4150 50  0001 C CNN
F 3 "~" H 5300 4150 50  0001 C CNN
	1    5300 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5EE2A87E
P 5000 4150
F 0 "R1" H 5070 4196 50  0000 L CNN
F 1 "4.7k" H 5070 4105 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4930 4150 50  0001 C CNN
F 3 "~" H 5000 4150 50  0001 C CNN
	1    5000 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4300 5000 4500
Connection ~ 5000 4500
Wire Wire Line
	5000 4500 4750 4500
Wire Wire Line
	5300 4300 5300 4400
Connection ~ 5300 4400
Wire Wire Line
	5300 4400 5050 4400
Text Label 4750 4500 0    50   ~ 0
SDA
Text Label 5050 4400 0    50   ~ 0
SCL
$Comp
L power:+3.3V #PWR0110
U 1 1 5EE2D33F
P 5150 3800
F 0 "#PWR0110" H 5150 3650 50  0001 C CNN
F 1 "+3.3V" H 5000 3900 50  0000 C CNN
F 2 "" H 5150 3800 50  0001 C CNN
F 3 "" H 5150 3800 50  0001 C CNN
	1    5150 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3800 5150 3950
Wire Wire Line
	5000 4000 5000 3950
Wire Wire Line
	5000 3950 5150 3950
Wire Wire Line
	5150 3950 5300 3950
Wire Wire Line
	5300 3950 5300 4000
Connection ~ 5150 3950
$Comp
L Device:C C1
U 1 1 5EE31B30
P 6350 3800
F 0 "C1" V 6098 3800 50  0000 C CNN
F 1 "100n" V 6189 3800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6388 3650 50  0001 C CNN
F 3 "~" H 6350 3800 50  0001 C CNN
	1    6350 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 3800 6050 3800
Connection ~ 6050 3800
Wire Wire Line
	6050 3800 6050 4000
Wire Wire Line
	6500 3800 6750 3800
$Comp
L power:GND #PWR0111
U 1 1 5EE349B9
P 6750 3900
F 0 "#PWR0111" H 6750 3650 50  0001 C CNN
F 1 "GND" H 6755 3727 50  0000 C CNN
F 2 "" H 6750 3900 50  0001 C CNN
F 3 "" H 6750 3900 50  0001 C CNN
	1    6750 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3800 6750 3900
Wire Wire Line
	2550 3550 2550 3350
Wire Wire Line
	2750 3550 2750 3350
$Comp
L power:+3.3V #PWR0112
U 1 1 5EE3BAD7
P 2550 3350
F 0 "#PWR0112" H 2550 3200 50  0001 C CNN
F 1 "+3.3V" H 2400 3450 50  0000 C CNN
F 2 "" H 2550 3350 50  0001 C CNN
F 3 "" H 2550 3350 50  0001 C CNN
	1    2550 3350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0113
U 1 1 5EE3BADD
P 2750 3350
F 0 "#PWR0113" H 2750 3200 50  0001 C CNN
F 1 "+5V" H 2850 3450 50  0000 C CNN
F 2 "" H 2750 3350 50  0001 C CNN
F 3 "" H 2750 3350 50  0001 C CNN
	1    2750 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5EE3DF45
P 2650 5150
F 0 "#PWR0114" H 2650 4900 50  0001 C CNN
F 1 "GND" H 2655 4977 50  0000 C CNN
F 2 "" H 2650 5150 50  0001 C CNN
F 3 "" H 2650 5150 50  0001 C CNN
	1    2650 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5150 2650 4950
Wire Wire Line
	3100 4500 3450 4500
Wire Wire Line
	3100 4300 3450 4300
Wire Wire Line
	3100 4100 3450 4100
Wire Wire Line
	3100 3900 3450 3900
Wire Wire Line
	3100 4000 3450 4000
Wire Wire Line
	3100 4200 3450 4200
Wire Wire Line
	3100 4400 3450 4400
Wire Wire Line
	3100 4600 3450 4600
Wire Wire Line
	2150 3900 1850 3900
Wire Wire Line
	2150 4100 1850 4100
Wire Wire Line
	2150 4300 1850 4300
Wire Wire Line
	2150 4500 1850 4500
Wire Wire Line
	2150 4600 1850 4600
Wire Wire Line
	2150 4400 1850 4400
Wire Wire Line
	2150 4200 1850 4200
Wire Wire Line
	2150 4000 1850 4000
Wire Wire Line
	3100 4750 3450 4750
Text Label 3450 4750 2    50   ~ 0
OE
Text Label 3450 4500 2    50   ~ 0
DB0
Text Label 3450 4300 2    50   ~ 0
DB1
Text Label 3450 4100 2    50   ~ 0
DB2
Text Label 3450 3900 2    50   ~ 0
DB3
Text Label 3450 4000 2    50   ~ 0
DB4
Text Label 3450 4200 2    50   ~ 0
DB5
Text Label 3450 4400 2    50   ~ 0
DB6
Text Label 3450 4600 2    50   ~ 0
DB7
Text Label 1850 4500 0    50   ~ 0
IO_Vl1
Text Label 1850 4300 0    50   ~ 0
IO_Vl2
Text Label 1850 4100 0    50   ~ 0
IO_Vl3
Text Label 1850 3900 0    50   ~ 0
IO_Vl4
Text Label 1850 4000 0    50   ~ 0
IO_Vl5
Text Label 1850 4200 0    50   ~ 0
IO_Vl6
Text Label 1850 4400 0    50   ~ 0
IO_Vl7
Text Label 1850 4600 0    50   ~ 0
IO_Vl8
Wire Wire Line
	2550 6350 2550 6050
Wire Wire Line
	2450 6350 2450 6050
Wire Wire Line
	2350 6350 2350 6050
Wire Wire Line
	2250 6350 2250 6050
Wire Wire Line
	2950 6350 2950 6050
Wire Wire Line
	2850 6350 2850 6050
Wire Wire Line
	2750 6350 2750 6050
Wire Wire Line
	2650 6350 2650 6050
Text Label 2250 6050 3    50   ~ 0
IO_Vl1
Text Label 2350 6050 3    50   ~ 0
IO_Vl2
Text Label 2450 6050 3    50   ~ 0
IO_Vl3
Text Label 2550 6050 3    50   ~ 0
IO_Vl4
Text Label 2650 6050 3    50   ~ 0
IO_Vl5
Text Label 2750 6050 3    50   ~ 0
IO_Vl6
Text Label 2850 6050 3    50   ~ 0
IO_Vl7
Text Label 2950 6050 3    50   ~ 0
IO_Vl8
Wire Wire Line
	3050 6350 3050 6050
Text Label 3050 6050 3    50   ~ 0
OE
Wire Wire Line
	2150 6350 2150 6050
Wire Wire Line
	5200 6200 5200 5900
Wire Wire Line
	1850 6350 1850 6050
Text Label 1850 6050 3    50   ~ 0
FS
Text Label 5200 5900 3    50   ~ 0
VEE
Text Label 2150 6050 3    50   ~ 0
CE
Wire Wire Line
	2050 6350 2050 6050
Wire Wire Line
	1950 6350 1950 6050
Text Label 1950 6050 3    50   ~ 0
MD2
Text Label 2050 6050 3    50   ~ 0
RESET
Wire Wire Line
	3750 6350 3750 6050
Wire Wire Line
	3550 6350 3550 6050
Text Label 3750 6050 3    50   ~ 0
C_D
Text Label 3550 6050 3    50   ~ 0
WR
Wire Wire Line
	3650 6350 3650 6050
Text Label 3650 6050 3    50   ~ 0
RD
Wire Wire Line
	3150 6350 3150 6050
Wire Wire Line
	3250 6350 3250 6050
Text Label 3150 6050 3    50   ~ 0
SCL
Text Label 3250 6050 3    50   ~ 0
SDA
$Comp
L Connector_Generic:Conn_01x20 J1
U 1 1 5EE85AF5
P 3100 1750
F 0 "J1" V 3317 1696 50  0000 C CNN
F 1 "Conn_01x20" V 3226 1696 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 3100 1750 50  0001 C CNN
F 3 "~" H 3100 1750 50  0001 C CNN
	1    3100 1750
	0    -1   -1   0   
$EndComp
Text Label 3400 2350 1    50   ~ 0
DB6
Wire Wire Line
	3400 1950 3400 2350
NoConn ~ 4100 1950
$Comp
L power:GND #PWR0115
U 1 1 5EF627EF
P 3450 6250
F 0 "#PWR0115" H 3450 6000 50  0001 C CNN
F 1 "GND" H 3455 6077 50  0000 C CNN
F 2 "" H 3450 6250 50  0001 C CNN
F 3 "" H 3450 6250 50  0001 C CNN
	1    3450 6250
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 6250 3450 6350
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5EE4203A
P 4600 1750
F 0 "J3" V 4564 1562 50  0000 R CNN
F 1 "Conn_01x02" V 4473 1562 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4600 1750 50  0001 C CNN
F 3 "~" H 4600 1750 50  0001 C CNN
	1    4600 1750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5EE429B8
P 4700 2100
F 0 "#PWR0116" H 4700 1850 50  0001 C CNN
F 1 "GND" H 4850 2000 50  0000 C CNN
F 2 "" H 4700 2100 50  0001 C CNN
F 3 "" H 4700 2100 50  0001 C CNN
	1    4700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2100 4700 1950
$Comp
L power:+3.3V #PWR0117
U 1 1 5EE4832B
P 4600 2100
F 0 "#PWR0117" H 4600 1950 50  0001 C CNN
F 1 "+3.3V" H 4750 2200 50  0000 C CNN
F 2 "" H 4600 2100 50  0001 C CNN
F 3 "" H 4600 2100 50  0001 C CNN
	1    4600 2100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 2100 4600 1950
$EndSCHEMATC
