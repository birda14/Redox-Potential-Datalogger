// Include Required Libraries
#include <SPI.h>               //Library for SPI interface
#include <RTClib.h>            //Library for Real Time Clock RTC_DS3231
#include <avr/sleep.h>         //AVR library for controlling sleep modes
#include <SD.h>                //Library for SD card Logger
#include <OneWire.h>           //OneWire Interface for DS18B20 Temperature Sensor
#include <DallasTemperature.h> //Library for DS18B20 Temperature Sensor
#include <base_grav.h>         //Library for base Atlas gravity sensors
#include <orp_grav.h>          //Library for oxidation-reduction potential sensors 

//-------------------------------------------------------------------------

//Configuration for RTC, SD card, OPR Sensors, and Temp Sensors
 
  RTC_DS3231 rtc;                      //Setup real time clock
  const int alarmPin = 2;              // The number of the pin for monitoring alarm status on DS3231
  
  const int pinCS = 10;                //Set up logging sheild 10 for the SD cs line
  
  #define ONE_WIRE_BUS 9               //One wire bus on digital pin 9
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature sensors(&oneWire);

  Gravity_ORP ORP1 = Gravity_ORP(A0);  //Define OPR probe on pin A0
  Gravity_ORP ORP2 = Gravity_ORP(A1);  //Define OPR probe on pin A1
  Gravity_ORP ORP3 = Gravity_ORP(A2);  //Define OPR probe on pin A2
  Gravity_ORP ORP4 = Gravity_ORP(A3);  //Define OPR probe on pin A3
  
  //DeviceAddress probe1 = { 0x28, 0x77, 0x17, 0x76, 0xE0, 0x01, 0x3C, 0x91 };  //WL1 Store onewire bus address to variable probe1
  //DeviceAddress probe2 = { 0x28, 0x07, 0xEC, 0x76, 0xE0, 0xFF, 0x3C, 0x9A };  //WL1 Store onewire bus address to variable probe2
  //DeviceAddress probe3 = { 0x28, 0xCC, 0x27, 0x95, 0xF0, 0x01, 0x3C, 0x61 };  //WL1 Store onewire bus address to variable probe3
  //DeviceAddress probe4 = { 0x28, 0x94, 0xB8, 0x76, 0xE0, 0x01, 0x3C, 0xBD };  //WL1 Store onewire bus address to variable probe4

  DeviceAddress probe1 = { 0x28, 0x66, 0x7B, 0x76, 0xE0, 0x01, 0x3C, 0xCD };  //WL2 Store onewire bus address to variable probe1
  DeviceAddress probe2 = { 0x28, 0xD9, 0x86, 0x76, 0xE0, 0x01, 0x3C, 0xA4 };  //WL2 Store onewire bus address to variable probe2
  DeviceAddress probe3 = { 0x28, 0x1D, 0x83, 0x76, 0xE0, 0x01, 0x3C, 0x35 };  //WL2 Store onewire bus address to variable probe3
  DeviceAddress probe4 = { 0x28, 0x1E, 0x5B, 0x76, 0xE0, 0x01, 0x3C, 0x0C };  //WL2 Store onewire bus address to variable probe4

  //DeviceAddress probe1 = { 0x28, 0x82, 0xA4, 0x76, 0xE0, 0x01, 0x3C, 0x09 };  //WL3 Store onewire bus address to variable probe1
  //DeviceAddress probe2 = { 0x28, 0x68, 0x93, 0x76, 0xE0, 0x01, 0x3C, 0x3A };  //WL3 Store onewire bus address to variable probe2
  //DeviceAddress probe3 = { 0x28, 0x6B, 0xCE, 0x76, 0xE0, 0x01, 0x3C, 0x1A };  //WL3 Store onewire bus address to variable probe3
  //DeviceAddress probe4 = { 0x28, 0x37, 0x3A, 0x76, 0xE0, 0x01, 0x3C, 0xF0 };  //WL3 Store onewire bus address to variable probe4

  //DeviceAddress probe1 = { 0x28, 0x82, 0x58, 0x76, 0xE0, 0x01, 0x3C, 0x8E };  //WL5 Store onewire bus address to variable probe1
  //DeviceAddress probe2 = { 0x28, 0xC4, 0x61, 0x76, 0xE0, 0x01, 0x3C, 0x3E };  //WL5 Store onewire bus address to variable probe2
  //DeviceAddress probe3 = { 0x28, 0xF5, 0x56, 0x76, 0xE0, 0x01, 0x3C, 0x31 };  //WL5 Store onewire bus address to variable probe3
  //DeviceAddress probe4 = { 0x28, 0xBE, 0x32, 0x76, 0xE0, 0x01, 0x3C, 0xB2 };  //WL5 Store onewire bus address to variable probe4

  //DeviceAddress probe1 = { 0x28, 0xB7, 0x4C, 0x76, 0xE0, 0x01, 0x3C, 0xEB };  //WL6 Store onewire bus address to variable probe1
  //DeviceAddress probe2 = { 0x28, 0xB2, 0x67, 0x56, 0xB5, 0x01, 0x3C, 0xB6 };  //WL6 Store onewire bus address to variable probe2
  //DeviceAddress probe3 = { 0x28, 0xEA, 0x8A, 0x95, 0xF0, 0x01, 0x3C, 0xBA };  //WL6 Store onewire bus address to variable probe3
  //DeviceAddress probe4 = { 0x28, 0xCC, 0x56, 0x76, 0xE0, 0x01, 0x3C, 0x4A };  //WL6 Store onewire bus address to variable probe4

  //DeviceAddress probe1 = { 0x28, 0x79, 0x0B, 0x95, 0xF0, 0x01, 0x3C, 0x54 };  //WL7 Store onewire bus address to variable probe1
  //DeviceAddress probe2 = { 0x28, 0x9B, 0xE9, 0x76, 0xE0, 0x01, 0x3C, 0xC1 };  //WL7 Store onewire bus address to variable probe2
  //DeviceAddress probe3 = { 0x28, 0x6D, 0xF9, 0x95, 0xF0, 0x01, 0x3C, 0xF6 };  //WL7 Store onewire bus address to variable probe3
  //DeviceAddress probe4 = { 0x28, 0x9F, 0x12, 0x95, 0xF0, 0x01, 0x3C, 0x40 };  //WL7 Store onewire bus address to variable probe4
  
  
  float Celsius1 = sensors.getTempC(probe1);
  float Celsius2 = sensors.getTempC(probe2);
  float Celsius3 = sensors.getTempC(probe3);
  float Celsius4 = sensors.getTempC(probe4);
  
