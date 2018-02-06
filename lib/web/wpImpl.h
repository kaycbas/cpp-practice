
WebPage::WebPage()
{
}

WebPage::WebPage(char* filename)
{
	ifstream ifile (filename);

	if (ifile.fail()) 						
	{
    cout << "Could not open file.\n";
  }

	string wrdStr;
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
			words.add(wrdStr);
			wrdStr.erase();
		}
	}
}

WebPage::~WebPage()
{
}

//void WebPage::print()







void WebPage::print()
{
	int i;
	int s = words.size();
	cout << *words.first() << endl;

	for (i=0; i<s-1; i++)
	{
	cout << *words.next() << endl;
	}
	cout << "_____________________________" << endl;
}


Set<string> WebPage::allWords() const
{
	return words;
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







