#pragma once
#include <vector>

class PlayerModel;
class DealerModel;

class TableModel
{
	std::vector<PlayerModel*> players;
	DealerModel* dealer = nullptr;
public:
	TableModel();
	~TableModel();
	const std::vector<PlayerModel*> GetPlayers() const;
	const DealerModel* GetDealer() const;
};