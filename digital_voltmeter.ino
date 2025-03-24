// Incarca librariile pentru afisare
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

float R1 = 100.0; // kOhm  // Rezistentele divizorului de intrare
float R2 = 22.0;  // kOhm

// Defineste matrix
Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
    matrix.begin(0x70);
    matrix.setBrightness(2);
    matrix.blinkRate(0);
    Serial.begin(9600);
}

void loop()
{
    int n = analogRead(A0); // Citirea pinului de intrare numar pana la 1023
    float uI = n * (1 + R1 / R2) * (5.0 / 1023.0);
    Serial.println(uI);
    matrix.print(uI);
    matrix.writeDisplay();
    delay(500);
}
