#pragma once
class PrintJob
{
public:
	//Constructors
	PrintJob(char type, int pages);

	//Accessors
	char GetType();
	int GetPages();
	int GetTime();

	//Mutators
	PrintJob operator++(int);

private:
	int serviceTime;
	int waitingTime;
	char type;
	int pages;
};

