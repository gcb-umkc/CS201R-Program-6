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

private:
	int serviceTime = this->GetTime();
	int waitingTime;
	char type;
	int pages;
};

