#pragma once
#include "Book.h"
#include "Utils.h"

class Library
{
	vector<Book*> books;

public:
	~Library() {
		Clear();
	}
	void Add_book();
	void Output_books();
	void Save_books();
	void Download_books();
	void Clear();

};