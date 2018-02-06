#ifndef SET_H
#define SET_H

#include <set>

using namespace std;

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

#include "setImpl.h"
#endif
