#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Library.h"

using namespace std;

void Library::Menu()
{
	cout << "\n         ����"
		<< "\n1. �������� �����;"
		<< "\n2. ����������� ��� �����;"
		<< "\n3. �������� ������ � ����;"
		<< "\n4. ��������� ������ �� �����;"
		<< "\n5. �������� ������;"
		<< "\n0. �����." << endl;
	cout << "\n�������� ����� ����: ";
}

void Library::Add_book(vector<Book>& books)
{
	Book book;
	cin >> book;
	books.push_back(book);
	//books.push_back({book});
}

void Library::Output_books(vector<Book>& books)
{
	if (books.size() == 0)
	{
		cout << "� ��� ��� ���� ��� ���������." << endl;
	}
	else
		cout << "\n�����:\n" << endl;
	for (auto& book : books)
		cout << book << endl;
}

void Library::Save_books(vector<Book>& books)
{
	ofstream fout;
	string filename;
	if (books.empty())
	{
		cout << "� ��� ��� ������ ��� ������ � ����." << endl;
	}
	else
	{
		cout << "������� �������� �����: ";
		cin >> filename;

		fout.open((filename + ".txt"), ios::trunc);
		if (fout.is_open())
		{
			for (const auto& book : books)
			{
				fout << book << endl;	
			}
			cout << "������ � ������ �������� � ���� � ������ " + filename + "." << endl;
		}
		else
		{
			cout << "�� ������� ������� ���� " + filename + ".txt." << endl;
		}
		fout.close();
	}
}

void Library::Download_books(vector<Book>& books)
{
	ifstream fin;
	string filename;
	cout << "������� ��� �����: " << endl;
	cin >> filename;
	fin.open((filename + ".txt"));
	if (fin.is_open())
	{
		string line;
		bool p = 0;
		while (getline(fin, line))
		{
			if (line == "�����")
			{
				Book book;
				fin >> book;
				books.push_back(book);
				//books.pushback({book});
				p = 1;
			}
		}
		if (!p)
		{
			cout << "��� ������ � ������." << endl;
		}
		else
		{
			cout << "������ � ������ ��������� �� �����." << endl;
		}
	}
	else
	{
		cout << "�� ������� ������� ���� � ��������� " + filename + " ��� �� �� ����������." << endl;
	}
	fin.close();
}

void Library::Clear(vector<Book>& books)
{
	books.clear();
	cout << "������ � ������ �������." << endl;
}
