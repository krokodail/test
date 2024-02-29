#pragma once
#include "PlayerModel.h"

class DeckModel;
class DealerModel:public PlayerModel
{
	DeckModel* _deck = nullptr;
public:
	DealerModel();
	DeckModel* GetDeck() const;
	virtual ~DealerModel();
};