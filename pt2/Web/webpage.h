#ifndef SET_H
#define SET_H

#include <string>
#include <set>

using namespace std;

class WebPage {			
  public:
    WebPage ();    
    WebPage (string filename, map<string, WebPage*> *globMap);		
    ~WebPage ();   

    Set<string>* allWords ();
		void parse();
		void addIncomingLink (string otherFileName);

  //data members//
		string _name;
		map<string, WebPage*> *GMPtr;
		Set<string> words;
		Set<WebPage*> outLinkPtrs;
		Set<WebPage*> inLinkPtrs;
};

////////////////////////

template <class T>
class Set : public std::set<T>
{
  public: 
    Set ();                    
    ~Set ();

		T get (int pos) const;

		bool contains (const T & item) const;                   

    Set<T>* setIntersection (const Set<T> & other) const;

    Set<T>* setUnion (const Set<T> & other) const;
};



////////////////General Functions///////////////////////////////

bool valid (char ch);

#include "setImpl.h"
#include "wpImpl.h"
#endif
