#include "skip_list.h"
#include "skip_list_iterator.h"
#include <assert.h>

template<typename T>
inline void SkipList<T>::erase()
{
	while (!empty())
	{
		SkipListNode<T>* deletedElem = frontL;
		frontL = frontL->next;

		if (endL == frontL)
		{
			// The last item in the list is deleted
			frontL = endL = nullptr;
		}

		delete deletedElem;
	}
}

template <typename T>
void SkipList<T>::copy(SkipList<T> const& l) {
	for (T const& x : l)
		insertElem(x);
}

template<typename T>
inline SkipList<T>::SkipList(SkipList<T> const& sl) : frontL(nullptr), endL(nullptr)
{
	copy(sl);
}

template<typename T>
inline SkipList<T>& SkipList<T>::operator=(SkipList<T> const& sl)
{
	if (this != &sl)
	{
		erase();
		copy(sl);
	}
	return *this;
}

template<typename T>
inline SkipList<T>::~SkipList()
{
	erase();
}

template<typename T>
inline SkipList<T>::SkipList(SkipList<T>&& other)
{
	frontL = other.frontL;
	other.endL = other.frontL = nullptr;
}

template<typename T>
inline SkipList<T>& SkipList<T>::operator=(SkipList<T>&& other)
{
	if (this != &other)
	{
		erase();
		frontL = other.frontL;
		endL = other.endL;

		other.endL = other.frontL = nullptr;
	}
	return *this;
}

template<typename T>
inline SkilListIterator<T> SkipList<T>::begin() const
{
	return SkilListIterator<T>(frontL);
}

template<typename T>
inline SkilListIterator<T> SkipList<T>::end() const
{
	return SkilListIterator<T>();
}

template<typename T>
inline bool SkipList<T>::empty() const
{
	return frontL == nullptr && endL==nullptr;
}

template<typename T>
inline bool SkipList<T>::insertElem(T const& x)
{
	if (empty())
	{
		//insert at the beginning
		SkipListNode<T>* newElem = new SkipListNode<T>{ x,nullptr,frontL };

		frontL = newElem;
		endL = newElem;

		return true;
	}
	
		//otherwise insert at the end
		SkipListNode<T>* newElem = new SkipListNode<T>{ x,nullptr,nullptr };

		endL->next = newElem;
		endL = newElem;

		return true;
	
}


template<typename T>
inline bool SkipList<T>::deleteQueue()
{
	if (empty())
	{
		return false;
	}

	erase();
	return true;
}

template <typename T>
int SkipList<T>::indexOf(T& city)
{
	SkipListNode<T>* current = frontL;

	for (int i = 0; current != NULL; i++)
	{
		if (city == current->data)
		{
			return i;
		}
		current = current->next;
	}
	return -1;
}

template <typename T>
SkipListNode<T>* SkipList<T>::getNodeAt(int index) 
{
	SkipListNode<T>* current = frontL;

	while (current != NULL && index > 0) {
		index = index - 1;
		current = current->next;
	}

	return current;
}

template <typename T>
bool SkipList<T>::connect(T& first, T& second)
{
	int positionFirst = indexOf(first);
	int positionSecond = indexOf(second);

	if (positionFirst < 0 || positionSecond < 0) {
		return false;
	}

	getNodeAt(positionFirst)->skip = getNodeAt(positionSecond);

	return true;
}

template <typename T>
inline void SkipList<T>::wayForAnyaAndVankata(std::queue<T> importantCities)
{
	SkipListNode<T>* elemList = frontL;
	std::queue<T> result;

	result.push(elemList->data);
	if (elemList->data == importantCities.front())
	{
		importantCities.pop();
	}
	
	//while (elemList!=NULL)
	for (int i = 0; elemList != NULL; i++)
	{
		if (!importantCities.empty())
		{
			if (elemList->data == importantCities.front())
			{
				result.push(elemList->data);
				elemList=elemList->next;
				importantCities.pop();
			}
			else if (elemList->skip!=NULL && elemList->skip->data == importantCities.front())
			{
				result.push(elemList->skip->data);
				elemList = elemList->skip;
				importantCities.pop();				
			}
			else if (elemList->next->data == importantCities.front())
			{
				result.push(elemList->next->data);
				elemList = elemList->next;
				importantCities.pop();
			}
			else
			{
				result.push(elemList->next->data);
				elemList = elemList->next;
			}
		}
		else if(result.front() != elemList->data )
		{
			result.push(elemList->data);
			elemList = elemList->next;
		}

	}
	
	printQueue(result);
}


template<typename T>
inline void SkipList<T>::printQueue(std::queue<T> q)
{
	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}
