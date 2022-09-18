

void Receiver(int file_directory[], char receive_BMSdata[], int dataLength)
{
	memset(receive_BMSdata, '\0', dataLength);
		
	close(file_directory[1]);
		
	read(file_directory[0], receive_BMSdata, dataLength);
		
	close(file_directory[0]);
	//printf("Receiver: %s",receive_BMSdata);
}
