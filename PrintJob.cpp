#include "PrintJob.h"
using namespace std;

PrintJob::PrintJob(char type, int pages) {
	this->type = type;
	this->pages = pages;
}

int PrintJob::GetTime() {
	if (serviceTime) {
		//TODO: time calculations
		serviceTime = pages;
	}
	return serviceTime;
}

char PrintJob::GetType() {
	return type;
}

int PrintJob::GetPages() {
	return pages;
}