#pragma once
#include "Boost.h"
#include "Book.h"

class EBook: public Book
{
	friend class boost::serialization::access;

protected:

	string link = "";

public:

	BOOST_SERIALIZATION_SPLIT_MEMBER()

	virtual ~EBook() {}

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	template<class Archive>
	void save(Archive& ar, const unsigned int version) const
	{
		ar & boost::serialization::base_object<Book>(*this);
		ar & link;
	}

	template<class Archive>
	void load(Archive& ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<Book>(*this);
		ar & link;
	}

	//friend istream& operator >> (istream& in, EBook& e_book);
	//friend ostream& operator << (ostream& out, const EBook& e_book);
	//friend ofstream& operator << (ofstream& fout, const EBook& book);
	//friend ifstream& operator >> (ifstream& fin, EBook& book);
};

BOOST_CLASS_VERSION(EBook, 1)


