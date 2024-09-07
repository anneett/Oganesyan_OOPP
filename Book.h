#pragma once

#include <string>

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

};