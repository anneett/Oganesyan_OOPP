#pragma once
#include <string>
#include <vector>

using namespace std;

class Book
{
public:

	string author = "";
	string title = "";
	int release_year = 0;
	string publishing_house = "";
	bool in_stock = 0;
	double rating = 0;

	friend istream& operator >> (istream& in, Book& book);
	friend ostream& operator << (ostream& out, const Book& book);
};