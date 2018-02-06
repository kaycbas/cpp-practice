#include <string>

using namespace std;

template <class T>
class Item
{
	public:
		Item();	
	
		T* get_value();		


		T value;

		Item<T> *prev, *next;	
};


/////////////////////////////////////////////////////////////////////////

template <class T>
class List
{
  public:
    List ();   

		List (const List<T> & other);

    ~List ();  

		List<T> & operator= (const List<T> & other);

    int size () const;  

    void insert (int position, const T & value);

    void posRemove (int position);

		void valRemove (const T &value);

    void set (int position, const T & value);

    Item<T>* get (int position) const;


  private:
		Item<T> *head;
		int _size;
};


/////////////////////////////////////////////////////////////////////////


template <class T>
class Set {
  public: 
    Set ();                    
    Set (const Set<T> & other); 
    ~Set ();                    

    void add (const T & item); 

    void remove (const T & item);

    bool contains (const T & item) const;

    int size () const;

    bool isEmpty () const;

		Item<T> * get (int pos) const;

    Set<T>* setIntersection (const Set<T> & other) const;

    Set<T>* setUnion (const Set<T> & other) const;

    T* first ();

    T* next ();

  private:
    List <T> internalStorage;
		int _size;
		Item<T>* itr;
};


/////////////////////////////////////////////////////////////////////


class WebPage {
  public:
    WebPage ();    
    WebPage (char* filename);
    ~WebPage ();   

		void print();

    Set<string> allWords () const;  

    //friend ostream & operator<< (ostream & os, const WebPage & page);

  //private:
		Set<string> words;
};


////////////////General Functions///////////////////////////////

bool valid (char ch);

#include "itemImpl.h"
#include "listImpl.h"
#include "setImpl.h"
#include "wpImpl.h"
