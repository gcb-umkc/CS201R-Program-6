#pragma once
#include "PrintQueue.h"

class SJFQueue :
    public PrintQueue
{
public:
	//Only needs to implement different add function to sort by shortest
	void AddJob(PrintJob newJob);
};

