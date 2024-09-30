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

void Library::Save_books()
{
    string filename;
    ofstream fout(filename, ofstream::binary);
    if (books.empty())
    {
        cout << "� ��� ��� ������ ��� ������ � ����." << endl;
    }
    else
    {
        cout << "������� �������� �����: ";
        cin.ignore();
        getline(cin, filename);
        fout.open((filename + ".dat"));
        if (fout.is_open())
        {
            boost::archive::binary_oarchive oa(fout);
            oa << books;
            cout << "������ �������� � ���� � ��������� " + filename + ".dat." << endl;
            fout.close();
        }
        else
        {
            cout << "�� ������� ������� ���� " + filename + ".dat." << endl;
        }
        fout.close();
    }
}

void Library::Load_books()
{
    string filename;
    ifstream fin(filename, ifstream::binary);
    
    cout << "������� �������� ����� ��� ��������: ";
    cin.ignore();
    getline(cin, filename);
    fin.open((filename + ".dat"));
    if (fin.is_open())
    {
        try {
            boost::archive::binary_iarchive ia(fin);
            ia >> books;
            cout << "������ ������� ���������." << endl;
        }
        catch (const exception& e) {
            cout << "������ ������ �� �����: " << e.what() << "." << endl;
            Clear();
            fin.close();
            return;
        }
    }
    else
    {
        cout << "�� ������� ������� ���� � ��������� " + filename + ".dat." << endl;
    }
    fin.close();
}

void Library::Clear()
{
    books.clear();
    cout << "������ � ������ �������." << endl;
}
