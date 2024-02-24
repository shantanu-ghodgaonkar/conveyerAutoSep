/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo botServo;
Servo topServo;

int pos = 0;    // variable to store the servo position

void setup() {
  botServo.attach(9);  // attaches the servo on pin 9 to the servo object
  topServo.attach(10);

}
const int botHome = 90;
const int topHome = 94;

void loop() {
  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }

  // botServo.write(18); // HOME
  // botServo.write(0); // LEFT SIDE ACTUATION
  // botServo.write(36); // RIGHT SIDE ACTUATION
  

  // botServo.write(90); // HOME
  // topServo.write(72); // FORWARD ACUTATION

  botServo.write(botHome); // HOME
  topServo.write(topHome); // HOME

  delay(1000);

  botServo.write(botHome-30); // LEFT SIDE ACTUATION

  delay(1000);

  botServo.write(botHome); // HOME

  delay(1000);

  botServo.write(botHome+30); // RIGHT SIDE ACTUATION

  delay(1000);

  botServo.write(botHome); // HOME

  delay(1000);

  topServo.write(topHome-30); // FORWARD ACUTATION

  delay(1000);
  topServo.write(topHome); // HOME


}
