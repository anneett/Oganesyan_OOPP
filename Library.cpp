#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Library.h"

using namespace std;

void Library::Add_book()
{
    Book* book = new Book;
    cin >> *book;
    books.push_back(book);
}

void Library::Output_books()
{
    if (books.empty())
    {
        cout << "� ��� ��� ���� ��� ���������." << endl;
    }
    else
    {
        cout << "\n�����:\n" << endl;
        for (const auto& book : books)
        {
            cout << *book << endl;
        }
    }
}

void Library::Save_books()
{
    ofstream fout;
    string filename;
    if (books.empty())
    {
        cout << "� ��� ��� ������ ��� ������ � ����." << endl;
    }
    else
    {
        cout << "������� �������� �����: ";
        cin.ignore();
        getline(cin, filename);

        fout.open((filename + ".txt"), ios::trunc);
        if (fout.is_open())
        {
            for (const auto& book : books)
            {
                fout << *book << endl;
            }
            cout << "������ � ������ �������� � ���� � ������ " + filename + "." << endl;
        }
        else
        {
            cout << "�� ������� ������� ���� " + filename + ".txt." << endl;
        }
        fout.close();
    }
}

void Library::Download_books()
{
    ifstream fin;
    string filename;
    cout << "������� ��� �����: ";
    cin.ignore();
    getline(cin, filename);
    fin.open((filename + ".txt"));
    if (fin.is_open())
    {
        Clear();
        string line;
        bool p = false;
        while (getline(fin, line))
        {
            if (line == "�����")
            {
                Book* book = new Book;
                books.push_back(book);
                fin >> *book;
                if (!fin)
                {
                    cout << "�������� ������ �����." << endl;
                    Clear();
                    fin.close();
                    return;
                }
                p = true;
            }
        }
        if (!p)
        {
            cout << "��� ������ � ������." << endl;
        }
        else
        {
            cout << "������ � ������ ��������� �� �����." << endl;
        }
    }
    else
    {
        cout << "�� ������� ������� ���� � ��������� " + filename + " ��� �� �� ����������." << endl;
    }
    fin.close();
}

void Library::Clear()
{
    for (auto& book : books)
    {
        delete book;
    }
    books.clear();
    cout << "������ � ������ �������." << endl;
}
