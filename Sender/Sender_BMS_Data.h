#define MAX_VALUE   50
#define TEMP_RANGE  50
#define SOC_RANGE   50
#define CHAR_MAX    256
typedef struct {
	int Temperature[MAX_VALUE];
	int Soc[MAX_VALUE];
} sensorValue;
void DisplayToConsole(char* buffer);
int GenerateSensorData(int Datasize,sensorValue *sensorData);
