#include <assert.h>
#include "Sender/Generate_BMS_Data.h"
#include "Receiver/Rx_BMS_Data.h"
#include "BMS_Statistics/BMS_Statistics.h"

int Rx_status = FALSE;
char receive_BMSdata[MAX_NOOF_RECEIVED_BMSDATA];

void Test_Receiver()
{
  Rx_status = ReadData_From_Console(READ_FROM_MOCK_DATA,receive_BMSdata);
  assert(Rx_status == ACK_RX_DATA);
}

int main()
{
  Test_Receiver();
}
