#include "Book.h"
#include "Utils.h"

istream& operator >> (istream& in, Book& book)
{
	cout << "������� �������� �����: ";
	cin.ignore();
	getline(cin, book.title);
	while (true)
	{
		if (book.title == "")
		{
			cout << "����� �� ����� �� ����� ��������. ������� �������� �����: ";
			cin.ignore();
			getline(cin, book.title);
		}
		else
			break;
	}

	cout << "������� ������ �����: ";
	getline(cin, book.author);

	cout << "������� ��� ������� �����. ����� �������� ����� � ����� ������� �� ����� 1700: ";
	book.release_year = GetCorrectData(1700, 2024);

	cout << "������� ������������ �����: ";
	cin.ignore();
	getline(cin, book.publishing_house);

	cout << "���� �� ����� � �������: ���� ��, ������� 1, ���� ���, �� 0: ";
	book.in_stock = GetCorrectData(0, 1);

	cout << "������� ������� �����: ";
	book.rating = GetCorrectData(0.0, 5.0);
	return in;
}

ostream& operator << (ostream& out, const Book& book)
{
	if (book.title == "")
	{
		cout << "\n��� ����������� ����." << endl;
	}
	else
	{
		cout << "��������: " << book.title
			<< "\n�����: " << book.author
			<< "\n��� �������: " << book.release_year
			<< "\n������������: " << book.publishing_house
			<< "\n� �������: " << book.in_stock
			<< "\n�������: " << book.rating << endl;
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
	fout << "�����" << endl;
	fout << book.title << endl << book.author << endl << book.release_year << endl << book.publishing_house << endl << book.in_stock << endl << book.rating << endl;
	return fout;
}