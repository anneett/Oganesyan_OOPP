#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
	vector<Book> books;
	Library library;

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
			library.Add_book(books);
			break;
		}
		case 2:
		{
			library.Output_books(books);
			break;
		}
		case 0:
		{
			return false;
		}
		}
	}
}
