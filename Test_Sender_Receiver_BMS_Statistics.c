#include <assert.h>
#include "Sender/Generate_BMS_Data.h"
#include "Receiver/Rx_BMS_Data.h"
#include "BMS_Statistics/BMS_Statistics.h"

int Rx_status = FALSE;

void ReadMock_BMSdata();
void Read_realTime_data();

void Test_Receiver()
{
  ReadMock_BMSdata();
  Read_realTime_data();
}

void ReadMock_BMSdata() {
    char Rx_BMSdata[MAX_NOOF_RECEIVED_BMSDATA] = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
    Rx_status = ReadData_From_Console(READ_FROM_MOCK_DATA,Rx_BMSdata);
    
    for(int BMSdata = 0; BMSdata < 200; BMSdata++)
    {
        assert(Rx_BMSdata[BMSdata] == '\0');
    }
    assert(Rx_status == ACK_RX_DATA);
}

void Read_realTime_data() {
    char Rx_BMSdata[MAX_NOOF_RECEIVED_BMSDATA] = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
    Rx_status = ReadData_From_Console(READ_FROM_PIPE,Rx_BMSdata);
    
    for(int BMSdata = 0; BMSdata < MAX_NOOF_RECEIVED_BMSDATA; BMSdata++)
    {
        assert(Rx_BMSdata[BMSdata] == '\0');
    }
    assert(Rx_status == NACK_RX_DATA);
}

int main()
{
  Test_Receiver();
}
