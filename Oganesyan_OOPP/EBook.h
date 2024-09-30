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
};

BOOST_CLASS_VERSION(EBook, 1)


