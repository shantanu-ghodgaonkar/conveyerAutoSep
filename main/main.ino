#include <SoftwareSerial.h>
#include <string.h>
#include <ParallaxLCD.h>
#include <Servo.h>

// Pins
#define PINGSENSOR 7  // PING Sensor on Pin 7
#define DCMRELAY 8    // DC Motor relay on Pin 8
#define TOPSERVO 10   // Top Mounted Servo on Pin 10
#define BOTSERVO 9    // Bottom Mounted Servo on Pin 9
#define LCD 2         // LCD on Pin 2
#define BCSTX 3       // Barcode Scanner Transmitter
#define BCSRX 4       // Barcode Scanner Receiver

// LCD Constants
#define ROWS 2        // Number of rows in LCD
#define COLS 16       // Number of columns in LCD

// Servo motor Constants
#define BOTSERVOHOME 90   // Bottom Servo Home Angle
#define TOPSERVOHOME 94   // Top Servo Home Angle
#define SERVOOFFSET 30    // Servo Offset Angle

SoftwareSerial barcodeScanner(BCSTX, BCSRX); // Declare Barcode Scanner as a serial device
ParallaxLCD lcd(LCD,ROWS,COLS); // Declare Parallax LCD as a serial device
Servo botServo; // Declare bottom servo
Servo topServo; // Declare top servo
long distance = 0; // Variable to store output of PING sensor in cm
String barcode = "NONE";  // Variable to store scanned barcode

void setup() {
  botServo.attach(BOTSERVO); // Attach bottom servo to pin 9
  topServo.attach(TOPSERVO); // Attach top servo to pin 10
  botServo.write(BOTSERVOHOME); // Set bottom servo to home configuration
  topServo.write(TOPSERVOHOME); // Set top servo to home configuration
  lcd.setup(); // setup LCD
  lcd.backLightOn(); // Switch on LCD backlight
  lcd.empty(); // Clear LCD Screen
  pinMode(DCMRELAY, OUTPUT); // Set DC motor Relay pin as output
  digitalWrite(DCMRELAY, HIGH); // Switch on DC motor
  Serial.begin(9600); // Start serial communication
  // barcodeScanner.begin(115200);
}

void loop() {
  lcd.empty(); // Clear LCD Screen
  distance = runPINGSensor(); // Get PING Sensor reading
  // Serial.print("CM = ");
  // Serial.println(distance);
  if(distance < 10){ // If distance is less than 10 cm, package is in postion to be scanned
    digitalWrite(DCMRELAY, LOW); // Switch off motor; switch on barcode scanner
    // barcode = scanBarcode(); // Scan barcode
    lcd.print("Scanned Barcode: "); // Display scanned barcode on LCD
    lcd.print(barcode);
    digitalWrite(DCMRELAY, HIGH); // Switch on DC motor; switch off barcode scanner
    delay(1000); // Wait for package to fall on turntable
    if(barcode.substring(0,3) == "212") botServo.write(BOTSERVOHOME - SERVOOFFSET); // Check for first area and rotate servos accordingly
    else if (barcode.substring(0,3) == "929") botServo.write(BOTSERVOHOME + SERVOOFFSET); // Check for second area and rotate servos accordingly
    else if (barcode.substring(0,3) == "718") topServo.write(TOPSERVOHOME + SERVOOFFSET); // Check for third area and rotate servos accordingly
    delay(1000); // Allow 1s of delay for package to fall into right box
    botServo.write(BOTSERVOHOME); // Bring bottom servo back to home
    topServo.write(TOPSERVOHOME); // Bring top servo back to home
  }
}


long runPINGSensor() { // This function is responsible to get sensordata from PING sensor 
 // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(PINGSENSOR, OUTPUT);
  digitalWrite(PINGSENSOR, LOW);
  delayMicroseconds(2);
  digitalWrite(PINGSENSOR, HIGH);
  delayMicroseconds(5);
  digitalWrite(PINGSENSOR, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(PINGSENSOR, INPUT);
  return pulseIn(PINGSENSOR, HIGH) / 29 / 2;
}

String scanBarcode() { // This function is responsible to get the scanned barcode in string form
  barcodeScanner.begin(115200);
  if (barcodeScanner.available()) // Check if there is Incoming Data in the Serial Buffer.
  { Serial.println("Barcode scanner has data!");
    while (barcodeScanner.available()) // Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {return barcodeScanner.readString();}
  }
  barcodeScanner.end();
}

