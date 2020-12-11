#pragma once
class Clock
{
public:
	//Constructor
	Clock();
	Clock(int initialTime);

	//Accessors
	int GetTime();
	
	//Mutators
	void SetTime(int newTime);
	void Add(int time = 1);
	
	//Other
	Clock operator++(int);

private:
	int currentTicks;
};

