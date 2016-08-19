#include <Wire.h>	  //TWI library
#include "Sodaq_DS3231.h" //DS3231 lib by Sodaq
#include <LiquidCrystal.h>//LCD library
/***************************************/
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/***************************************/
char timebuf[20];       // Time
char datebuf[20];       // Date
/**************************************/
void setup () 
{
    Serial.begin(57600); //init serial com
    Wire.begin();        //init TWI interface
    rtc.begin();	 //init RTC module
    lcd.begin(16, 2);    //init LCD
}

void loop () 
{
    DateTime now = rtc.now();  //get the current date-time
    rtc.convertTemperature();  //read temperature from the RTC
/*****************************************/	
	Serial.print(timebuf);
	Serial.println();
	Serial.print(datebuf);
	Serial.println();
	Serial.print(rtc.getTemperature)
/****************************************/	
  lcd.setCursor(0,1);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print(timebuf); //Display time
  
  lcd.setCursor(3,1);
  lcd.print(datebuf); //Display date
  
  lcd.setCursor(10,0);
  lcd.print(rtc.getTemperature()); //Display temp readings in Celsius
  lcd.print("C");
  
sprintf(datebuf, "%02d|%02d|%02d",now.date(), now.month(), (now.year()));   // format date
sprintf(timebuf, "%02d:%02d:%02d", now.hour(), now.minute(), now.second()); // format time
delay(1000);   
}
