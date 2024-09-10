#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Library.h"

using namespace std;

void Library::Menu()
{
    cout << "\n         ����"
        << "\n1. �������� �����;"
        << "\n2. ����������� ��� �����;"
        << "\n3. �������� ������ � ����;"
        << "\n4. ��������� ������ �� �����;"
        << "\n5. �������� ������;"
        << "\n0. �����." << endl;
    cout << "\n�������� ����� ����: ";
}

void Library::Add_book(vector<Book*>& books)
{
    Book* book = new Book;
    cin >> *book;
    books.push_back(book);
}

void Library::Output_books(const vector<Book*>& books)
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

void Library::Save_books(const vector<Book*>& books)
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
        cin >> filename;

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

void Library::Download_books(vector<Book*>& books)
{
    ifstream fin;
    string filename;
    cout << "������� ��� �����: ";
    cin >> filename;
    fin.open((filename + ".txt"));
    if (fin.is_open())
    {
        string line;
        bool p = false;
        while (getline(fin, line))
        {
            if (line == "�����")
            {
                Book* book = new Book;
                fin >> *book;
                books.push_back(book);
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

void Library::Clear(vector<Book*>& books)
{
    for (auto& book : books)
    {
        delete book;
    }
    books.clear();
    cout << "������ � ������ �������." << endl;
}
