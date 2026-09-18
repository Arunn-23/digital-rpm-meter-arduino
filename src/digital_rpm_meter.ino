#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define IR_SENSOR 9
#define LED_PIN 13

volatile unsigned int pulseCount = 0;

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

    if (currentState == HIGH && lastState == LOW)
    {
        pulseCount++;

        digitalWrite(LED_PIN, HIGH);
        delay(10);
        digitalWrite(LED_PIN, LOW);
    }

    lastState = currentState;

    if (millis() - previousMillis >= 1000)
    {
        previousMillis = millis();

        rpm = pulseCount * 60;

        pulseCount = 0;
    }

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
