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

BOOST_CLASS_EXPORT(EBook)