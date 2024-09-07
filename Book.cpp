#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "Utils.h"

using namespace std;

istream& operator >> (istream& in, Book& book)
{
	cout << "Enter book author: ";
	cin.ignore();
	getline(cin, book.author);

	cout << "Enter book title: ";
	//cin.ignore();
	getline(cin, book.title);

	cout << "Enter year of book release. Если книга вышла до н.э., введите со знаком '-' : ";
	book.rating = GetCorrectData(-868, 2024);

	cout << "Enter publising house: ";
	cin.ignore();
	getline(cin, book.publishing_house);

	cout << "Есть ли книга в наличии: если есть, введите 1, если нет, то 0: ";
	book.in_stock = GetCorrectData(0, 1);

	cout << "Enter book rating: ";
	book.rating = GetCorrectData(0.0, 5.0);
	return in;
}

ostream& operator << (ostream& out, const Book& book)
{
	if (book.title == "")
	{
		cout << "\nNo books added." << endl;
	}
	else
	{
		cout << "Book author: " << book.title
			<< "\nBook title: " << book.author
			<< "\nYear of book release: " << book.release_year
			<< "\nPublishing house of book: " << book.publishing_house
			<< "\nBook in stock: " << book.in_stock
			<< "\nBook rating: " << book.rating << endl;
	}
	return out;
}