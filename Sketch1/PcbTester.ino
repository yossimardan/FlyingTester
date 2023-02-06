#include "Functions.h"
#include "Variables.h"

#include <Arduino.h>
#include <SPI.h>
#include <Streaming.h>
#include <TMC429.h>
//
const long BAUD = 115200;
const int LOOP_DELAY = 20;
//const int CLOCK_FREQUENCY_MHZ = 8;
//const int CLOCK_PIN = 25;
//const int CHIP_SELECT_PIN = 5;
//const int SCLK_PIN = 18;
//const int MOSI_PIN = 23;
//const int MISO_PIN = 19;
//const int SPI_BUS = VSPI;
//const int MOTOR = 0;


int counter = 0;

//class MyTMC429 : public TMC429 {
//private:
//    SPIClass* spi = NULL;
//
//    void spiBegin() override {
//        spi = new SPIClass(SPI_BUS);
//        spi->begin(SCLK_PIN, MISO_PIN, MOSI_PIN);
//    }
//
//    void spiBeginTransaction(SPISettings settings) override {
//        spi->beginTransaction(settings);
//    }
//
//    void spiEndTransaction() override {
//        spi->endTransaction();
//    }
//
//    uint8_t spiTransfer(uint8_t byte) override {
//        return spi->transfer(byte);
//    }
//};

// Instantiate TMC429
//MyTMC429 tmc429;


void setup()
{
	Initialize();
    Tmc429_Init();
	isTerminal = false;

    // Setup serial communications
    Serial.begin(BAUD);

    // tmc429 clock
    //pinMode(CLOCK_PIN, OUTPUT);
    //pinMode(CLOCK_PIN, OUTPUT);
    //ledcSetup(0, CLOCK_FREQUENCY_MHZ * 1000000, 1);
    //ledcAttachPin(CLOCK_PIN, 0);
    //ledcWrite(0, 1);

    //tmc429.setup(CHIP_SELECT_PIN, CLOCK_FREQUENCY_MHZ);
    //tmc429.initialize();
    //tmc429.setVelocityMode(MOTOR);


}

//========================================================
//=====     Main Loop       ==============================
//========================================================
void loop()
{
	delay(10);
	counter++;
	Test1_Toggle();
	
	if (counter > 10)
	{
//		counter = 0;
		GetSerialMsg();
		SendStatusMessage();

        delay(100);
        Tmc429_SetTarget(Target);

        uint32_t chipId = 0;
        for (int i = 0; i < 17; i = i + 8) {
            chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
        }

        Target_State = Tmc429_GetTarget();
        tmc429_SetVelocityMode();
        IsConnected = tmc429_IsConnected();
        Target_State = tmc429_GetVersion();
        Position = tmc429_GetPosition();
//        Serial.println(String(counter) +": target_position: " + String(Target_State));
//        Serial.println("Motor clk freq:" + String(ledcReadFreq(0)));
//        Serial.println("communicating\t= " + String(communicating));
//        Serial.println("RxBuffer\t= " + String(DebugCounter++));
        delay(LOOP_DELAY);

	}
}