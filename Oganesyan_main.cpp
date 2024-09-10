#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Utils.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
	Library library;

	while (true) {
		
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		
		cout << "\n         МЕНЮ"
			<< "\n1. Добавить книгу;"
			<< "\n2. Просмотреть все книги;"
			<< "\n3. Записать данные в файл;"
			<< "\n4. Загрузить данные из файла;"
			<< "\n5. Очистить список;"
			<< "\n0. Выход." << endl;
		cout << "\nВыберите пункт меню: ";

		int number = GetCorrectData(0, 5);
		switch (number)
		{
		case 1:
		{
			library.Add_book();
			break;
		}
		case 2:
		{
			library.Output_books();
			break;
		}
		case 3:
		{
			library.Save_books();
			break;
		}
		case 4:
		{
			library.Download_books();
			break;
		}
		case 5:
		{
			library.Clear();
			break;
		}
		case 0:
		{
			return false;
		}
		}
	}
}
