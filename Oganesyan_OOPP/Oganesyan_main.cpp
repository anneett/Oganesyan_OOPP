#include "Boost.h"
#include "Utils.h"
#include "Library.h"

int main()
{
	Library library;

	while (true) {
		
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		
		cout << "\n         ����"
			<< "\n1. �������� �����;"
			<< "\n2. �������� ����������� �����;"
			<< "\n3. ����������� ��� �����;"
			<< "\n4. �������� ������ � ����;"
			<< "\n5. ��������� ������ �� �����;"
			<< "\n6. �������� ������;"
			<< "\n0. �����." << endl;
		cout << "\n�������� ����� ����: ";

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
