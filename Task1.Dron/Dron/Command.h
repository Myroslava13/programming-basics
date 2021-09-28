#ifndef COMMAND_H
#define COMMAND_H
#include"Dron.h"

class Command {
	Dron* drons;
	int maxCapacity;
	int currentCapacity;



public:
	Command(int maxCapacity = 100);
	~Command();
	void AddDron(Dron& dron);
	void RemoveDron(int idx);
	void PrintDrons();
	string GetMostPopularDronMake();
	string GetMostPopularDronModel();
	string GetMostPopularDronYear();
};

#endif