#include "Dron.h"
#include"Error.h"
#include <string>
using namespace std;

Dron::Dron(string makebytechnical, string modelsrews, int Pricedron)
{
	(*this).makebytechnical = makebytechnical;
	this->modelsrews = modelsrews;
	if (Pricedron < 0)
		throw Error(ErrorCode::NegativeYear);

	year = Pricedron;
}

string Dron::ToString()
{
	return "Car: " + makebytechnical + " " + modelsrews + " " + to_string(year);
}

string Dron::GetMake()
{
	return makebytechnical;
}
string Dron::GetModel()
{
	return modelsrews;
}
string Dron::GetYear()
{
	return to_string(year);
}