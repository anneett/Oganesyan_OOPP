#pragma once
#include "Boost.h"
#include "Utils.h"
#include "Book.h"
#include "EBook.h"

class Library
{
	vector<shared_ptr<Book>> books;

public:

	virtual ~Library() {
		Clear();
	}
	virtual void Add_book();
	virtual void Add_EBook();
	virtual void Output_books();
	void Save_books();
	void Download_books();
	void Clear();
};