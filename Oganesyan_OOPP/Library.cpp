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
        cout << "У вас нет книг для просмотра." << endl;
    }
    else
    {
        cout << "\nКниги:" << endl;
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
        cout << "У вас нет данных для записи в файл." << endl;
    }
    else
    {
        cout << "Введите название файла: ";
        cin.ignore();
        getline(cin, filename);
        fout.open((filename + ".dat"));
        if (fout.is_open())
        {
            boost::archive::binary_oarchive oa(fout);
            oa << books;
            cout << "Данные загружеы в файл с названием " + filename + ".dat." << endl;
            fout.close();
        }
        else
        {
            cout << "Не удалось открыть файл " + filename + ".dat." << endl;
        }
        fout.close();
    }
}

void Library::Load_books()
{
    string filename;
    ifstream fin(filename, ifstream::binary);
    
    cout << "Введите название файла для загрузки: ";
    cin.ignore();
    getline(cin, filename);
    fin.open((filename + ".dat"));
    if (fin.is_open())
    {
        try {
            boost::archive::binary_iarchive ia(fin);
            ia >> books;
            cout << "Данные успешно загружены." << endl;
        }
        catch (const exception& e) {
            cout << "Ошибка чтения из файла: " << e.what() << "." << endl;
            Clear();
            fin.close();
            return;
        }
    }
    else
    {
        cout << "Не удалось открыть файл с названием " + filename + ".dat." << endl;
    }
    fin.close();
}

void Library::Clear()
{
    books.clear();
    cout << "Данные о книгах очищены." << endl;
}
