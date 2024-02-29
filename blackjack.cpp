// blackjack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "DeckModel.h"
#include "CardModel.h"
#include "TableModel.h"
#include "TableView.h"
#include "DealerModel.h"
#include "TableController.h"

using namespace std;

int main()
{
    TableModel* table = new TableModel();
    TableView* tableView = new TableView();
    TableController* tableController = new TableController(table, tableView);
    tableController->StartGame();
}