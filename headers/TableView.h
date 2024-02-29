#pragma once
#include <string>

class TableView
{
public:

	void DrawTable(const std::string& table);
	void DrawMenu(const std::string& menu);
	int GetInput();
};