#include"fun.h"
#include<iostream>
using namespace std;

void main() {
	int m;
	cout << "m = ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		int n;
		cout << "n = ";
		cin >> n;
		char* line = new char[n];

		read_line(line, n);
		change(line, n);
		print_line(line, n);
	}
}