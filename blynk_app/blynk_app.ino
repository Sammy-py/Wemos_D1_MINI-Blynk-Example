/////////////// telefondan lcd ye yazı veri aktar ///////////////////
///Telefondan hotsopt açıp kullanabilirsiniz///

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>   //I2C PROTOKLÜ WEMOS D1 MINI'DE SDA D2 SCL D1
LiquidCrystal_I2C lcd(0x27, 16, 2);

char token[] = "OeFqA3E3***********************";//token şifre = BLYNK UYGULAMASI MAİL GÖNDERİYOR (* ile gizlemem gerekiyor)
char agAdi[] = "HUAWEI";//modem kullanıcı adı yada hotspotdaki
char agSifre[] = "123456789"; //modem kullanıcı şifre yada hotspotdaki

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Blynk.begin(token, agAdi, agSifre);
}
void loop() {
  Blynk.run();
}
BLYNK_WRITE(V2)
{
  String pinValue = param.asStr(); // V2 Değişkeni
  lcd.clear();
  Serial.println(pinValue);
  lcd.print(pinValue);
}
