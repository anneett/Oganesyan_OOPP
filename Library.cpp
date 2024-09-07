#include <iostream>
#include "Utils.h"
#include "Library.h"

using namespace std;

void Library::Add_book(vector <Book>& books)
{
	Book book;
	cin >> book;
	books.push_back(book);
}

void Library::Output_books(vector <Book>& books)
{
	if (books.size() == 0)
	{
		cout << "You don't have books to watch." << endl;
	}
	else
		cout << "\nBooks:\n" << endl;
	for (auto& book : books)
		cout << book << endl;
}