/*-----------------------------------------------------------------------
  Author: DSC MBM
  Platforms: Arduino Uno R3
  File: blink_compare.ino
  ------------------------------------------------------------------------
  Description: 
  We compare a fully on LED against one that is blinking very rapidly 
  (imperceptible to our eyes at a first glance)
  ------------------------------------------------------------------------

------------------------------------------------------------------------*/
 
// Initialize 2 variables for the pins we'll be using later
int led_on = 13;
int led_flicker = 12;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_on, OUTPUT);
  pinMode(led_flicker, OUTPUT);       
  digitalWrite(led_on, HIGH);   // turn the LED on
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_flicker, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1);               // wait for a millisecond
  digitalWrite(led_flicker, LOW);    // turn the LED off by making the voltage LOW
  delay(1);               // wait for a millisecond
}
