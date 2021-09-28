#include"Menu.h"
#include"Dron.h"
#include"Error.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::ShowMenu()
{
	char userInput;

	do {
		showMainMenu();
		cin >> userInput;
		safeHandleUserInput(userInput);

		cout << endl;
	} while (userInput != '0');
}

void Menu::showMainMenu()
{
	cout << "Drone Manufacturing\nPlease select an option:\n";
	cout << "1 - Add new dron;\n";
	cout << "2 - Print dron;\n";
	cout << "3 - Remove dron;\n";
	cout << "4 - Get most popular dron make;\n";
	cout << "5-Most popular dron model;\n";
	cout << "6-Most popular year model;\n";
	cout << "0 - Exit.\n";
}

void Menu::showAndHadnleAddDronMenu()
{
	string makebytechnical, modelsrews;
	int price;

	cout << "Make by technical:\n";
	cin >> makebytechnical;
	cout << " The model depends on the number screws :\n";
	cin >> modelsrews;
	cout << "Price:\n";
	cin >> price;

	Dron dron(makebytechnical, modelsrews, price);
	command.AddDron(dron);

	cout << "Dron Added!!!\n";
}

void Menu::showAndHadnleRemoveDronMenu()
{
	int idx;
	cout << "Type dron id\n";
	cin >> idx;

	command.RemoveDron(idx);
	cout << "Dron Removed!!!\n";
}

void Menu::safeHandleUserInput(char userInput)
{
	try
	{
		handleUserInput(userInput);
	}
	catch (Error& error)
	{

		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "Some error occurs" << endl;
	}
}

void Menu::handleUserInput(char userInput)
{
	switch (userInput)
	{
	case '1':
		showAndHadnleAddDronMenu();
		break;
	case '2':
		command.PrintDrons();
		cout << endl;
		break;
	case '3':
		showAndHadnleRemoveDronMenu();
		break;
	case '4':
		cout << "Most popular dron make is " << command.GetMostPopularDronMake() << endl;
		break;
	case '5':
		cout << "Most popular dron model is " << command.GetMostPopularDronModel() << endl;
		break;
	case '6':
		cout << "Most popular year is " << command.GetMostPopularDronYear() << endl;
		break;

	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}