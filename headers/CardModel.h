#pragma once
#include <string>

using namespace std;

class CardModel
{
	const string _suit;
	const string _name;
	const int _value;
public:
	string getFullName()const;
	int getValue()const;
	CardModel() = delete;
	CardModel(const string& suit, const string& name, const int& value);
};