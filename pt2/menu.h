#ifndef MENU_H
#define MENU_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

class Menu : public QWidget
{
	Q_OBJECT

	public:
		Menu (QWidget *parent = 0);

	private slots:
		void readInput();

	private:
		//Web *WebPtr;
		QGridLayout *grid;
		QLineEdit *searchLine;
		QPushButton *searchButton;
		QListWidget *results;
};

#endif
