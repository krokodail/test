#include "CardModel.h"

using namespace std;

string CardModel::getFullName() const {
	return string(_suit + " " + _name);
}

int CardModel::getValue() const{
	return _value;
}

CardModel::CardModel(const string& suit, const string& name, const int& value):
	_suit(suit), _name(name), _value(value) {}