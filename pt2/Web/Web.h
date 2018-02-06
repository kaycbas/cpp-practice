#ifndef WEB_H
#define WEB_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <map>
#include "headers.h"

class Web
{
	public:
		Web(char*);
		~Web();

		void readData (char*);
		string* retFileText(WebPage*);

		vector<WebPage*> wPages;
		map<string, WebPage*> globMap;
};

/////////////////////IMPLEMENTATION////////////////////////

Web::Web(char *filename)
{
	readData (filename);
}

Web::~Web()
{
}

void Web::readData(char* filename)
{
	ifstream ifile (filename);

	if (ifile.fail()) 						
	{
    cout << "Could not open data file.\n";
		return;
  }

	string file;
	bool done=false;
	WebPage *newPage;
	//char *fname;

	while (!done)
	{
		getline(ifile, file);
		if (!ifile)
			done=true;
		else 
		{
			newPage = new WebPage (file, &globMap);	

			globMap[file] = newPage;
			wPages.push_back(newPage);	
		}
	}

	for (int i=0; i<wPages.size(); ++i)
	{
		wPages[i]->parse();
	}
}


string* Web::retFileText (WebPage *page)
{
	Set<string> *textSet;
	textSet = page->allWords();
	string text;

	for (int i=0; i<textSet->size(); ++i)
	{
		text.append(textSet->get(i));
		text.append(" ");
	}
	string *textPtr=&text;
	return textPtr;
}

#endif
