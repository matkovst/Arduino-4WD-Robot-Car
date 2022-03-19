#include "src/head.h"

#define TRIG_PIN 7
#define ECHO_PIN 8
#define SERVO_PIN 12
#define LED_PIN 13

Head head;

void setup()
{
    head.setup(TRIG_PIN, ECHO_PIN, SERVO_PIN);
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);

    const result_t r = head.check();
    if (r.code == RESULT_OK)
        Serial.println("Head checks passed.");
    else
        Serial.println("Head checks failed: " + r.msg);
}

void loop()
{
    const int distance = head.observe();
    Serial.println("Distance in CM: " + String(distance));
    
    const int ledDelay = ledDelayForDistance(distance);
    digitalWrite(LED_PIN, HIGH);
    delay(ledDelay);
    digitalWrite(LED_PIN, LOW);
    delay(ledDelay);
}

// void setup() { }

// void loop() { }