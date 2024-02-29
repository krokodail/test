#include "TableController.h"
#include "TableModel.h"
#include "TableView.h"
#include "DealerModel.h"
#include "PlayerModel.h"
#include "DeckModel.h"

TableController::TableController(TableModel* InTableModel, TableView* InTableView)
{
	tableModel = InTableModel;
	tableView = InTableView;
	gameState = GameState::PreMatch;
}

TableController::~TableController()
{
	delete tableModel;
	delete tableView;
}

void TableController::DrawTable() const
{
	auto dealer_hand = tableModel->GetDealer()->GetHand();
	std::string table = "Dealer: ";
	for (const auto card_in_hand : dealer_hand) {
		table += card_in_hand->getFullName() + " ";
	}

	table += "\tValue: " + std::to_string(tableModel->GetDealer()->GetHandValue());

	auto player_hand = tableModel->GetPlayers()[0]->GetHand();
	table += "\nPlayer: ";
	for (const auto card_in_hand : player_hand) {
		table += card_in_hand->getFullName() + " ";
	}

	table += "\tValue: " + std::to_string(tableModel->GetPlayers()[0]->GetHandValue());

	tableView->DrawTable(table);
}

void TableController::GiveCardToPlayer(const PlayerModel* InPlayer,DeckModel* InDeck)
{
	CardModel* card = InDeck->PopRandomCard();
	InPlayer->PushCardToHand(card);
}

void TableController::DrawMenu()
{
	std::string menu = "\n\n1.Take card\t2.Enough";
	tableView->DrawMenu(menu);
}

void TableController::GameLoop()
{
	switch (gameState) {
	case GameState::PreMatch:
		DrawTable(); // реализовать проверку на БлекДжек
		DrawMenu();
		break;
	}
}

void TableController::StartGame()
{
	GiveCardToPlayer(tableModel->GetDealer(), tableModel->GetDealer()->GetDeck());
	GiveCardToPlayer(tableModel->GetDealer(), tableModel->GetDealer()->GetDeck());
	GiveCardToPlayer(tableModel->GetPlayers()[0], tableModel->GetDealer()->GetDeck());
	GiveCardToPlayer(tableModel->GetPlayers()[0], tableModel->GetDealer()->GetDeck());
	GameLoop();
}