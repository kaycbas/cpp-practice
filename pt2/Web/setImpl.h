template <class T>
Set<T>::Set()
{
}

template <class T>
Set<T>::~Set()
{
}

template <class T>
T Set<T>::get (int pos) const
{
	typename Set<T>::iterator it;
	it = this->begin();
	for (int i=0; i<pos; ++i)
		++it;
	return *it;
}

template <class T>
bool Set<T>::contains (const T & item) const
{
	typename Set<T>::iterator it;
	it=this->find(item);
	if (it!=this->end()){
		return true;
	}
	else 
	{
		return false;
	}
}


template <class T>
Set<T>* Set<T>::setIntersection (const Set<T> & other) const
{
	Set<T>* newSet = new Set<T>;
	T* tempT;
	typename Set<T>::iterator it;

	for (it=this->begin(); it!=this->end(); ++it)
	{
		if (other.contains(*it))
		{
			if (!newSet->contains(*it))
			{
					newSet->insert(*it);
			}
		}
	}				
	return newSet;			
}



template <class T>
Set<T>* Set<T>::setUnion (const Set<T> & other) const
{
	Set<T>* newSet = new Set<T>;
	T* tempT;
	typename Set<T>::iterator it;

	for (it=this->begin(); it!=this->end(); ++it)
	{
		newSet->insert(*it);
	}

	for (it=other.begin(); it!=other.end(); ++it)
	{
		if (!newSet->contains(*it))
		{
			newSet->insert(*it);
		}
	}				
	return newSet;	
}









