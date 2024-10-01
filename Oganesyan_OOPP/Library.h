#pragma once
#include "Boost.h"
#include "Utils.h"
#include "Book.h"
#include "EBook.h"

class Library
{
	vector<shared_ptr<Book>> books;

public:

	void Add_book();
	void Add_EBook();
	void Output_books();

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& books;
	}

	void Save_books();
	void Load_books();

	void Clear();
};