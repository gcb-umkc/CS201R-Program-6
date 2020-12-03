#pragma once
class PrintJob
{
public:
	//Constructors
	PrintJob();
	PrintJob(int time, char type, int pages) : time(time), type(type), pages(pages) {};

	//Accessors
	int GetTime();
	char GetType();
	int GetPages();

private:
	int time;
	char type;
	int pages;
};

