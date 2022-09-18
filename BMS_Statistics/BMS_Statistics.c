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

int movingAverage_of_Tempdata(int BatteryTempdata[])
{
    int AvgofTemp = 0;
    
    for(int index = MAX_RECEIVE_DATA - 5; index < MAX_RECEIVE_DATA; index++)
    {
       AvgofTemp +=  BatteryTempdata[index];
       //printf("avg: %d \n",index);
    }
    AvgofTemp /= 5;
    
    return AvgofTemp;
    //printf("avg: %d ",AvgofTemp);
}

int movingAverage_of_SOCdata(int BatterySOCdata[])
{
    int AvgofSoc = 0;
    
    for(int index = MAX_RECEIVE_DATA - 5; index < MAX_RECEIVE_DATA; index++)
    {
       AvgofSoc +=  BatterySOCdata[index];
       //printf("avg: %d \n",index);
    }
    AvgofSoc /= 5;
    
    return AvgofSoc;
    //printf("avg: %d",AvgofSoc);
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
       printf("Temp: %d \n",BatteryTempdata[BMSTempIndex]);
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
       printf("SOC: %d \n",BatterySOCdata[BMSSocIndex]);
       ++BMSSocIndex;
       BMSdataIndex = 0;
       memset(BMSdata, '\0', BMSData_length);
    }
}

void print_movingAvgData(int AvgOfTemp, int AvgOfSoc)
{
	printf("Avg of Temp: %d Soc: %d\n",AvgOfTemp,AvgOfSoc);
}

void print_Temp_MinMaxData(int minTempData, int maxTempData)
{
	printf("Temp min value: %d max value: %d\n", minTempData, maxTempData);
}

void print_Soc_MinMaxData(int minSocData, int maxSocData)
{
	printf("Soc min value: %d max value: %d\n", minSocData, maxSocData);
}

void BMSData_Statistics(char receive_BMSdata[], int datasize)
{
    int BatteryTempdata[50];
    int BatterySOCdata[50];
    int AvgofTemp = 0, AvgofSOC = 0;;
    
    convertString_To_Int(receive_BMSdata,datasize,BatteryTempdata,BatterySOCdata);
	
    AvgofTemp = movingAverage_of_Tempdata(BatteryTempdata);
    AvgofSOC = movingAverage_of_SOCdata(BatterySOCdata);
	
    print_movingAvgData(AvgofTemp, AvgofSOC);
	
    sortBmsData(BatteryTempdata, BatterySOCdata);
	
    print_Temp_MinMaxData(BatteryTempdata[0],BatteryTempdata[MAX_RECEIVE_DATA-1]);
    print_Soc_MinMaxData(BatterySOCdata[0],BatterySOCdata[MAX_RECEIVE_DATA-1]);
	
}
