# Proyek-Penelitian-Farming-SteviaRB
Proyek ini merupakan sebuah penelitian gabungan yang dikerjakan oleh 3 departemen di ITS, yaitu :  
1. Departemen Biologi
2. Departemen Teknik Fisika
3. Departemen Teknik Instrumentasi  

Dalam penelitian ini saya sebagai asisten peneliti dari departemen Teknik Instrumentasi bertugas untuk mendesain serta membuat alat untuk mendukung proses penelitian  
Alat yang dibuat berupa sebuah lemari yang berisi 3 rak dengan kondisi tertutup. Berisi sebuah kamera dengan sistem penggerak yang bisa mengambil gambar tiap baris tanaman stevia dan juga memiliki sensor DHT11 pada tiap-tiap rak untuk memonitoring temperatur serta kelembapan. Foto diambil berkala dan dikirim secara otomatis pada folder penyimpanan Google Drive. Data monitoring yang didapat dari sensor DHT11 akan disimpan dan dikirim pada halaman Google Spreadsheet. Sistem elektronik serta pemrograman pada alat ini dikerjakan oleh saya sendiri. Dibuatnya alat ini bertujuan untuk mengamati pertumbuhan dari tanaman Stevia RB terhadap perbedaan panjang gelombang cahaya yang diberikan. Tanaman Stevia RB merupakan tanaman yang sensitif terhadap kontaminan, dengan alat yang dibuat ini kita bisa mengamati tanaman Stevia RB tanpa perlu menyentuhnya secara langsung, sehingga pertumbuhan tanaman Stevia RB aman terhindar dari kontaminan.  
  
List komponen yang digunakan :  
1. Raspberry Pi 3b
2. PCB utama
3. PCB touchscreen LCD
4. PCB USB webcam & Servo
5. LCD 7inch Touchscreen
6. Arduino nano
7. DHT 11 (3 buah)
8. USB Hub
9. USB Webcam (3 buah)
10. Stepper Nema17 (3 buah)
11. Power Supply 12v 10A
  
Berikut merupakan desain PCB utama versi pertama :  
=> Layer Atas  
  ![image](https://user-images.githubusercontent.com/87922087/143823699-942f2eae-b18b-45b8-903f-b51af5826194.png)

=> Layer Bawah  
  ![image](https://user-images.githubusercontent.com/87922087/143823767-af0d8f1b-e998-463b-a903-1e35cab96d80.png)

Berikut merupakan desain PCB utama versi kedua :  
=> Layer Atas  
  ![image](https://user-images.githubusercontent.com/87922087/143824376-eb411233-5e71-47e4-9dac-21e51eb6534b.png)

=> Layer Bawah  
  ![image](https://user-images.githubusercontent.com/87922087/143824471-060b5031-e703-4b9b-9d0e-39cfad0423a3.png)  
  
Berikut merupakan desain PCB USB Webcam & Servo :  
=> Layer Atas  
![image](https://user-images.githubusercontent.com/87922087/143825533-a5a85deb-cddf-4061-9290-656e65b19841.png)

=> Layer Bawah  
![image](https://user-images.githubusercontent.com/87922087/143825628-fbc19baa-4eac-4dbf-b704-e32d946d8bc8.png)

Berikut merupakan desain PCB touchscreen LCD :  
=> Layer Atas  
![image](https://user-images.githubusercontent.com/87922087/143826292-dea44669-45ef-4783-8fa4-4bcfa3934f9c.png)

=> Layer Bawah  
![image](https://user-images.githubusercontent.com/87922087/143826396-a713b89e-3679-4f55-9689-a3250a2a2fef.png)

Bahasa permrograman yang digunakan pada proyek ini terdiri dari 3 bahasa, yaitu :
1. C  
digunakan untuk memprogram arduino, membaca data dari 3 buah sensor DHT11 lalu mengirimkannya ke Raspberry Pi melalui USB Serial  
3. C++  
digunakan untuk memprogram GUI yang dibuat dengan menggunakan QT Creator  
5. Python  
digunakan untuk memprogram proses pergerakan kamera, pengambilan gambar, upload gambar ke Google Drive, serta membaca dan upload data monitoring sensor ke Google Spreadsheet  


  

