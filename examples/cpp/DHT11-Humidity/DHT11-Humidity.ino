/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <DHT11.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT11 dht11(A0);//??
void setup() {
  // Initialize serial communication to allow debugging and data readout.
    // Using a baud rate of 9600 bps.
    Serial.begin(9600);
    lcd.begin(16, 2);

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // Attempt to read the humidity value from the DHT11 sensor.
    int humidity = dht11.readHumidity();

    // Check the result of the reading.
    // If there's no error, print the humidity value.
    // If there's an error, print the appropriate error message.
    if (humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT)
    {
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
        lcd.print("Humidity : " ); 
        lcd.print(humidity );
        lcd.print("%" );

    }
    else
    {
        Serial.println(DHT11::getErrorString(humidity));
        lcd.print("Humidity : " ); 
        lcd.print(humidity );
        lcd.print("%" );
       
    }

    // Wait for 1 seconds before the next reading.
    delay(1000);
    lcd.clear();

  // lcd.setCursor(0, 1);
  // // print the number of seconds since reset:
  // lcd.print(millis() / 1000);
}