//------------------------------------------------------------------------- 
 
void setup() {
  Serial.begin(9600);
  rtc.begin(); //Start real time clock
  pinMode(alarmPin, INPUT_PULLUP); // Set alarm pin as pullup
  SD.begin(pinCS); //Start SD card
  Serial.println("RTC and SD Card started");
  
  // Disable and clear both alarms
  rtc.disableAlarm(1);
  rtc.disableAlarm(2);
  rtc.clearAlarm(1);
  rtc.clearAlarm(2);

  rtc.writeSqwPinMode(DS3231_OFF); // Place SQW pin into alarm interrupt mode
   Serial.println("Setup Loop Complete");
}

void loop() {
  DateTime now = rtc.now();                                   //Get current time at start of loop
  rtc.setAlarm1(now + TimeSpan(0, 1, 0, 0),DS3231_A1_Hour);   //Wakeup Interval - 1 hour
  Serial.println("Left Loop");                                //Message for debugging
  File dataFile = SD.open("wl2log.csv", FILE_WRITE);          //Opens or creates file on SD card

  sensors.begin();                                            //Activate and poll the Temp sensors
  sensors.requestTemperatures();
  delay(1000);
  
  //Main logging function
  if (dataFile) {
    dataFile.print("WL2"); //Edit to change site information 
    dataFile.print(",");
    dataFile.print(now.year(), DEC);
    dataFile.print("/");
    dataFile.print(now.month(), DEC);
    dataFile.print("/");
    dataFile.print(now.day(), DEC);
    dataFile.print(",");
    dataFile.print(now.hour(), DEC);
    dataFile.print(":");
    dataFile.print(now.minute(), DEC);
    dataFile.print(":");
    dataFile.print(now.second(), DEC);
    dataFile.print(",");
    dataFile.print((int)ORP1.read_orp());       //OPR Probe 1       
    dataFile.print(",");
    dataFile.print((int)ORP2.read_orp());       //OPR Probe 2
    dataFile.print(",");
    dataFile.print((int)ORP3.read_orp());       //OPR Probe 3
    dataFile.print(",");
    dataFile.print((int)ORP4.read_orp());       //OPR Probe 4
    dataFile.print(",");
    dataFile.print(Celsius1);       //Temperature Probe 1
    dataFile.print(",");
    dataFile.print(Celsius2);       //Temperature Probe 2
    dataFile.print(",");
    dataFile.print(Celsius3);       //Temperature Probe 3
    dataFile.print(",");
    dataFile.print(Celsius4);       //Temperature Probe 4   
    dataFile.println();
    dataFile.close();

    Serial.println("Logging");
    Serial.println((int)ORP1.read_orp());
    Serial.println((int)ORP2.read_orp());
    Serial.println((int)ORP3.read_orp());
    Serial.println((int)ORP4.read_orp());
    Serial.println(Celsius1);
    Serial.println(Celsius2);
    Serial.println(Celsius3);
    Serial.println(Celsius4);
       
    enterSleep();  // Go to sleep
    
 }
  
}

void enterSleep(){
  sleep_enable();                       // Enabling sleep mode
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // Setting the sleep mode, in this case full sleep
  
  noInterrupts();                       // Disable interrupts
  attachInterrupt(digitalPinToInterrupt(alarmPin), alarm_ISR, LOW);
  
  Serial.println("Going to sleep!");    // Print message to serial monitor
  Serial.flush();                       // Ensure all characters are sent to the serial monitor
  
  interrupts();                         // Allow interrupts again
  sleep_cpu();                          // Enter sleep mode

  /* The program will continue from here when it wakes */
  
  // Disable and clear alarm
  rtc.disableAlarm(1);
  rtc.clearAlarm(1);
  
  Serial.println("I'm back!");          // Print message to show we're back
 }

void alarm_ISR() {                      
  // This runs when SQW pin is low. It will wake up the µController
  sleep_disable(); // Disable sleep mode
  detachInterrupt(digitalPinToInterrupt(alarmPin)); // Detach the interrupt to stop it firing
}
