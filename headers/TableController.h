#pragma once
#include <string>

class TableModel;
class TableView;
class PlayerModel;
class DeckModel;

enum class GameState {
	PreMatch,
	PlayerWins,
	DealerWins,
	Draw,
	PlayerChoice,
	DealerChoice
};

class TableController
{
private:
	GameState gameState;
	TableModel* tableModel = nullptr;
	TableView* tableView = nullptr;
	void DrawTable() const;
	void GiveCardToPlayer(const PlayerModel* InPlayer, DeckModel* InDeck);
	void DrawMenu();
	void GameLoop();
	bool IsGameFinished();
public:
	TableController(TableModel* InTableModel, TableView* InTableView);
	~TableController();
	void StartGame();
};

