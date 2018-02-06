
template <class T>		//item function implementations
Item<T>::Item()
{
	next = NULL;
	prev = NULL;
}


template <class T>
T* Item<T>::get_value()
{
	return &value;
}
