
template <class T>
Set<T>::Set()
{
	_size = 0;
}

template <class T>
Set<T>::Set (const Set<T> & other)
{
}

template <class T>
Set<T>::~Set()
{
}

template <class T>
void Set<T>::add (const T & item)
{
	int s = internalStorage.size();
	internalStorage.insert(s, item);
	_size = internalStorage.size();
}

template <class T>
void Set<T>::remove (const T & item)
{
	internalStorage.valRemove(item);
	_size=internalStorage.size();
}

template <class T>
bool Set<T>::contains (const T & item) const
{
	Item<T> *tempItem;
	int i;
	bool found = false;

	for (i=0; i<size() && found==false; i++)
	{
		tempItem=internalStorage.get(i);
		if (tempItem->value == item)
		{
			found = true;
			i--;
		}
	}

	if (found)
		return found;
	else
		return false;
}

template <class T>
int Set<T>::size () const
{
	return _size;
}

template <class T>
bool Set<T>::isEmpty () const
{
	if (_size==0)
		return true;
	else
		return false;
}

template <class T>
Item<T>* Set<T>::get(int pos) const
{
	return internalStorage.get(pos);
}

template <class T>
Set<T>* Set<T>::setIntersection (const Set<T> & other) const
{
	Set<T>* newSet = new Set<string>;
	Item<T> *tempItem;
	int i, j, k;

	for (i=0; i<size(); i++)
	{
		tempItem = internalStorage.get(i);
		if (other.contains(tempItem->value))
		{
			if (!newSet->contains(tempItem->value))
			{
					newSet->add(tempItem->value);
			}
		}
	}				
	return newSet;			
}

template <class T>
Set<T>* Set<T>::setUnion (const Set<T> & other) const
{
	Set<T>* newSet = new Set<string>;
	Item<T> *tempItem;
	int i;

	for (i=0; i<size(); i++)
	{
		tempItem = internalStorage.get(i);
		newSet->add(tempItem->value);		
	}

	for (i=0; i<other.size(); i++)
	{
		tempItem = other.get(i);		
		if (!newSet->contains(tempItem->value))
		{
			newSet->add(tempItem->value);
		}
	}
	return &newSet;
}

template <class T>
T* Set<T>::first()
{
	if (size()!=0)	//size=0, called by print(), causing seg fault
	{
		itr = internalStorage.get(0);
		return &itr->value;
	}		
}

template <class T>
T* Set<T>::next()
{
	if(itr->next!=NULL)
		itr=itr->next;
	else
		return first();
	return &itr->value;
}












