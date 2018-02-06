#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>
#include "headers.h"

using namespace std;

void readData (char*);
void browse (); 
void andFunc ();
void orFunc ();
void simpFunc (string input);
void printResults ();

vector<WebPage*> wPages;
vector<int> matchPage;

int main (int argc, char *argv[])
{
	if (argc!=2)
	{
		cout << "Please enter two command line arguments." << endl;
		return 0;
	}

	readData (argv[1]);

	browse();

	cout << "Program exited." << endl << endl;

	return 0;
}



void readData (char* filename)
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
	char *fname;

	while (!done)
	{
		getline(ifile, file);
		if (!ifile)
			done=true;
		else 
		{
			fname=&file[0];
			newPage = new WebPage (fname);		
			wPages.push_back(newPage);	
		}
	}
}


void browse ()
{
	bool done = false;
	string str;
	string temp;
	char ch;
	int i;
	bool good = true;
	while (!done)
	{
		cout << "Enter argument(s): " << endl;
		cin >> str;
		cout << endl;
		if (str == ".")
			done = true;
		else if (str == "AND")
			andFunc();
		else if (str == "OR")
			orFunc();
		else 
		{
			getline(cin, temp);
			if (temp.size()>1)
			{
				cout << "Invlaid input." << endl << endl;
			}
			else 
			{
				simpFunc(str);
			}
		}
		cout << "-------------------------------------------------" << endl;
		matchPage.clear();
	}
}

void andFunc()
{
	Set<string> wInputs;
	Set<string> *setPtr;
	string wrdStr;
	int i, s;
	char ch;

	while (ch!=')')
	{
		ch = cin.get();
		if (valid(ch))
		{
			wrdStr.push_back(ch);
		}
		else if (wrdStr.size()!=0)
		{
			wInputs.add(wrdStr);
			wrdStr.erase();
		}
	}

	s = wPages.size();
	for (i=0; i<s; i++)
	{
		setPtr = wPages[i]->words.setIntersection(wInputs);
		if (setPtr->size() == wInputs.size())
		{
			matchPage.push_back(i);
		}
	}
	printResults ();
}

	
void orFunc()
{
	Set<string> wInputs;
	Set<string> *setPtr;
	string wrdStr;
	int i, s;
	char ch;

	while (ch!=')')
	{
		ch = cin.get();
		if (valid(ch))
		{
			wrdStr.push_back(ch);
		}
		else if (wrdStr.size()!=0)
		{
			wInputs.add(wrdStr);
			wrdStr.erase();
		}
	}

	s = wPages.size();
	for (i=0; i<s; i++)
	{
		setPtr = wPages[i]->words.setIntersection(wInputs);
		if (setPtr->size() > 0)
		{
			matchPage.push_back(i);
		}
	}
	printResults ();
}

void simpFunc(string input)
{
	int i;
	int s = wPages.size();
	for (i=0; i<s; i++)
	{
		if (wPages[i]->words.contains(input))
		{
			matchPage.push_back(i);
		}
	}
	printResults();
}


void printResults ()
{
	string input;
	int i;
	int s;
	s = matchPage.size();
	cout << s << " page(s) matched your search." << endl;

	if (s>0)
	{
		for (i=0; i<s; i++)
		{
			cout << "Page: " << endl << endl;
			wPages[matchPage[i]]->print();
			cout << "Input 'next' to go to the next page." << endl;
			cin >> input;
			while (input!="next")
			{
				cin >> input;
			}
		}
		cout << "That was the last page." << endl << endl;
	}
}









