/*-----------------------------------------------------------------------
  Author:  DSC MBM
  Platforms: Arduino Uno R3
  File: analog_input_vol.ino
  ------------------------------------------------------------------------
  Description:
  In this activity we'll generate sounds with our microcontroller that'll
  be played through an attached speaker. We'll modify the volume of the
  sounds by reading the value from an attached potentiometer.
  
  We'll also use the Serial object from the Arduino libraries to send 
  messages back to the computer via USB.  After the code is uploaded to
  the microcontroller, these messages can be displayed on a computer by 
  opening the Serial Monitor window in the Arduino IDE.
  ------------------------------------------------------------------------
 ------------------------------------------------------------------------*/

// Instead of using variables, we'll use constant types to give names to
// the pins used as these won't change throughout the code.
const int analog_in_pin  = A0;  // Analog input pin that the potentiometer is attached to
const int analog_out_pin = 11;  // Analog output pin that the LED is attached to

// For tracking the readings and volume we use variables as
// their values will change throughout the code
int read_value = 0;          // value read from the pot
int volume = 0;              // value output to the PWM (analogWrite)

void setup() {
  // initialize serial communications at 9600bps:
  Serial.begin(9600); 
}

void loop() {
  // Read the current value of the potentiometer
  read_value = analogRead(analog_in_pin);            
  // map it to the range of the analog out
  volume = map(read_value, 0, 1023, 0, 127);
  
  // change the analog out value:
  analogWrite(analog_out_pin, volume);
   
  // print the results to the serial monitor:
  Serial.print("read = " );                       
  Serial.print(read_value);      
  Serial.print("\t output = ");      
  Serial.println(volume);
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
