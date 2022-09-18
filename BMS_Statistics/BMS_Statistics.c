#include "BMS_Statistics.h"

static int BMSdataIndex = 0;

void sortGivenIndexPosition(int *BatteryTempdata, int *BatterySOCdata, int noOfElements, int received_position) {
	int temp;
	
	for(int index = received_position+1 ; index < noOfElements; index++) {
	if(BatteryTempdata[received_position] > BatteryTempdata[index]) {
	temp = BatteryTempdata[received_position];
     	BatteryTempdata[received_position] = BatteryTempdata[index];
     	BatteryTempdata[index] = temp;
   	}
   	
   	if(BatterySOCdata[received_position] > BatterySOCdata[index]) {
	temp = BatterySOCdata[received_position];
     	BatterySOCdata[received_position] = BatterySOCdata[index];
     	BatterySOCdata[index] = temp;
   	}
 	}
}

void sortBmsData(int BatteryTempdata[], int BatterySOCdata[]) {
  	for(int index = 0; index < MAX_RECEIVE_DATA; index++) {
    	sortGivenIndexPosition(BatteryTempdata, BatterySOCdata,  MAX_RECEIVE_DATA, index); 
  	}
}

void movingAverage_of_BMSdata(int BatteryTempdata[], int BatterySOCdata[])
{
    int AvgofTemp = 0;
    int AvgofSoc = 0;
    
    for(int index = MAX_RECEIVE_DATA - 5; index < MAX_RECEIVE_DATA; index++)
    {
       AvgofTemp +=  BatteryTempdata[index];
       AvgofSoc +=  BatterySOCdata[index];
       //printf("avg: %d \n",index);
    }
    AvgofTemp /= 5;
    AvgofSoc /= 5;
    
    printf("avg: %d %d",AvgofTemp,AvgofSoc);
}

void convertString_To_Int(char receive_BMSdata[], int len, int BatteryTempdata[], int BatterySOCdata[])
{
    int index;
    char BMSdata[4];
    
    memset(BMSdata, '\0', sizeof(BMSdata));
    
    for(index = 0; index <  len; index++)
    {
        if(receive_BMSdata[index] != '\0')
        {
           // printf("in: %d\n",index);
            if((receive_BMSdata[index] != ',') && (receive_BMSdata[index] != '\n'))
            {
                BMSdata[BMSdataIndex] = receive_BMSdata[index];
                //printf("%c",BMSdata[BMSdataIndex]);
                BMSdataIndex++;
            }
            convertBatteryTempData_To_Int(receive_BMSdata[index], BatteryTempdata, BMSdata, sizeof(BMSdata));
		
	    convertBatterySocData_To_Int(receive_BMSdata[index], BatterySOCdata, BMSdata, sizeof(BMSdata));
        }
        else
        {
            break;
        }
    }
}

void convertBatteryTempData_To_Int(int receive_BMSdata, int BatteryTempdata[], char BMSdata[], int BMSData_length)
{
    static int BMSTempIndex = 0;
    
    if((receive_BMSdata == ',') && (receive_BMSdata != '\n'))
    {
       BatteryTempdata[BMSTempIndex] = atoi(BMSdata);
       //printf("Temp: %d \n",BatteryTempdata[BMSTempIndex]);
       ++BMSTempIndex;
       BMSdataIndex = 0;
       memset(BMSdata, '\0', BMSData_length);
    }
}

void convertBatterySocData_To_Int(int receive_BMSdata, int BatterySOCdata[], char BMSdata[], int BMSData_length)
{
    static int BMSSocIndex = 0;
    
    if((receive_BMSdata == '\n') && (receive_BMSdata != ','))
    {
       BatterySOCdata[BMSSocIndex] = atoi(BMSdata);
       //printf("SOC: %d \n",BatterySOCdata[BMSSocIndex]);
       ++BMSSocIndex;
       BMSdataIndex = 0;
       memset(BMSdata, '\0', BMSData_length);
    }
}

void BMSData_Statistics(char receive_BMSdata[], int datasize)
{
    int BatteryTempdata[50];
    int BatterySOCdata[50];
    
    convertString_To_Int(receive_BMSdata,datasize,BatteryTempdata,BatterySOCdata);
    movingAverage_of_BMSdata(BatteryTempdata, BatterySOCdata);
    sortBmsData(BatteryTempdata, BatterySOCdata);
    printf("Temp_M: %d %d\n",BatteryTempdata[0],BatteryTempdata[MAX_RECEIVE_DATA-1]);
    printf("Soc_M: %d %d\n",BatterySOCdata[0],BatterySOCdata[MAX_RECEIVE_DATA-1]);
}
