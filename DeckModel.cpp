#include "DeckModel.h"
#include "CardModel.h"
#include <cstdlib>
#include <ctime>

using namespace std;

DeckModel::DeckModel() {
	vector<string> suits{ "♠","♣","♥","♦" };
	vector<string> names{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

	int value{0};

	for (int i(0); i < suits.size();i++) {
		for (int j(0); j < names.size();j++) {
			if (names[j] == "J" || names[j] == "Q" || names[j] == "K") {
				value = 10;
			}
			else if (names[j] == "A") {
				value = 11;
			}
			else {
				value = j + 2;
			}
			_deck.push_back(new CardModel(suits[i], names[j], value));
		}
	}
}

DeckModel::~DeckModel() {
	for (int i{ 0 }; i < _deck.size(); i++) {
		delete _deck[i];
	}
}

CardModel* DeckModel::PopRandomCard() {
	if (_deck.empty()) {
		return nullptr;
	}
	srand(time(nullptr));
	int i{ static_cast <int>( rand() % _deck.size() )};
	CardModel* card{ _deck[i] };

	_deck.erase(_deck.begin() + i);

	return card;
}