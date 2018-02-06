#include "menu.h"
#include <string>

Menu::Menu (QWidget *parent) : QWidget (parent)
{

	grid = new QGridLayout (this);
	grid->setSpacing (15);

	searchLine = new QLineEdit (this);
	grid->addWidget (searchLine, 0, 0, 1, 4);

	searchButton = new QPushButton ("Search", this);
	grid->addWidget (searchButton, 0, 4, 1, 1);

	results = new QListWidget (this);
	results->addItem ("Result 1");
	results->addItem ("Result 2");
	results->addItem ("Result 3");
	results->addItem ("Result 4");
	results->addItem ("Result 5");
	grid->addWidget (results, 1, 0, 6, 5);

	setLayout (grid);

	connect (searchButton, SIGNAL(clicked()), this, SLOT (readInput()));
}
	
	
void Menu::readInput()
{
	std::string input = searchLine->text().toStdString();
	
}








