#pragma once
class PrintJob
{
public:
	//Constructors
	PrintJob();
	PrintJob(int arrivalTime, char type, int pages);

	//Accessors
	char GetType();
	int GetPages();
	int GetTime();
	int GetArrival();
	int GetServiceTime();

private:
	char type;
	int pages;
	int serviceTime, arrivalTime;
};

