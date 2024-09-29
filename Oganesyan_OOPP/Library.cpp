#include "Utils.h"
#include "Library.h"
#include "EBook.h"

void Library::Add_book()
{
    shared_ptr<Book> book = make_shared<Book>();
    book->Input(cin);
    books.push_back(book); 
}

void Library::Add_EBook()
{
    shared_ptr<EBook> e_book = make_shared<EBook>();
    e_book->Input(cin);
    books.push_back(e_book);
}

void Library::Output_books()
{
    if (books.empty())
    {
        cout << "� ��� ��� ���� ��� ���������." << endl;
    }
    else
    {
        cout << "\n�����:" << endl;
        for (const auto& book : books)
        {
            book->Output(cout << endl);
        }
    }
}

void Library::Save_books(const std::string& filename) {
    std::ofstream ofs(filename);
    boost::archive::text_oarchive oa(ofs);
    oa << books; // ������������ ������� ���������� �� ������� � ����������� ������
}

void Library::Load_books(const std::string& filename) {
    std::ifstream ifs(filename);
    boost::archive::text_iarchive ia(ifs);
    ia >> books; // �������������� ������� ����������
}

void Library::Clear()
{
    books.clear();
    cout << "������ � ������ �������." << endl;
}
