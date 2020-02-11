#define LED_PIN 2

void setup() {
  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);
}

void timedBlink() {
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);   
}

void dimmer(int freq, int duty) {
  int period, onTime, offTime;
  period = 1000/freq;
  onTime = period * duty / 100;
  offTime = period - onTime;
  digitalWrite(LED_PIN, HIGH);
  delay(onTime);
  digitalWrite(LED_PIN, LOW);
  delay(offTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  int freq = 100;
  for (int x = 0; x < 100; x++) {
    dimmer(freq, x);
  }
  freq = 100;
  for (int x = 100; x > 0; x--) {
    dimmer(freq, x);
  }
}
