#include "Utils.h"
#include "EBook.h"

void EBook::Input(istream& in)
{
    Book::Input(in);

    cout << "������� ������ �� ���� � ����������� ������: ";
    in >> link;

    while (link.empty())
    {
        cout << "� ����������� ����� ������ ���� ������ �� ����. ������� ������ �� ����: ";
        in >> link;
    }
}

void EBook::Output(ostream& out) const
{
    Book::Output(out);
    out << "������ �� �����: " << link << endl;
}

//ifstream& operator >> (ifstream& fin, Book& book)
//{
//	getline(fin, book.title);
//	getline(fin, book.author);
//	fin >> book.release_year;
//	fin.ignore();
//	getline(fin, book.publishing_house);
//	fin >> book.in_stock;
//	fin >> book.rating;
//	fin.ignore();
//	return fin;
//}

//ofstream& operator << (ofstream& fout, const Book& book)
//{
//	fout << "�����" << endl;
//	fout << book.title << endl << book.author << endl << book.release_year << endl << book.publishing_house << endl << book.in_stock << endl << book.rating << endl;
//	return fout;
//}