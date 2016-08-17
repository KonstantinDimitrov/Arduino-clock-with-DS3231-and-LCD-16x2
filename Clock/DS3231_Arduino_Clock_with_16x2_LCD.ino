// Date and time functions using RX8025 RTC connected via I2C and Wire lib

#include <Wire.h>

#include "Sodaq_DS3231.h"
#include <LiquidCrystal.h>

 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char timebuf[20];       // Time
char datebuf[20];       // Date
int year2digit;         // 2 digit year



void setup () 
{
    Serial.begin(57600);
    Wire.begin();
    rtc.begin();
    lcd.begin(16, 2);
}



void loop () 
{
    DateTime now = rtc.now(); //get the current date-time
   
	Serial.print(timebuf);
	Serial.println();
	Serial.print(datebuf);
	
	
 
  lcd.setCursor(0,1);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(timebuf);
  
  lcd.setCursor(3,1);
  lcd.print(datebuf);
  
rtc.convertTemperature();
  lcd.setCursor(10,0);
  lcd.print(rtc.getTemperature());
  lcd.print("C");
  
sprintf(datebuf, "%02d|%02d|%02d",now.date(), now.month(), (now.year()));
sprintf(timebuf, "%02d:%02d:%02d", now.hour(), now.minute(), now.second()); // format time
delay(1000);   
}
