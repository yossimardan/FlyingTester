#include <Arduino.h>
#include <SPI.h>
#include <Streaming.h>
#include <TMC429.h>
#include "Functions.h"
#include "Externals.cpp"

//void setStepDiv(uint8_t step_div);
//uint8_t getStepDiv();


const int CLOCK_FREQUENCY_MHZ = 16;
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
    //tmc429.setRampMode(MOTOR);
    tmc429.setTargetVelocityInHz(MOTOR,100);
    tmc429.setLimitsInHz(MOTOR, Vmin,Vmax,AccMax);
}
//=============================================================
void Tmc429_SetTargetV(int value)
{
    tmc429.setTargetVelocityInHz(MOTOR, value);
}

void Tmc429_StopAll()
{
    tmc429.stopAll();
}

int Tmc429_GetTargetV()
{
    return tmc429.getTargetVelocityInHz(MOTOR);
}


void Tmc429_SetTargetP(int value)
{
    tmc429.setTargetPosition(MOTOR, value);
}

int Tmc429_GetTargetP()
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

void  tmc429_SetPosition(int32_t position)
{
    tmc429.setActualPosition(MOTOR,position);
}


void  tmc429_SetMotionProfile(uint32_t vMin, uint32_t vMax, uint32_t accMax)
{
    tmc429.setLimitsInHz(MOTOR, vMin, vMax, accMax);
}

void  tmc429_WriteRegister(uint8_t address, uint32_t value)
{
    tmc429.writeRegister(MOTOR, address,value);
}


int  tmc429_ReadRegister(uint8_t address)
{
    return tmc429.readRegister(MOTOR, address);
}
