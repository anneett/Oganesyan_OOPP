#pragma once
#include "Book.h"
#include "Utils.h"

class Library
{
public:

	void Add_book(vector <Book>& books);
	void Output_books(vector <Book>& books);
	void Save_books(vector <Book>& books);
};