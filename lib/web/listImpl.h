
template <class T>		//list function implementations
List<T>::List()
{
	head=NULL;
	_size=0;
}

template <class T>
List<T>::List(const List<T> & other) //new
{
	head=NULL;
	_size=0;
	int s = other.size();
	Item<T>* tempItem;
	for (int i=0; i<s; i++)
	{
		tempItem=other.get(i);
		insert (i, tempItem->value);
	}
}

template <class T>
List<T>& List<T>::operator= (const List<T> & other) //new
{
	int s = other.size();
	Item<T>* tempItem;
	for (int i=0; i<s; i++)
	{
		tempItem=other.get(i);
		set (i, tempItem->value);
	}
}

template <class T>
List<T>::~List()
{
}

template <class T>
int List<T>::size() const
{
	return _size;
}

template <class T>
void List<T>::insert(int position, const T & value)
{
	if (position<0 || position>size())
	{
		cout << "Out of bounds\n";
		return;
	}

	Item<T> *newItem = new Item<T>;
	newItem->value=value;

	if (head==NULL) 
	{
		head=newItem;
		newItem->prev=NULL;
		newItem->next=NULL;
	}

	else if (position==0)
	{
		newItem->prev=NULL;
		newItem->next=head;
		head->prev=newItem;
		head=newItem;
	}

	else
	{
		int i;
		Item<T> *temp;
		temp=head;

		for (i=1; i<position; i++)
		{
			temp=temp->next;
		}
		
		if (position==size())
		{
			newItem->prev=temp;
			newItem->next=NULL;
			temp->next=newItem;
		}

		else
		{
			newItem->prev=temp;
			newItem->next=temp->next;
			temp->next=newItem;
			temp=newItem->next;
			temp->prev=newItem;
		}
	}
	_size++;
}

template <class T>
void List<T>::posRemove(int position)
{
	int s=size();
	if (position<0 || position>s)
	{
		cout << "Out of bounds\n";
		return;
	}

	if (head->next==NULL)
	{
		head=NULL;
	}

	else if (position==0)
	{
		head=head->next;
		head->prev=NULL;
	}

	else 
	{
		Item<T> *temp;
		int i;
		temp=head;
		for (i=1; i<position; i++)
		{
			temp=temp->next;
		}

		if (position==(s-1))
		{
			temp->next=NULL;
		}
		else
		{
			temp->next=temp->next->next;
			temp=temp->next->next;
			temp->prev=temp->prev->prev;
		}
	}
	_size--;
}

template <class T>
void List<T>::valRemove(const T & value)
{
	Item<T> *tempItem;
	int i;
	bool found = false;

	for (i=0; i<size() && found==false; i++)
	{
		tempItem=get(i);
		if (tempItem->value == value)
		{
			found = true;
			i--;
		}
	}

	if (found==true)
	{
		posRemove (i);
	}
	else 
	{
		cout << "No such item." << endl;
	}
}

template <class T>
void List<T>::set(int position, const T & value)
{
	if (position<0 || position>size())
	{
		cout << "Out of bounds\n";
		return;
	}

	if (position==size())
		insert (_size, value);

	else
	{
		Item<T> *temp;
		int i;
		temp=head;
		for (i=0; i<position; i++)
		{
			temp=temp->next;
		}
		temp->value=value;
	}
}

template <class T>
Item<T>* List<T>::get(int position) const
{
	if (position<0 || position>=size())
	{
		cout << "Out of bounds\n";
		return NULL;
	}

	Item<T> *temp;
	int i;
	temp=head;
	for (i=0; i<position; i++)
	{
		temp=temp->next;
	}
	return temp;	
}









