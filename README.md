# Arduino Pro Mini Redox-Potential-Datalogger
A low-power redox potential and temperature datalogger based on the Arduino Pro Mini. Desinged to run unsupervised for durations of ~14 days. 

## Construction 
Required Components:
Component | Quantity | Product Link
---|---|---
Arduino Pro Mini 8MHz | 1 | https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardProMini
Adafruit RTC DS3231 | 1 |  https://www.adafruit.com/product/3013
Adafruit microSD Card Module | 1 | https://www.adafruit.com/product/254
Gravity ORP Sensor | 4 | https://atlas-scientific.com/embedded-solutions/orp-sensor-meter/
Gravity ORP Probe | 4 | https://atlas-scientific.com/probes/consumer-grade-orp-probe/
DS18B20 Waterproof Temperature Sensor | 4 | https://amzn.to/3keA4Po
Perma-proto Half Sized Breadboard | 1 | https://bit.ly/3kfBTf6
CR1220 Coin Cell Battery | 1 | https://bit.ly/2DmNJ6x

## Assemble Board

Component | Pin | Board Position
--- | --- | ---
Arduino Pro Mini | DP0 | D1
Arduino Pro Mini | DP1 | D2
Arduino Pro Mini | RESET | D3
Arduino Pro Mini | GND | D4
Arduino Pro Mini | DP2 | D5
Arduino Pro Mini | DP3 | D6
Arduino Pro Mini | DP4 | D7
Arduino Pro Mini | DP5 | D8
Arduino Pro Mini | DP6 | D9
Arduino Pro Mini | DP7 | D10
Arduino Pro Mini | DP8 | D11
Arduino Pro Mini | DP9 | D12
Arduino Pro Mini | DP10 | H12
Arduino Pro Mini | DP11 | H11
Arduino Pro Mini | DP12 | H10
Arduino Pro Mini | DP13 | H9
Arduino Pro Mini | A0 | H8
Arduino Pro Mini | A1 | H7
Arduino Pro Mini | A2 | H6
Arduino Pro Mini | A3 | H5
Arduino Pro Mini | A4/SDA | I45 
Arduino Pro Mini | A5/SCL | I44
Arduino Pro Mini | A6 | Blank
Arduino Pro Mini | A7 | Blank
Arduino Pro Mini | 3V3 | H4
Arduino Pro Mini | RESET | H3
Arduino Pro Mini | GND | H2
Arduino Pro Mini | RAW | H1
Adafruit RTC DS3231 | Vin |
Adafruit RTC DS3231 | GND |
Adafruit RTC DS3231 | SCL |
Adafruit RTC DS3231 | SDA |
Adafruit RTC DS3231 | BAT |
Adafruit RTC DS3231 | 32K |
Adafruit RTC DS3231 | SQW |
Adafruit RTC DS3231 | RST |
Adafruit microSD Card Module | 5V |
Adafruit microSD Card Module | 3V |
Adafruit microSD Card Module | GND |
Adafruit microSD Card Module | CLK |
Adafruit microSD Card Module | DO |
Adafruit microSD Card Module | DI |
Adafruit microSD Card Module | CS |
Adafruit microSD Card Module | CD |

 Component | Board Position 1 | Board Position 2
 ---|---|---
 Black Wire 1 | Ground 3 | B3 
 | |
 | |
 | |
 | |
 | |
 | |

