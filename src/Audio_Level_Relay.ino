/*
 * Project Audio_Level_Relay
 * Description:
 * Author:
 * Date:
 */

 int ledPin = D1;                // LED connected to digital pin D1
 int analogPin = A0;             // potentiometer connected to analog pin A0
 int val = 0;                    // variable to store the read value
 int too_loud_count = 0;
 int count_threshold = 100;
 int level_threshold = 255;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(ledPin, OUTPUT);      // sets the ledPin as output
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  val = analogRead(analogPin);
  if(val > level_threshold)
  {
    too_loud_count++;
    delay(100);
  }

  if(too_loud_count > count_threshold)
  {
    digitalWrite(ledPin, 1);
    delay(5000);
    too_loud_count = 0;
    digitalWrite(ledPin, 0);
  }
  // The core of your code will likely live here.

}
