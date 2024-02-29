#include "PlayerModel.h"
#include "vector"
#include "CardModel.h"

using namespace std;

int PlayerModel::GetHandValue() const {
	int sum = 0;
	
	for (auto card_in_hand : _hand) {
		sum += card_in_hand->getValue();
	}
	for (auto ace_in_hand : _aces) {
		if (sum <= 21) {
			break;
		}
		sum -= 10;
	}
	return sum;
}

bool PlayerModel::PushCardToHand(CardModel* card) const
{
	if (card == nullptr) {
		return false;
	}

	for (auto card_in_hand : _hand) {
		if (card_in_hand->getFullName() == card->getFullName()) {
			return false;
		}
	}

	if (card->getValue() == 11) {
		_aces.push_back(card);
	}

	_hand.push_back(card);
	return true;
}

const std::vector<CardModel*>& PlayerModel::GetHand() const
{
	return _hand;
}

PlayerModel::~PlayerModel()
{

}
