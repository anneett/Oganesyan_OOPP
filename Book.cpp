#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"

using namespace std;


istream& operator >> (istream& in, Book& book)
{
	cout << "Enter book title: ";
	cin.ignore();
	getline(cin, book.title);
	cout << "Enter book author: ";
	//cin.ignore();
	getline(cin, book.author);

	cout << "Enter year of book release. Если книга вышла до н.э., введите со знаком '-' : ";
	book.rating = GetCorrectData(-868, 2024);
	cout << "Enter publising house: ";
	//cin.ignore();
	getline(cin, book.publishing_house);

	cout << "Есть ли книга в наличии: если есть, введите 1, если нет, то 0: ";
	book.in_stock = GetCorrectData(0, 1);

	cout << "Enter book rating: ";
	book.rating = GetCorrectData(0.0, 5.0);
	return in;
}

//ostream& operator << (ostream& out, const Truba& tb)
//{
//	if (tb.length == 0)
//	{
//		cout << "\nNo pipes added." << endl;
//	}
//	else
//	{
//		cout << "Pipe MaxID: " << tb.max_idp
//			<< "\nPipe ID: " << tb.idpipe
//			<< "\nPipe mark: " << tb.mark
//			<< "\nPipe length: " << tb.length
//			<< "\nPipe diameter: " << tb.diameter
//			<< "\nThe pipe attribute: " << tb.repair
//			<< "\nThe free parameter: " << tb.free << endl;
//	}
//	return out;
//}