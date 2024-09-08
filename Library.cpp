#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Library.h"

using namespace std;

void Library::Add_book(vector <Book>& books)
{
	Book book;
	cin >> book;
	books.push_back(book);
	//books.push_back({book});
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

void Library::Save_books(vector <Book>& books)
{
	ofstream fout;
	string filename;
	if (books.empty())
	{
		cout << "You do not have book data to save." << endl;
	}
	else
	{
		cout << "Enter filename: ";
		cin >> filename;

		fout.open((filename + ".txt"), ios::trunc);
		if (fout.is_open())
		{
			for (const auto& book : books)
			{
				fout << book << endl;	
			}
			cout << "Data about books is saved to file named " + filename + "." << endl;
		}
		else
		{
			cout << "Could not open file named " + filename + "." << endl;
		}
		fout.close();
	}
}