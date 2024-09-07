#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "Book.h"

using namespace std;

int main()
{
	vector<Book> books;

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
			Add_book(books);
			break;
		}
		case 2:
		{
			Output_books(books);
			break;
		}
		case 0:
		{
			return false;
		}
		}
	}
}
