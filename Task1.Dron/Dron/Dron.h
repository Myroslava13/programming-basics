#ifndef Dron_H
#define Dron_H

#include<string>
using namespace std;

class Dron
{
private:
	string makebytechnical; //string = char*
	string modelsrews;
	int year;
public:
	Dron(string makebytechnical = "", string modelsrews4 = "", int year = 0);
	string ToString();
	string GetMake();
	string GetModel();
	string GetYear();


};

#endif // !Dron_H