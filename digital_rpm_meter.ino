/*
 * Digital RPM Meter Using Arduino Nano
 * IR Sensor -> D9
 * 16x2 I2C LCD -> SDA A4, SCL A5
 * LED Indicator -> D13
 *
 * RPM = pulses detected in 1 second × 60
 * Assumption: 1 pulse = 1 complete revolution
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define IR_SENSOR 9
#define LED_PIN 13

unsigned int pulseCount = 0;
unsigned long previousMillis = 0;
unsigned long displayMillis = 0;

int rpm = 0;
bool lastState = LOW;

void setup()
{
  pinMode(IR_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hi Arun");

  lcd.setCursor(0, 1);
  lcd.print("RPM meter Ready..");

  delay(2000);
  lcd.clear();
}

void loop()
{
  bool currentState = digitalRead(IR_SENSOR);

  // Detect one HIGH transition as one pulse
  if (currentState == HIGH && lastState == LOW)
  {
    pulseCount++;

    // Pulse indication
    digitalWrite(LED_PIN, HIGH);
    delay(10);
    digitalWrite(LED_PIN, LOW);
  }

  lastState = currentState;

  // Calculate RPM every 1 second
  if (millis() - previousMillis >= 1000)
  {
    previousMillis = millis();

    rpm = pulseCount * 60;

    pulseCount = 0;
  }

  // Refresh LCD
  if (millis() - displayMillis >= 600)
  {
    displayMillis = millis();

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Reading RPM");

    lcd.setCursor(0, 1);
    lcd.print("RPM: ");
    lcd.print(rpm);
  }
}
