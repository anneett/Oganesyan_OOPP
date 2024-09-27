#pragma once
#include "Boost.h"

class Book
{
	friend class boost::serialization::access;

protected:

	string title = "";
	string author = "";
	int release_year = 0;
	string publishing_house = "";
	bool in_stock = 0;
	double rating = 0;

public:

	virtual void Input(istream& in);
	virtual void Output(ostream& out) const;

	//friend istream& operator >> (istream& in, Book& book);
	//friend ostream& operator << (ostream& out, const Book& book);
	friend ofstream& operator << (ofstream& fout, const Book& book);
	friend ifstream& operator >> (ifstream& fin, Book& book);
};