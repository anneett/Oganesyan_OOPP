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
		
		cout << "\n         ����"
			<< "\n1. �������� �����;"
			<< "\n2. ����������� ��� �����;"
			<< "\n3. �������� ������ � ����;"
			<< "\n4. ��������� ������ �� �����;"
			<< "\n5. �������� ������;"
			<< "\n0. �����." << endl;
		cout << "\n�������� ����� ����: ";

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
