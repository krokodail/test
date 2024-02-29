#pragma once
#include <vector>
#include <string>

using namespace std;

class CardModel;

class DeckModel
{
	vector<CardModel*> _deck;
public:
	DeckModel();
	~DeckModel();
	CardModel* PopRandomCard();
};

