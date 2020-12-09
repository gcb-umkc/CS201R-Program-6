#include "PrintQueue.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

PrintQueue::PrintQueue() {

}

void PrintQueue::SetWaitingTime(int waitingTime) {

}

int PrintQueue::GetWaitingTime() {
	return waitingTime;
}

void PrintQueue::SetBusy(bool newState) {
	busy = newState;
}

void PrintQueue::addJob(PrintJob newJob) {

}

void PrintQueue::removeJob() {

}

void PrintQueue::sort() {

}

void PrintQueue::readData(string fileName) {
	ifstream input;
	input.open(fileName);


	input.close();
}