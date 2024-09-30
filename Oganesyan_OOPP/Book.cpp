#include "Utils.h"
#include "Book.h"

void Book::Output(ostream& out) const
{
	if (title == "")
	{
		out << "\n��� ����������� ����." << endl;
	}
	else
	{
		out << "��������: " << title
			<< "\n�����: " << author
			<< "\n��� �������: " << release_year
			<< "\n������������: " << publishing_house
			<< "\n� �������: " << in_stock
			<< "\n�������: " << rating << endl;
	}
}


void Book::Input(istream& in)
{
	cout << "������� �������� �����: ";
	in.ignore();
	getline(in, title);

	while (title.empty())
	{
		cout << "����� �� ����� �� ����� ��������. ������� �������� �����: ";
		getline(in, title);
	}

	cout << "������� ������ �����: ";
	getline(in, author);

	cout << "������� ��� ������� �����. ����� �������� ����� � ����� ������� �� ����� 1700: ";
	release_year = GetCorrectData(1700, 2024);

	cout << "������� ������������ �����: ";
	in.ignore();
	getline(in, publishing_house);

	while (publishing_house.empty())
	{
		cout << "����� �� ����� �� ������������. ������� ������������ �����: ";
		getline(in, publishing_house);
	}

	cout << "���� �� ����� � �������: ���� ��, ������� 1, ���� ���, �� 0: ";
	in_stock = GetCorrectData(0, 1);

	cout << "������� ������� ����� (�� 0.0 �� 5.0): ";
	rating = GetCorrectData(0.0, 5.0);
}

BOOST_CLASS_EXPORT(Book)