// ultrasonic_sensor.ino

// Variabel
int indicator = 0;

// Fungsi untuk membaca jarak dari sensor ultrasonik
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  // Mengosongkan trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Mengatur trigger pin ke HIGH selama 10 mikrodetik
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Membaca echo pin, dan mengembalikan waktu perjalanan gelombang suara dalam mikrodetik
  return pulseIn(echoPin, HIGH);
}

// Mulai!
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);  // Mengatur pin 10 sebagai output untuk indikator
}

void loop() {
  // Menghitung jarak dalam cm
  indicator = 0.01723 * readUltrasonicDistance(6, 5);
  
  // Jika jarak kurang dari 20 cm, nyalakan LED dan tampilkan pesan
  if (indicator < 20) {
    Serial.println("Sebentar Lagi Penuh!");
    digitalWrite(10, HIGH);  // Nyalakan indikator
  } else {
    digitalWrite(10, LOW);   // Matikan indikator
  }
  
  delay(10); // Delay untuk meningkatkan performa simulasi
}
