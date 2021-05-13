#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getLinesCount1(string fileName)
{
	ifstream input("in1.txt");
	int count1 = 0;
	for (std::string line; getline(input, line); )
	{
		count1++;
	}
	return count1;
}

int main()
{
	int b1 = getLinesCount1("in1.txt");
	int b2 = getLinesCount1("in2.txt");
	int b3 = getLinesCount1("in3.txt");
	int i = 0;


	string* arr1 = new string[b1];
	string* arr2 = new string[b2];
	string* arr3 = new string[b3];

	ifstream input("in1.txt");
	for (std::string line; getline(input, line); )
	{
		arr1[i] = line;
		i++;
	}

	i = 0;
	ifstream input2("in2.txt");
	for (std::string line; getline(input2, line); )
	{
		arr2[i] = line;
		i++;
	}

	ifstream input3("in3.txt");
	for (std::string line; getline(input2, line); )
	{
		arr3[i] = line;
		i++;
	}

	ofstream fout1;
	fout1.open("out.txt");

	for (int i = 0; i < b1; i++)
	{
		for (int j = i; j < b2; j++)
		{
			for (int k = j; k < b3;k++) {

			
				if (arr1[i] == arr2[j] && arr1[i] == arr3[k] ) {
					fout1 << arr1[i] << endl;
				}
			}
		}
	}

	fout1.close();

	return 0;
}
