#include "Externals.cpp"
#include "Functions.h"

const static uint8_t ADDRESS_X_TARGET = 0b0000;
const static uint8_t ADDRESS_X_ACTUAL = 0b0001;
const static uint8_t ADDRESS_V_MIN = 0b0010;
const static uint8_t ADDRESS_V_MAX = 0b0011;
const static uint8_t ADDRESS_V_TARGET = 0b0100;
const static uint8_t ADDRESS_V_ACTUAL = 0b0101;
const static uint8_t ADDRESS_A_MAX = 0b0110;
const static uint8_t ADDRESS_A_ACTUAL = 0b0111;
const static uint8_t ADDRESS_A_THRESHOLD = 0b1000;
const static uint8_t ADDRESS_PROP_FACTOR = 0b1001;
const static uint8_t ADDRESS_REF_CONF_MODE = 0b1010;
const static uint8_t ADDRESS_INTERRUPT = 0b1011;
const static uint8_t ADDRESS_CLOCK_CONFIGURATION = 0b1100;
const static uint8_t ADDRESS_DX_REF_TOLERANCE = 0b1101;
const static uint8_t ADDRESS_X_LATCHED = 0b1110;
const static uint8_t ADDRESS_USTEP_COUNT_429 = 0b1111;
// JDX Addresses
const static uint8_t ADDRESS_DATAGRAM_LOW_WORD = 0b0000;
const static uint8_t ADDRESS_DATAGRAM_HIGH_WORD = 0b0001;
const static uint8_t ADDRESS_COVER_POS_LEN = 0b0010;
const static uint8_t ADDRESS_COVER_DATAGRAM = 0b0011;
const static uint8_t ADDRESS_IF_CONFIGURATION_429 = 0b0100;
const static uint8_t ADDRESS_POS_COMP_429 = 0b0101;
const static uint8_t ADDRESS_POS_COMP_INT = 0b0110;
const static uint8_t ADDRESS_POWER_DOWN = 0b1000;
const static uint8_t ADDRESS_TYPE_VERSION_429 = 0b1001;
const static uint8_t ADDRESS_SWITCHES = 0b1110;
const static uint8_t ADDRESS_GLOBAL_PARAMETERS = 0b1111;



int msgCounter = 0;
String RxBuffer;
//========================================================
//=====     Serial_Write           =======================
//========================================================
void Serial_Write(String msg)
{
    Serial1.print(msg);
}

void Serial_Writeln(String msg)
{
    Serial1.println(msg);
}

String Serial_Read()
{
    return Serial1.readString();
}

//========================================================
//=====     ParseParams            =======================
//========================================================
void ParseParams(String params)
{
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int index4 = 0;
    param1 = Null;
    param2 = Null;
    param3 = Null;
    param4 = Null;
    String prm = "";
    if (params.length() == 1) return;

    index1 = params.indexOf(",");
    if (index1 == -1) prm = params;
    else  prm = params.substring(0, index1);
    param1 = prm.toInt();

    if (index1 != -1)
    {
        index2 = params.indexOf(",", index1 + 1);
        prm = params.substring(index1 + 1, index2);
        param2 = prm.toInt();
    }
    if (index2 != -1)
    {
        index3 = params.indexOf(",", index2 + 1);
        prm = params.substring(index2 + 1, index3);
        param3 = prm.toInt();
    }
    if (index3 != -1)
    {
        index4 = params.indexOf(",", index3 + 1);
        prm = params.substring(index3 + 1, index4);
        param4 = prm.toInt();
    }
}

