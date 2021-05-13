#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct University {
    string Name;
    string City;
    int Year;
    int Number;
};

University* getUniversity(string s) {
    string delimiter = ",";
    size_t pos = 0;
    University* newp = new University();
    int currentProp = 0;

    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        if (currentProp == 0) {
            newp->Name = token;
            currentProp++;
        }
        else if (currentProp == 1) {
            newp->City = token;
            currentProp++;
        }
        else if (currentProp == 2) {
            newp->Year = stoi(token);
            currentProp++;
        }
        else if (currentProp == 3) {
            newp->Number = stoi(token);
        }
        s.erase(0, pos + delimiter.length());
    }

    return newp;
}

int getLinesCount(string fileName)
{
    std::ifstream input(fileName);
    int count = 0;
    for (std::string line; getline(input, line); )
    {
        count++;
    }
    return count;
}

University* readUniversitys(string fileName, int linesCount)
{
    University* universitys = new University[linesCount];
    std::ifstream input(fileName);
    int i = 0;
    for (std::string line; getline(input, line); )
    {
        University* p = getUniversity(line);
        universitys[i] = *p;
        i++;
    }
    return universitys;
}

University* sort(University* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].City > arr[j + 1].City)
            {
                auto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (arr[j].City == arr[j + 1].City)
            {
                if (arr[j].Number < arr[j + 1].Number) {
                    auto temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    return arr;
}

University* printyears(University* arr, int n)
{
    University* years = arr;
    for (int i = 0; i < n; i++) {
        if (years->Year > arr[i].Year)
        {
            years = &arr[i];
        }
    }
    cout << years->Name + " " + years->City;
    return years;
}


void printUniversitys(University* arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i].Name + " " + arr[i].City;
        cout << endl;
    }
}

int main() {
    string fileName = "university_in.txt";
    int linesCount = getLinesCount(fileName);
    University* unuversitys = readUniversitys(fileName, linesCount);
    printUniversitys(universitys, linesCount);

    University* sortedUniversitys = sort(universitys, linesCount);
    ofstream fout1;
    fout1.open("university_out.txt");
    for (int i = 0; i < linesCount; i++) {
        fout1 << sortedUniversitys[i].Name + " " + sortedUniversitys[i].City << endl;
    }
    fout1.close();

    cout << "Oldest university: ";
    printyears(universitys, linesCount);

    int t;
    cin >> t;
    return 0;
}
