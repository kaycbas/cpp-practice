#include <iostream>
#include "menu.h"
#include "wpDisplay.h"
#include "Web.h"
#include <string>


int main (int argc, char* argv[])
{
	
	Web theWeb (argv[1]);

	WebPage *temp;

	for (int i=0; i<theWeb.wPages.size(); ++i)		//prints webpage info (for demonstration purposes)
	{
		WebPage *wpPtr = theWeb.wPages[i];
		cout << "FILE NAME: " << wpPtr->_name << endl << endl;

		cout << "OUTGOING LINKS: " << endl;
		for (int k=0; k<wpPtr->outLinkPtrs.size(); ++k)
		{
			temp = wpPtr->outLinkPtrs.get(k);
			cout << temp->_name << endl;
		}

		cout << endl << endl << "INCOMING LINKS: " << endl;
		for (int j=0; j<wpPtr->inLinkPtrs.size(); ++j)
		{
			temp = wpPtr->inLinkPtrs.get(j);
			cout << temp->_name << endl;
		}

		cout << endl << "File text: " << endl;
		string* text;
		text = theWeb.retFileText(wpPtr);
		cout << *text << endl << "*******************************" << endl << endl;
	}


	QApplication app (argc, argv);

	Menu mainWindow;
	mainWindow.move (300, 300);
	mainWindow.setWindowTitle ("Main Menu");

	WebDisplay secWindow;

	mainWindow.show();
	secWindow.show();

	return app.exec();	
}
