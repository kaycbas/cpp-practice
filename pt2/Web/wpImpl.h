
WebPage::WebPage()
{
}

WebPage::WebPage(string filename, map<string, WebPage*> *globMap)
{
	_name = filename;
	GMPtr = globMap;
}


WebPage::~WebPage()
{
}

void WebPage::parse()
{
	char *fname;

	fname = &_name[0];
	ifstream ifile (fname);

	if (ifile.fail()) 						
	{
    cout << "Could not open file.\n";
  }

	WebPage *tempWPPtr;
	std::map<string, WebPage*>::iterator it;
	string wrdStr;
	string linkStr;
	char ch;
	bool done = false;


	while (!done)
	{
		ch = ifile.get();
		if (ch == EOF)
			done=true;
		else if (valid(ch))
			wrdStr.push_back(ch);
		else if (wrdStr.size()!=0)
		{
			words.insert(wrdStr);
			wrdStr.erase();
		}

		if (ch == '[')
		{
			while (ch!='(')
			{
				ch = ifile.get();
			}
			while (ch!=')')
			{
				ch = ifile.get();
				if (ch!=')')
					linkStr.push_back(ch);
			}

			it = GMPtr->find(linkStr);
			tempWPPtr = it->second;
			outLinkPtrs.insert(tempWPPtr);
			tempWPPtr->addIncomingLink (_name);
			linkStr.erase();
		}
	}
}

void WebPage::addIncomingLink (string otherFileName)
{
	std::map<string, WebPage*>::iterator it;
	WebPage *tempWPPtr;

	it = GMPtr->find(otherFileName);
	tempWPPtr = it->second;
	inLinkPtrs.insert(tempWPPtr);
}	
	

Set<string>* WebPage::allWords()
{
	return &words;
}


bool valid (char ch)
{
	bool valid=false;
	if (isalpha(ch))
		valid=true;
	if (isdigit(ch))
		valid=true;
	return valid;
}







