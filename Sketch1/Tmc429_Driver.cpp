#include <Arduino.h>
#include <SPI.h>
#include <Streaming.h>
#include <TMC429.h>

const int CLOCK_FREQUENCY_MHZ = 8;
const int CLOCK_PIN = 25;
const int CHIP_SELECT_PIN = 5;
const int SCLK_PIN = 18;
const int MOSI_PIN = 23;
const int MISO_PIN = 19;
const int SPI_BUS = VSPI;
const int MOTOR = 0;

class MyTMC429 : public TMC429 {
    private:  SPIClass* spi = NULL;

    void spiBegin() override {
        spi = new SPIClass(SPI_BUS);
        spi->begin(SCLK_PIN, MISO_PIN, MOSI_PIN);
    }

    void spiBeginTransaction(SPISettings settings) override {
        spi->beginTransaction(settings);
    }

    void spiEndTransaction() override {
        spi->endTransaction();
    }

    uint8_t spiTransfer(uint8_t byte) override {
        return spi->transfer(byte);
    }
};

// Instantiate TMC429
MyTMC429 tmc429;


void Tmc429_Init()
{
    // tmc429 clock
    pinMode(CLOCK_PIN, OUTPUT);
    ledcSetup(0, CLOCK_FREQUENCY_MHZ * 1000000, 1);
    ledcAttachPin(CLOCK_PIN, 0);
    ledcWrite(0, 1);

    tmc429.setup(CHIP_SELECT_PIN, CLOCK_FREQUENCY_MHZ);
    tmc429.initialize();
    tmc429.setVelocityMode(MOTOR);
    tmc429.setTargetVelocityInHz(MOTOR,100);

}
//=============================================================
void Tmc429_SetTarget(int value)
{
    tmc429.setTargetPosition(MOTOR, value);
}

int Tmc429_GetTarget()
{
   return tmc429.getTargetPosition(MOTOR);
}
void tmc429_SetVelocityMode()
{
    tmc429.setVelocityMode(MOTOR);
}

bool  tmc429_IsConnected()
{
    return  tmc429.communicating();
}

int tmc429_GetVersion()
{
    return  tmc429.getVersion();
}

int tmc429_GetPosition()
{
    return  tmc429.getActualPosition(MOTOR);
}

