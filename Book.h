#pragma once
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
	string title = "";
	string author = "";
	int release_year = 0;
	string publishing_house = "";
	bool in_stock = 0;
	double rating = 0;

public:
	
	friend istream& operator >> (istream& in, Book& book);
	friend ostream& operator << (ostream& out, const Book& book);
	friend ofstream& operator << (ofstream& fout, const Book& book);
	friend ifstream& operator >> (ifstream& fin, Book& book);
};