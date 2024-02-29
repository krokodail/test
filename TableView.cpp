#include "TableView.h"
#include "TableModel.h"
#include "DealerModel.h"
#include "TableController.h"
#include <iostream>

void TableView::DrawTable(const std::string& table)
{
	cout << table;
}

void TableView::DrawMenu(const std::string& menu)
{
	cout << menu;
}

int TableView::GetInput()
{
	int input;
	cin >> input;
	return input;
}
