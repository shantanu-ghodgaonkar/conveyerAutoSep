#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX
 
void setup()
{
  Serial.begin(9600);  
  mySerial.begin(9600); // set the data rate for the SoftwareSerial port
}
 
void loop()
{
  if (mySerial.available()) // Check if there is Incoming Data in the Serial Buffer.
  { Serial.println("Serial Available!");
    while (mySerial.available()) // Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      Serial.print(mySerial.readString()); // Print the Byte
      delay(5); // A small delay
    }
    Serial.println();
  }
}