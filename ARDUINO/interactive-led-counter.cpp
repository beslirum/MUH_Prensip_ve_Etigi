//görsel diğer repoda

// Arduino pin bağlantıları
const int ledPins[] = {9, 8, 7, 6}; // LED pinleri
const int buttonPinForward = 2;    // İleri butonun pin numarası
const int buttonPinBackward = 3;   // Geri butonun pin numarası

// İleri ve geri sayım için kullanılan değişkenler
int sayac = 0;         // Sayı değişkeni
int yon = 0;           // Sayma yönü (0: durdu, 1: ileri, -1: geri)

// İleri butonun durumu
int sonButonDurumuIleri = HIGH;
// Geri butonun durumu
int sonButonDurumuGeri = HIGH;

void setup() {
  // LED pinleri çıkış olarak ayarlanır
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Buton pinleri giriş olarak ayarlanır
  pinMode(buttonPinForward, INPUT_PULLUP);
  pinMode(buttonPinBackward, INPUT_PULLUP);
}

void loop() {
  // İleri butonun durumu okunur
  int butonDurumuIleri = digitalRead(buttonPinForward);

  // İleri butona basılıp bırakıldığında
  if (butonDurumuIleri == LOW && sonButonDurumuIleri == HIGH) {
    yon = 1;       // İleri sayma yönü ayarlanır
    sayac = 0;     // Sayı sıfırlanır
  }

  // Geri butonun durumu okunur
  int butonDurumuGeri = digitalRead(buttonPinBackward);

  // Geri butona basılıp bırakıldığında
  if (butonDurumuGeri == LOW && sonButonDurumuGeri == HIGH) {
    yon = -1;      // Geri sayma yönü ayarlanır
    sayac = 9;     // Sayı 9'a ayarlanır
  }

  // LED'lerin durumu güncellenir
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], bitRead(sayac, i));
  }

  // İleri ya da geri sayma durumuna göre sayı güncellenir
  if (yon == 1) {
    sayac++;
    if (sayac > 9) {
      sayac = 0;
    }
  } else if (yon == -1) {
    sayac--;
    if (sayac < 0) {
      sayac = 9;
    }
  }

  // İleri ve geri buton durumları güncellenir
  sonButonDurumuIleri = butonDurumuIleri;
  sonButonDurumuGeri = butonDurumuGeri;

  // 1 saniye beklenir
  delay(1000);
}
