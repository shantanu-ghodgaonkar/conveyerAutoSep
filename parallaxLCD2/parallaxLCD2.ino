#include <ParallaxLCD.h>

// Change these values if you're using the 4x20 LCD
#define ROWS 2
#define COLS 16

ParallaxLCD lcd(2,ROWS,COLS); // desired pin, rows, cols

void setup () {

  lcd.setup();
  lcd.backLightOn();
  lcd.empty();
  Serial.begin(9600);
}
void loop () {
  Serial.println("LCD SETUP BEGIN");
  lcd.setup();
  lcd.backLightOn();
  lcd.empty();
  Serial.println("LCD COMMS STARTED");
  delay(1000);
  lcd.print("Scanned Barcode: ");
  lcd.print("212-11219");
  delay(3000);
  // lcd.empty();
  lcd.end();
  Serial.println("LCD COMMS ENDED");
  delay(3000);
}
