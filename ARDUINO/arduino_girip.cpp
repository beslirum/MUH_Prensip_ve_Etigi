/*
Arduino ile programlama yaparken giriş/çıkış portlarından veri alma ve gönderme oldukça temel bir konsepttir. İlk olarak, Arduino'da giriş/çıkış portları olan dijital ve analog pinleri anlamak önemlidir.

Dijital Pinler:
Arduino'nun dijital pinleri sadece iki durumu temsil edebilir: HIGH (yüksek, 5V) veya LOW (düşük, 0V). Örneğin, bir sensörden gelen sinyali dijital bir pin üzerinden alabilir ve bu sinyali kontrol etmek için kullanabilirsin.

Analog Pinler:
Arduino'nun analog pinleri, analog voltajları ölçmek için kullanılır. Analog bir sensörden gelen voltaj değerini ölçebilir ve bu değeri Arduino üzerinde kullanabilirsin.

İlk olarak, bir sensörden (örneğin, potansiyometre gibi) gelen veriyi alalım. Potansiyometre, analog bir sensördür ve direnci değiştikçe analog bir voltaj değeri üretir. Bu değeri Arduino'daki bir analog pine bağlayarak okuyabiliriz.

Örnek bir Arduino kodu:
*/ 

const int potPin = A0; // Potansiyometrenin bağlı olduğu analog pin

void setup() {
  Serial.begin(9600); // Seri iletişimi başlat
}

void loop() {
  int potValue = analogRead(potPin); // Potansiyometrenin değerini oku
  Serial.println(potValue); // Değeri seri monitöre yazdır

  // Burada potValue değeri ile istediğin hesaplamaları yapabilirsin

  delay(1000); // 1 saniye bekle
}

