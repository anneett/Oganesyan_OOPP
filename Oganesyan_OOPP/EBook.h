#pragma once
#include "Boost.h"
#include "Book.h"

class EBook: public Book
{
	friend class boost::serialization::access;

protected:

	string link = "";

public:

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	//friend istream& operator >> (istream& in, EBook& e_book);
	//friend ostream& operator << (ostream& out, const EBook& e_book);
	//friend ofstream& operator << (ofstream& fout, const EBook& book);
	//friend ifstream& operator >> (ifstream& fin, EBook& book);
};
