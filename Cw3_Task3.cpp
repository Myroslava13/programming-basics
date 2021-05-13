#include <iostream>
using namespace std;

struct Straight_line
{
	double y;
	double x;
	double k;
	double b;

	Straight_line(double x, double y, double k, double b)
	{
		this->x = x;
		this->y = y;
		this->k = k;
		this->b = b;
	}

	void verification()
	{
		if (y == (k * x) + b)
		{
			cout << "Belongs to" << endl;
		}
		else
		{
			cout << "Does not belong" << endl;
		}
	}

};

int main()
{
	Straight_line Line1(2, 3, -1, 1);
	Line1.verification();


	system("pause");
	return 0;
}
