#include "Clock.h"


Clock::Clock() {
	this->currentTicks = 0;
}

Clock::Clock(int initialTime) {
	this->currentTicks = initialTime;
}

void Clock::Add(int time) {
	this->currentTicks += time;
}

int Clock::GetTime() {
	return currentTicks;
}

void Clock::SetTime(int newTime) {
	this->currentTicks = newTime;
}

Clock Clock::operator++(int) {
	this->Add();
	return *this;
}