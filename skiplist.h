#ifndef __SKIP_LIST
#define __SKIP_LIST

#include <iostream>
#include <cstring>
#include <queue>

/*	
	 _________________
	|��/��| ��� | a�� |
	|_____|_____|_____|
	 data   skip  next
*/

template <typename T>
struct SkipListNode
{
	T data;
	SkipListNode<T>* skip, * next;

	//SkipListNode(const T& value, SkipListNode* skipNode = nullptr, SkipListNode* nextNode = nullptr)
		//:data(value), skip(skipNode), next(nextNode) {}
};

template <typename T>
class SkipList;

template <typename T>
class SkilListIterator
{
	friend class SkipList<T>;

	SkipListNode<T>* ptr;

public:
	//SkilListIterator(SkipListNode* pos = nullptr, SkipListNode* skipPos=nullptr) : ptr(pos), skipPtr(skipPos) {}
	SkilListIterator(SkipListNode<T>* pos = nullptr) : ptr(pos) {}

	SkilListIterator<T> next() const {
		if (!valid()) {
			return *this;
		}
		return SkilListIterator(ptr->next);
	}

	SkilListIterator<T> skip() const {
		if (!valid()) {
			return *this;
		}
		return SkilListIterator(ptr->skip);
	}

	bool valid() const {
		return ptr != nullptr;
	}

	T const& getConst() const {
		return ptr->data;
	}

	T& get() const {
		return ptr->data;
	}

	operator bool() const {
		return valid();
	}

	SkilListIterator<T>& operator++() {
		return (*this = next());
	}

	SkilListIterator<T> operator++(int) {
		SkilListIterator saved = *this;
		++(*this);
		return saved;
	}

	T& operator*() {
		return get();
	}

	bool operator==(SkilListIterator<T> const& it) const {
		return ptr == it.ptr;
	}

	bool operator!=(SkilListIterator<T> const& it) const {
		return !(*this == it);
	}

	SkilListIterator<T>& operator+=(unsigned n) {
		for (int i = 0; i < n; ++i) {
			++(*this);
		}

		return *this;
	}
};

template <typename T>
class SkipList
{
private:
	SkipListNode<T>* frontL, * endL;

	void copy(SkipList<T> const& l);
	void erase();

public:
	SkipList() : frontL(nullptr), endL(nullptr) {}

	SkipList(SkipList<T> const& sl);
	SkipList<T>& operator=(SkipList<T> const& sl);

	~SkipList();	

	SkipList(SkipList<T>&& other);
	SkipList<T>& operator=(SkipList<T>&& other);

	SkilListIterator<T> begin() const;
	SkilListIterator<T> end() const;
	
	bool empty() const;
	
	T const& getAt(SkilListIterator<T> const& it) const;
	T& getAt(SkilListIterator<T> const& it);

	bool insertElem(SkilListIterator<T> const& it, T const& x);
	bool insertLast(T const& x);
	// delete in not good have probelms
	bool deleteElem();

	//take pointer from the first to the second city -> this is skip field
	void addInformafionInSkipField(const std::string arr[2], const SkipList<T> list);

	// returns the position of the city
	SkipListNode<T>* search(std::string city, const SkipList<T> list);

	void wayForAnyaAndVankata(const SkipList<T> list, const std::string importantCities);
	void printQueue(std::queue<T> q);
};

template<typename T>
inline void SkipList<T>::erase()
{
	while (!empty())
		deleteElem();
}

template <typename T>
void SkipList<T>::copy(SkipList<T> const& l) {
	for (T const& x : l)
		insertElem(x);
}

template<typename T>
inline SkipList<T>::SkipList(SkipList<T> const& sl) : frontL(nullptr),endL(nullptr)
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
inline bool SkipList<T>::insertElem(SkilListIterator<T> const& it, T const& x)
{
	if (empty()) {
		SkipListNode<T>* newElem = new SkipListNode<T>{ x, nullptr, frontL};
		frontL = newElem;
		if (endL == nullptr)
			endL = newElem;
		return true;
	}

	SkipListNode<T>* newElem = new SkipListNode<T>{ x, nullptr, nullptr };

	if (!it || it.ptr == endL) {
		endL->next = newElem;
		endL = newElem;
	}
	else {
		newElem->next = it.ptr->next;
		it.ptr->next = newElem;
	}
	return true;
}

template<typename T>
inline bool SkipList<T>::insertLast(T const& x)
{
	SkilListIterator<T> it = end();
	SkipListNode<T>* newElem = new SkipListNode<T>{ x, nullptr, nullptr };

	if (empty()) {
		endL = newElem;
	}


	if (!it || it.ptr == endL) {
		endL->next = newElem;
		endL = newElem;
	}
	else {
		// ������ �� ������� ������ �� �������
		newElem->next = it.ptr->next;
		it.ptr->next = newElem;
	}
	return true;
}


template<typename T>
inline bool SkipList<T>::deleteElem()
{
	T tmp;
	//return deleteElem(tmp);
	return true;
}

template<typename T>
inline void SkipList<T>::addInformafionInSkipField(const std::string arr[2], const SkipList<T> list)
{
	// add asset biblioteque and add assert in this void functin if have problem with 
	// serch function and invalid position to catch a bug
	SkipListNode<T>* first;
	first = search(arr[0], list);
	//assert();
	first->skip = search(arr[1], list);
}

template<typename T>
inline SkipListNode<T>* SkipList<T>::search(std::string city, const SkipList<T> list)
{
	SkipListNode<T>* elem;

	while (!list.empty())
	{
		if (city == elem->getAt())
		{
			return elem; //position
		}
		//next element in list
		elem->next;

	}
	return nullptr; //end position or another invalid position and taka in another function assert for invalid posion
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



#endif // !__SKIP_LIST
