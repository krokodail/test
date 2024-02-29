#include "DealerModel.h"
#include "DeckModel.h"

DealerModel::DealerModel()
{
	_deck = new DeckModel();
}

DeckModel* DealerModel::GetDeck() const
{
	return _deck;
}

DealerModel::~DealerModel()
{
	delete _deck;
}
