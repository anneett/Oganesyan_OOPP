#pragma once
#include "Boost.h"
#include "Book.h"

class Ebook : public Book
{
	//friend class boost::serialization::access;

	string link = "";
};
