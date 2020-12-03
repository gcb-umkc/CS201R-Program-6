#include "PrintJob.h"

PrintJob::PrintJob() {
	time = 0;
	type = ' ';
	pages = 0;
}

int PrintJob::GetTime() {
	return time;
}

char PrintJob::GetType() {
	return type;
}

int PrintJob::GetPages() {
	return pages;
}