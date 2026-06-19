#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WiFi Credentials
const char* ssid = "ashok";
const char* password = "Ashok@07";

// ThingSpeak API Key
String apiKey = "ZPSOMVLOEORM8O9O";

// Pins
#define MQ2_PIN 34
#define LED_PIN 25
#define BUZZER_PIN 26

// LCD Address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Smoke Threshold
int smokeThreshold = 1000;

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // LCD Initialization
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smoke Detector");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);

  // WiFi Connection
  WiFi.begin(ssid, password);

  lcd.clear();
  lcd.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  delay(2000);
}

void loop() {

  int smokeValue = analogRead(MQ2_PIN);

  Serial.print("Smoke Value: ");
  Serial.println(smokeValue);

  int smokeStatus = 0;

  lcd.clear();

  if (smokeValue > smokeThreshold) {

    smokeStatus = 1;

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("WARNING!");

    lcd.setCursor(0, 1);
    lcd.print("SMOKE DETECTED");

    Serial.println("SMOKE DETECTED!");

  } else {

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Smoke Level:");

    lcd.setCursor(0, 1);
    lcd.print("SAFE");

    Serial.println("SAFE");
  }

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url =
      "http://api.thingspeak.com/update?api_key=" +
      apiKey +
      "&field1=" + String(smokeValue) +
      "&field2=" + String(smokeStatus);

    http.begin(url);

    int httpCode = http.GET();

    Serial.print("ThingSpeak Response: ");
    Serial.println(httpCode);

    http.end();
  }

  delay(15000); // ThingSpeak minimum update interval
}