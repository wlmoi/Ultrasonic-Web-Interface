Untuk menggunakan kode ini dengan ESP32, Anda perlu melakukan beberapa penyesuaian agar kompatibel dengan papan ESP32. Berikut adalah langkah-langkahnya:

    Setup Hardware:
        Sambungkan sensor ultrasonik (misalnya HC-SR04) ke ESP32:
            VCC ke 5V
            GND ke GND
            Trigger pin ke GPIO 6 (atau pin lain yang Anda inginkan)
            Echo pin ke GPIO 5 (atau pin lain yang Anda inginkan)
        Sambungkan LED (atau buzzer) ke GPIO 10 sebagai indikator.

    Instalasi Software:
        Pastikan Anda memiliki Arduino IDE yang sudah diatur untuk ESP32.
        Tambahkan ESP32 ke Arduino IDE dengan mengikuti petunjuk di sini.

    Code Adjustments:
        ESP32 memiliki perbedaan pada pengelolaan GPIO dibandingkan dengan Arduino. Beberapa pin mungkin tidak berfungsi dengan cara yang sama, jadi sesuaikan GPIO jika diperlukan.

    Upload Kode:
        Pastikan Anda memilih board "ESP32 Dev Module" dari menu Tools > Board.
        Upload kode yang telah disesuaikan ke ESP32.




    Penjelasan Kode:

    readUltrasonicDistance: Fungsi ini membaca waktu yang dibutuhkan oleh gelombang ultrasonik untuk kembali setelah memantul dari objek, dan mengembalikan waktu tersebut dalam mikrodetik.
    setup: Bagian ini mengatur serial komunikasi untuk debugging dan mengatur pin 10 sebagai output untuk indikator.
    loop: Bagian utama yang berjalan terus menerus. Ini menghitung jarak menggunakan sensor ultrasonik dan menyalakan indikator jika jarak kurang dari 20 cm.

Pengujian:

    Sambungkan ESP32 ke komputer Anda, lalu buka Serial Monitor di Arduino IDE untuk melihat output dari sensor.
    Tempatkan objek di depan sensor untuk melihat perubahan pada indikator LED atau buzzer.