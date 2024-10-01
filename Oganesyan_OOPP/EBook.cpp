#include "Utils.h"
#include "EBook.h"

BOOST_CLASS_EXPORT(EBook)

void EBook::Input(istream& in)
{
    Book::Input(in);

    cout << "Введите ссылку на сайт с электронной книгой: ";
    in >> link;

    while (link.empty())
    {
        cout << "У электронной книги должна быть ссылка на сайт. Введите ссылку на сайт: ";
        in >> link;
    }
}

void EBook::Output(ostream& out) const
{
    Book::Output(out);
    out << "Ссылка на книгу: " << link << endl;
}