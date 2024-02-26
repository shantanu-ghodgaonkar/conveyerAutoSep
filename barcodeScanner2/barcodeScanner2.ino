#include <SoftwareSerial.h>
SoftwareSerial barcodeScanner(3, 4); // RX, TX
 
void setup()
{
  Serial.begin(9600);  
  // barcodeScanner.begin(9600); // set the data rate for the SoftwareSerial port
}
 
unsigned long previousMillis = millis();
unsigned long interval = 4000;
void loop()
{ 
  unsigned long currentMillis = millis();
  barcodeScanner.begin(9600);
  while(currentMillis - previousMillis < interval){
  if (barcodeScanner.available()) // Check if there is Incoming Data in the Serial Buffer.
  { Serial.println("Serial Available!");
    while (barcodeScanner.available()) // Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      Serial.print(barcodeScanner.readString()); // Print the Byte
      delay(5); // A small delay
    }
    Serial.println();
  }
  }
  barcodeScanner.end();
}