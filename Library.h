#pragma once
#include "Book.h"
#include "Utils.h"

class Library
{
public:

	void Menu();
	void Add_book(vector<Book>& books);
	void Output_books(vector<Book>& books);
	void Save_books(vector<Book>& books);
	void Download_books(vector<Book>& books);
	void Clear(vector<Book>& books);

};