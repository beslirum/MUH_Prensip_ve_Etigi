
/*
Bu örnekte, bir analog sensörden (örneğin, LDR - ışık bağımlı direnç) gelen değeri okuyacak ve bu değeri kullanarak basit bir ışık şiddeti hesaplaması yapacağız.
*/

const int ldrPin = A0; // LDR'nin bağlı olduğu analog pin
int ldrValue; // LDR değerini tutacak değişken

void setup() {
  Serial.begin(9600); // Seri iletişimi başlat
}

void loop() {
  ldrValue = analogRead(ldrPin); // LDR değerini oku
  Serial.print("LDR Değeri: ");
  Serial.println(ldrValue); // LDR değerini seri monitöre yazdır

  // Işık şiddeti hesaplama (örnek bir formül)
  int lightIntensity = map(ldrValue, 0, 1023, 0, 100); // Değer aralığını haritala
  Serial.print("Işık Şiddeti (%): ");
  Serial.println(lightIntensity); // Işık şiddetini seri monitöre yazdır

  delay(1000); // 1 saniye bekle
}


/*
Bu örnekte, LDR'nin analog pininden gelen değeri analogRead fonksiyonu ile okuyoruz. Daha sonra, bu değeri bir formül kullanarak ışık şiddeti olarak hesaplıyoruz. map fonksiyonu, bir değeri belirli bir aralıktan başka bir aralığa dönüştürmek için kullanılır.
  */
