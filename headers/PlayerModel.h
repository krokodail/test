#pragma once
#include <vector>
#include "CardModel.h"

using namespace std;

class PlayerModel
{
	mutable vector <CardModel*> _hand;
	mutable vector <CardModel*> _aces;
public:
	int GetHandValue()const;

	bool PushCardToHand(CardModel* card) const;
	
	virtual ~PlayerModel();

	const std::vector<CardModel*>& GetHand() const;
};

