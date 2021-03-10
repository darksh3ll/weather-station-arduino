#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SimpleDHT.h>

// configure ecran lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//configure capteur DHT11
int pinDHT11 = 13;
SimpleDHT11 dht11(pinDHT11);

//configure LED RGB
int ROUGE_PIN = 8;
int GREEN_PIN = 10;
int BLEU_PIN = 9;

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(ROUGE_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLEU_PIN, blueValue);
}

void setup()
{
  pinMode(ROUGE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLEU_PIN, OUTPUT);
  Serial.begin(115200);
  lcd.begin(16, 2);
}

void loop()
{
  float temperature = 0;
  float humidity = 0;
  lcd.setCursor(0, 0);
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT22 failed, err=");
    Serial.print(SimpleDHTErrCode(err));
    Serial.print(",");
    Serial.println(SimpleDHTErrDuration(err));
    delay(2000);
    return;
  }

  if (temperature >= 30)
  {
    setColor(255, 0, 0); //ROUGE
  }
  else
  {
    setColor(0, 255, 12);
  }

  Serial.print("Sample OK: ");
  Serial.print((float)temperature);
  Serial.print(" *C, ");
  Serial.print((float)humidity);
  Serial.println(" RH%");

  lcd.print((int)temperature);
  lcd.print(" DEGRES C");
  lcd.setCursor(0, 1);
  lcd.print((int)humidity);
  lcd.print(" % HUMIDITE");
  delay(1500);
}