/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int greenPin = A5;  // Analog input pin that the potentiometer is attached to
const int redPin = A4; 
const int bluePin = A3;
const int greenOutPin = 9; // Analog output pin that the LED is attached to
const int blueOutPin = 3;
const int redOutPin = 11;
 // value read from the sound
int greenIn = 0;       
int redIn = 0;
int blueIn = 0;
// value output to the PWM (analog out)
int greenOut = 0;
int redOut = 0;
int blueOut = 0;
const int maxGreen = 70;
const int maxBlue = 100;
const int maxRed = 255;   
int maxMRed = 0;
int maxMBlue = 0;
int maxMGreen = 0;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  greenIn = analogRead(greenPin);
  redIn = analogRead(redPin);
  blueIn = analogRead(bluePin);
  maxMGreen = greenIn > maxMGreen ? greenIn : maxMGreen;
  maxMBlue = blueIn > maxMBlue ? blueIn : maxMBlue;
  maxMRed = redIn > maxMRed ? maxMRed : maxMRed;
  // map it to the range of the analog out:
  greenOut = map(greenIn, 0, maxMGreen, 0, maxGreen);
  redOut = map(redIn, 0, maxMRed, 0, maxRed);
  blueOut = map(blueIn, 0, maxMBlue, 0, maxBlue);
  // change the analog out value:
  analogWrite(greenOutPin, greenOut);
  analogWrite(redOutPin, redOut);
  analogWrite(blueOutPin, blueOut);

  // print the results to the serial monitor:
  Serial.print("red = " );
  Serial.print(redIn);
  Serial.print("\t\tgreen = " );
  Serial.print(greenIn);
  Serial.print("\t\tblue = " );
  Serial.print(blueIn);
 Serial.print("\t\tredOut = " );
  Serial.print(redOut);
  Serial.print("\t\tgreenOut = " );
  Serial.print(greenOut);
  Serial.print("\t\tblueOut = " );
  Serial.println(blueOut);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
