#include "skip_list.h"
#include "skip_list_iterator.h"
#include <assert.h>

template<typename T>
inline void SkipList<T>::erase()
{
	T x;
	while (!empty())
		deleteElem(x);
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
	return frontL == nullptr;
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
inline bool SkipList<T>::deleteElem(T& x)
{
	SkilListIterator<T> it = begin();

	if (!empty()) {
		x = frontL->data;

		SkipListNode<T>* deletedElem = frontL;
		frontL = frontL->next;

		if (endL == deletedElem)
		{
			// The last item in the list is deleted
			endL = nullptr;
		}

		delete deletedElem;
		return true;
	}

	return false;
}

template<typename T>
inline void SkipList<T>::connect(const std::string arr, const SkipList<T> list)
{
	SkipListNode<T>* first;
	std::string helper = arr[0];

	// fined strat of the "edge" between cities
	first = indexOf(helper, list);
	//if search return invalid position nullptr assert catch the bug
	assert(first!=nullptr);

	// find end of the "edge" and realizes skip arrow between cities
	first->skip = indexOf(arr[1], list);
	assert(first->skip != nullptr);
}

template<typename T>
inline SkipListNode<T>* SkipList<T>::indexOf(std::string city, const SkipList<T> list)
{
	SkipListNode<T>* elem;

	while (!list.empty())
	{
		if (city == elem->getAt())
		{
			//when we find city return position
			return elem; 
		}
		//next element in list
		elem->next;

	}
	//return nullptr for an invalid position 
	return nullptr; 
}

template<typename T>
inline void SkipList<T>::wayForAnyaAndVankata(const SkipList<T> list, const std::string importantCities)
{
	SkipListNode<T>* elem;
	std::queue<T> result;
	int i = 0;

	while (!list.empty())
	{
		// ! da zapiswapyrwiq grad ot kojto trygwat nazawisimo dali e w spisyka
		// da se oprawi

		if (elem == list.frontL)
		{
			result.push(elem->data);
		}

		if (!importantCities.empty())
		{
			if (elem->data == importantCities[i])
			{
				result.push(elem->data);
				elem->next;
				i++;
			}
			else if (elem->skip == importantCities[i])
			{
				result.push(elem->skip->data);
				elem->skip;
				i++;
			}
			else if (elem->next == importantCities[i])
			{
				result.push(elem->next->data);
				elem->next;
				i++;
			}
			else
			{
				result.push(elem->next->data);
				elem->next;
			}
		}
		else
		{
			result.push(elem->data);
			elem->next;
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
