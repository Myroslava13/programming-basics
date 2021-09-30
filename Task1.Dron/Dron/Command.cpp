#include"Command.h"
#include"Dron.h"
#include"Error.h"
#include<iostream>
using namespace std;

Command::Command(int maxCapacity)
{
	drons = new Dron[maxCapacity];
	this->maxCapacity = maxCapacity;
	currentCapacity = 0;


}
Command::~Command()
{

	delete[] drons;
}

void Command::AddDron(Dron& dron)
{
	if (currentCapacity >= maxCapacity)
		throw Error(ErrorCode::MaxSizeReached);

	drons[currentCapacity++] = dron;
}

void Command::RemoveDron(int idx)
{
	if (idx < 0 || idx >= currentCapacity)
		throw Error(ErrorCode::IdxOutsideLimit);

	for (int i = idx; i < (currentCapacity - 1); i++)
		drons[i] = drons[i + 1];

	currentCapacity--;
}
void Command::PrintDrons()
{
	cout << "Drons:\n";
	for (int i = 0; i < currentCapacity; i++)
	{
		cout << i << "--" << drons[i].ToString() << endl;
	}
}

string Command::GetMostPopularDronMake()
{

	return drons[0].GetMake();
}
string Command::GetMostPopularDronModel()
{

	return drons[0].GetModel();
}
string Command::GetMostPopularDronYear()
{

	return drons[0].GetYear();
}


