#include "TableModel.h"
#include "DealerModel.h"
#include "PlayerModel.h"

TableModel::TableModel()
{
	dealer = new DealerModel();
	players.push_back(new PlayerModel());
}

TableModel::~TableModel()
{
	delete dealer;
	for (int i{ 0 }; i < players.size(); i++) {
		delete players[i];
	}
}

const std::vector<PlayerModel*> TableModel::GetPlayers() const
{
	return players;
}

const DealerModel* TableModel::GetDealer() const
{
	return dealer;
}
