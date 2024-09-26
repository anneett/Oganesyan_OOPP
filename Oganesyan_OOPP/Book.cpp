#include "Book.h"
#include "Utils.h"

istream& operator >> (istream& in, Book& book)
{
	cout << "Введите название книги: ";
	cin.ignore();
	getline(cin, book.title);
	while (true)
	{
		if (book.title == "")
		{
			cout << "Книга не может не иметь название. Введите название книги: ";
			cin.ignore();
			getline(cin, book.title);
		}
		else
			break;
	}

	cout << "Введите автора книги: ";
	getline(cin, book.author);

	cout << "Введите год выпуска книги. Можно добавить книги с годом выпуска не ранее 1700: ";
	book.release_year = GetCorrectData(1700, 2024);

	cout << "Введите издательство книги: ";
	cin.ignore();
	getline(cin, book.publishing_house);

	cout << "Есть ли книга в наличии: если да, введите 1, если нет, то 0: ";
	book.in_stock = GetCorrectData(0, 1);

	cout << "Введите рейтинг книги: ";
	book.rating = GetCorrectData(0.0, 5.0);
	return in;
}

ostream& operator << (ostream& out, const Book& book)
{
	if (book.title == "")
	{
		cout << "\nНет добавленных книг." << endl;
	}
	else
	{
		cout << "Название: " << book.title
			<< "\nАвтор: " << book.author
			<< "\nГод выпуска: " << book.release_year
			<< "\nИздательство: " << book.publishing_house
			<< "\nВ наличии: " << book.in_stock
			<< "\nРейтинг: " << book.rating << endl;
	}
	return out;
}

ifstream& operator >> (ifstream& fin, Book& book)
{
	getline(fin, book.title);
	getline(fin, book.author);
	fin >> book.release_year;
	fin.ignore();
	getline(fin, book.publishing_house);
	fin >> book.in_stock;
	fin >> book.rating;
	fin.ignore();
	return fin;
}

ofstream& operator << (ofstream& fout, const Book& book)
{
	fout << "Книга" << endl;
	fout << book.title << endl << book.author << endl << book.release_year << endl << book.publishing_house << endl << book.in_stock << endl << book.rating << endl;
	return fout;
}