#include "Boost.h"
#include "Utils.h"
#include "Library.h"

int main()
{
	Library library;

	while (true) {
		
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		
		cout << "\n         МЕНЮ"
			<< "\n1. Добавить книгу;"
			<< "\n2. Добавить электронную книгу;"
			<< "\n3. Просмотреть все книги;"
			<< "\n4. Записать данные в файл;"
			<< "\n5. Загрузить данные из файла;"
			<< "\n6. Очистить список;"
			<< "\n0. Выход." << endl;
		cout << "\nВыберите пункт меню: ";

		int number = GetCorrectData(0, 6);
		switch (number)
		{
		case 1:
		{
			library.Add_book();
			break;
		}
		case 2:
		{
			library.Add_EBook();
			break;
		}
		case 3:
		{
			library.Output_books();
			break;
		}
		case 4:
		{
			library.Save_books("books.dat");
			break;
		}
		case 5:
		{
			library.Load_books("books.dat");
			break;
		}
		case 6:
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
