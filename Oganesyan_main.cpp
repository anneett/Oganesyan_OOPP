#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
//#include "Utils.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
	vector<Book*> books;
	Library library;

	while (true) {
		
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		library.Menu();
		int number = GetCorrectData(0, 5);
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
		case 3:
		{
			library.Save_books(books);
			break;
		}
		case 4:
		{
			library.Download_books(books);
			break;
		}
		case 5:
		{
			library.Clear(books);
			break;
		}
		case 0:
		{
			return false;
		}
		}
	}
}