//========================================================
//=====     GetSerialMsg           =======================
//========================================================
void GetSerialMsg()
{

    String cmd;
    String rxString = Serial_Read();
    RxBuffer = RxBuffer + rxString;

    int index = RxBuffer.indexOf("\n");
    if (index == -1) return;

    String commandLine = RxBuffer.substring(0, index);
    RxBuffer = "";
    cmd = commandLine.substring(0, 1);
    if (cmd == "?" || cmd == "q")
    {
        HandleCommand(cmd, param1, param2, param3);
        return;
    }
    cmd = commandLine.substring(0, 2);
    String params = commandLine.substring(2);

    ParseParams(params);
    HandleCommand(cmd, param1, param2, param3);
}
//========================================================
//=====    Report                 ========================
//========================================================
void SendRportMessage()
{
    Serial_Writeln("X_TARGET:\t" + String(tmc429_ReadRegister(ADDRESS_X_TARGET)));
    Serial_Writeln("X_ACTUAL:\t" + String(tmc429_ReadRegister(ADDRESS_X_ACTUAL)));
    Serial_Writeln("V_MIN:\t\t" + String(tmc429_ReadRegister(ADDRESS_V_MIN)));
    Serial_Writeln("V_MAX:\t\t" + String(tmc429_ReadRegister(ADDRESS_V_MAX)));
    Serial_Writeln("V_TARGET:\t" + String(tmc429_ReadRegister(ADDRESS_V_TARGET)));
    Serial_Writeln("V_ACTUAL:\t" + String(tmc429_ReadRegister(ADDRESS_V_ACTUAL)));
    Serial_Writeln("A_MAX:\t\t" + String(tmc429_ReadRegister(ADDRESS_A_MAX)));
    Serial_Writeln("A_ACTUAL:\t" + String(tmc429_ReadRegister(ADDRESS_A_ACTUAL)));
    Serial_Writeln("A_THRESHOLD:\t" + String(tmc429_ReadRegister(ADDRESS_A_THRESHOLD)));
    Serial_Writeln("PROP_FACTOR:\t" + String(tmc429_ReadRegister(ADDRESS_PROP_FACTOR)));
    Serial_Writeln("CONF_MODE:\t" + String(tmc429_ReadRegister(ADDRESS_REF_CONF_MODE), HEX));
    Serial_Writeln("INTERRUPT:\t" + String(tmc429_ReadRegister(ADDRESS_INTERRUPT)));
    Serial_Writeln("CLOCK:\t\t" + String(tmc429_ReadRegister(ADDRESS_CLOCK_CONFIGURATION)));
    Serial_Writeln("TOLERANCE:\t" + String(tmc429_ReadRegister(ADDRESS_DX_REF_TOLERANCE)));
    Serial_Writeln("LATCHED:\t" + String(tmc429_ReadRegister(ADDRESS_X_LATCHED)));
    Serial_Writeln("COUNT_429:\t" + String(tmc429_ReadRegister(ADDRESS_USTEP_COUNT_429)));


    const static uint8_t ADDRESS_DATAGRAM_LOW_WORD = 0b0000;
    const static uint8_t ADDRESS_DATAGRAM_HIGH_WORD = 0b0001;
    const static uint8_t ADDRESS_COVER_POS_LEN = 0b0010;
    const static uint8_t ADDRESS_COVER_DATAGRAM = 0b0011;
    const static uint8_t ADDRESS_IF_CONFIGURATION_429 = 0b0100;
    const static uint8_t ADDRESS_POS_COMP_429 = 0b0101;
    const static uint8_t ADDRESS_POS_COMP_INT = 0b0110;
    const static uint8_t ADDRESS_POWER_DOWN = 0b1000;
    const static uint8_t ADDRESS_TYPE_VERSION_429 = 0b1001;
    const static uint8_t ADDRESS_SWITCHES = 0b1110;
    const static uint8_t ADDRESS_GLOBAL_PARAMETERS = 0b1111;







}
//========================================================
//=====    Send Status Message    ========================
//========================================================
void SendStatusMessage()
{
    if (isTerminal) return;

    Serial_Writeln("<" + String(msgCounter++) + "> " +
        " PR:" + String(A001) +
        " PS:" + String(Position) +
        " TR:" + String(Target_State) +
        " CN:" + String(IsConnected) +
        " CF:" + String(Config) +
        ">");

    /*   Serial1.println("<" + String(msgCounter++) + "> " +
           " PR:" + String(A001) +
           " PS:" + String(Position) +
           " TR:" + String(Target_State) +
           " CN:" + String(IsConnected) +
           ">");*/

    return;


    Serial_Writeln("X_TARGET:\t\t" + String(tmc429_ReadRegister(ADDRESS_X_TARGET)));
    Serial_Writeln("X_ACTUAL:" + String(tmc429_ReadRegister(ADDRESS_X_ACTUAL)));
    Serial_Writeln("V_MIN:" + String(tmc429_ReadRegister(ADDRESS_V_MIN)));
    Serial_Writeln("V_MAX:" + String(tmc429_ReadRegister(ADDRESS_V_MAX)));
    Serial_Writeln("V_TARGET:" + String(tmc429_ReadRegister(ADDRESS_V_TARGET)));
    Serial_Writeln("V_ACTUAL:" + String(tmc429_ReadRegister(ADDRESS_V_ACTUAL)));
    Serial_Writeln("A_MAX:" + String(tmc429_ReadRegister(ADDRESS_A_MAX)));
    Serial_Writeln("A_ACTUAL:" + String(tmc429_ReadRegister(ADDRESS_A_ACTUAL)));
    Serial_Writeln("A_THRESHOLD:" + String(tmc429_ReadRegister(ADDRESS_A_THRESHOLD)));
    Serial_Writeln("PROP_FACTOR:" + String(tmc429_ReadRegister(ADDRESS_PROP_FACTOR)));
    Serial_Writeln("CONF_MODE:" + String(tmc429_ReadRegister(ADDRESS_REF_CONF_MODE), HEX));
    Serial_Writeln("INTERRUPT:" + String(tmc429_ReadRegister(ADDRESS_INTERRUPT)));
    Serial_Writeln("CLOCK:" + String(tmc429_ReadRegister(ADDRESS_CLOCK_CONFIGURATION)));
    Serial_Writeln("TOLERANCE:" + String(tmc429_ReadRegister(ADDRESS_DX_REF_TOLERANCE)));
    Serial_Writeln("LATCHED:" + String(tmc429_ReadRegister(ADDRESS_X_LATCHED)));
    Serial_Writeln("COUNT_429:" + String(tmc429_ReadRegister(ADDRESS_USTEP_COUNT_429)));

    Serial_Writeln(">");
}
//========================================================
//=====      Help                 ========================
//========================================================
void SendHelpMessage()
{
    Serial_Writeln("PcbTester Version 1.20 - Gusti Base");
    Serial_Writeln("========================================================");
    Serial_Writeln("mr - Master Reset");
    Serial_Writeln("q  - Quit terminal mode");
    Serial_Writeln("rp - Get report");
    Serial_Writeln("rn - Move Relative");
    Serial_Writeln("ci - Set Homing Creep_Interval, when velocity = 0.");
    Serial_Writeln("hv - Set Homing Approatch velocity");
    Serial_Writeln("sv - Set velocity.");
    Serial_Writeln("st - Print machine state (Parameters).");
    Serial_Writeln("========================================================");
    Serial_Writeln("?  - Terminal mode - Help Page");
    Serial_Writeln("q -  Quit terminal mode ");
}

