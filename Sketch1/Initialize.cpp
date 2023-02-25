#include "Externals.cpp"
#include "Functions.h"
//int TXD1 = 15;
//int RXD1 = 02;

void Initialize()
{
    pinMode(TEST1, OUTPUT);
    pinMode(TEST2, OUTPUT);
    pinMode(12, INPUT_PULLDOWN);

    Serial.begin(115200);
    Serial.setTimeout(10);
    Serial1.begin(115200, SERIAL_8N1, RXD1_PIN, TXD1_PIN);
    Serial1.setTimeout(10);
}
