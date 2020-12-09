#pragma once
class Clock
{
public:
	//Constructor
	Clock();
	Clock(int initialTime);

	//Accessors
	int GetTime();
	
	//Mutataors
	void SetTime(int newTime);
	int Add(int time = 1);
	
private:
	int currentTicks;
};

