#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"

using namespace std;

int main()
{
	//vector<Books> library;

	while (true) {
		cout << "\nSelect menu item: "
			<< "\n1. Add book;"
			<< "\n2. View all books;"
			<< "\n0. Exit." << endl;
		cout << "\nSelect: ";

		int number = GetCorrectData(0, 2);
		switch (number)
		{
		case 1:
		{
			//gts.Add_pipe(pipes);
			break;
		}
		case 0:
		{
			return false;
		}
		}
	}
}
