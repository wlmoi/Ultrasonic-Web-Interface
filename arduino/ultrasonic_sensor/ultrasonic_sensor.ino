// ultrasonic_sensor.ino

// variabel
int indicator = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

// Start!
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  indicator = 0.01723 * readUltrasonicDistance(6, 5);
  Serial.println(indicator);
  if (indicator < 20) {
    Serial.println("Sebentar Lagi Penuh!");
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}

