#include"fun.h"
#include<iostream>
using namespace std;


void read_line(char*& line, int n) {
	cout << "enter line: " << endl;
	cin >> line;
}
void print_line(char* line, int n) {
	cout << line << endl;
	
}
void change(char*& line, int n) {
	int k = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (line[i] >= 'a' && line[i] <= 'z') {
			k++;

		}
		else
			m++;
	}
	if (k > m) {
		for (int i = 0; i < n; i++) {
			line[i] = tolower(line[i]);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			line[i] = toupper(line[i]);
		}
	}
}