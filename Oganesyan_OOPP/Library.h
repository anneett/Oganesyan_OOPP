#pragma once
#include "Boost.h"
#include "Utils.h"
#include "Book.h"
#include "EBook.h"

class Library
{
	vector<shared_ptr<Book>> books;

public:

	virtual void Add_book();
	virtual void Add_EBook();
	virtual void Output_books();

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& books;
	}

	virtual void Save_books();
	virtual void Load_books();

	void Clear();
};