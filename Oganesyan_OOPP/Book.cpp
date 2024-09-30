#include "Utils.h"
#include "Book.h"

void Book::Output(ostream& out) const
{
	if (title == "")
	{
		out << "\nНет добавленных книг." << endl;
	}
	else
	{
		out << "Название: " << title
			<< "\nАвтор: " << author
			<< "\nГод выпуска: " << release_year
			<< "\nИздательство: " << publishing_house
			<< "\nВ наличии: " << in_stock
			<< "\nРейтинг: " << rating << endl;
	}
}


void Book::Input(istream& in)
{
	cout << "Введите название книги: ";
	in.ignore();
	getline(in, title);

	while (title.empty())
	{
		cout << "Книга не может не иметь название. Введите название книги: ";
		getline(in, title);
	}

	cout << "Введите автора книги: ";
	getline(in, author);

	cout << "Введите год выпуска книги. Можно добавить книги с годом выпуска не ранее 1700: ";
	release_year = GetCorrectData(1700, 2024);

	cout << "Введите издательство книги: ";
	in.ignore();
	getline(in, publishing_house);

	while (publishing_house.empty())
	{
		cout << "Книга не может не издательства. Введите издательство книги: ";
		getline(in, publishing_house);
	}

	cout << "Есть ли книга в наличии: если да, введите 1, если нет, то 0: ";
	in_stock = GetCorrectData(0, 1);

	cout << "Введите рейтинг книги (от 0.0 до 5.0): ";
	rating = GetCorrectData(0.0, 5.0);
}

BOOST_CLASS_EXPORT(Book)