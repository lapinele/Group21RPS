#include "validInput.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int main()
{
	string userStr;
	char userChar;
	char yn[] = {'y','n'};
	char rpse[] = {'r','p','s','e'};

	cout << "Please enter either y or n" << endl;
	getline(cin, userStr);
	userChar = validInput(userStr, yn, 2);
	cout << "User chooses " << userChar << endl;

	cout << "Please enter either r, p, s, or e" << endl;
	getline(cin, userStr);
	userChar = validInput(userStr, rpse, 2);
	cout << "User chooses " << userChar << endl;

	return 0;
}
