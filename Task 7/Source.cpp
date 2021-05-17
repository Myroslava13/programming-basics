#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;
	if (n <= 2)
	{
		cout << "Error\n";
		system("pause");
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n + i; j++)
		{
			cout << j % n*2  << " ";
		}
		cout << endl;

	}
	return 0;
	system("pause");
}
