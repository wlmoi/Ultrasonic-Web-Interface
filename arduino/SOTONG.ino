// SOTONG.ino

// Pin setup
const int triggerPin = 5; // Pin trig HC-SR04
const int echoPin = 18;   // Pin echo HC-SR04
const int mq2Pin = 34;    // Pin analog MQ2
const int indicatorPin = 2; // Pin LED indicator

// Variabel untuk sensor ultrasonik dan MQ2
float distance;
int gasValue;
int indicator = 0;

// Fungsi untuk membaca jarak menggunakan sensor ultrasonik
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

// Fungsi setup
void setup() {
  Serial.begin(115200);
  pinMode(indicatorPin, OUTPUT);
}

// Fungsi loop
void loop() {
  // Baca jarak dari sensor ultrasonik
  distance = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Baca nilai gas dari sensor MQ2
  gasValue = analogRead(mq2Pin);
  Serial.print("Nilai Gas: ");
  Serial.println(gasValue);

  // Logika untuk mengontrol LED indicator berdasarkan jarak
  if (distance < 20) {
    Serial.println("Tong Sampah 1 Sebentar Lagi Penuh!");
    digitalWrite(indicatorPin, HIGH);
  } else {
    digitalWrite(indicatorPin, LOW);
  }

  // Logika tambahan untuk indikator gas
  if (gasValue > 300) {
    Serial.println("Bahaya Gas Terdeteksi Sekitar Tong Sampah 1!");
    digitalWrite(indicatorPin, HIGH);
  } else {
    digitalWrite(indicatorPin, LOW);
  }

  delay(1000); // Delay 1 detik
}
