#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Library.h"

using namespace std;

void Library::Menu()
{
	cout << "\n         МЕНЮ"
		<< "\n1. Добавить книгу;"
		<< "\n2. Просмотреть все книги;"
		<< "\n3. Записать данные в файл;"
		<< "\n4. Загрузить данные из файла;"
		<< "\n5. Очистить список;"
		<< "\n0. Выход." << endl;
	cout << "\nВыберите пункт меню: ";
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
		cout << "У вас нет книг для просмотра." << endl;
	}
	else
		cout << "\nКниги:\n" << endl;
	for (auto& book : books)
		cout << book << endl;
}

void Library::Save_books(vector<Book>& books)
{
	ofstream fout;
	string filename;
	if (books.empty())
	{
		cout << "У вас нет данных для записи в файл." << endl;
	}
	else
	{
		cout << "Введите название файла: ";
		cin >> filename;

		fout.open((filename + ".txt"), ios::trunc);
		if (fout.is_open())
		{
			for (const auto& book : books)
			{
				fout << book << endl;	
			}
			cout << "Данные о книгах записаны в файл с именем " + filename + "." << endl;
		}
		else
		{
			cout << "Не удалось открыть файл " + filename + ".txt." << endl;
		}
		fout.close();
	}
}

void Library::Download_books(vector<Book>& books)
{
	ifstream fin;
	string filename;
	cout << "Введите имя файла: " << endl;
	cin >> filename;
	fin.open((filename + ".txt"));
	if (fin.is_open())
	{
		string line;
		bool p = 0;
		while (getline(fin, line))
		{
			if (line == "Книга")
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
			cout << "Нет данных о книгах." << endl;
		}
		else
		{
			cout << "Данные о книгах загружены из файла." << endl;
		}
	}
	else
	{
		cout << "Не удалось открыть файл с названием " + filename + " или он не существует." << endl;
	}
	fin.close();
}

void Library::Clear(vector<Book>& books)
{
	books.clear();
	cout << "Данные о книгах очищены." << endl;
}
