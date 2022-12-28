#ifndef __SKIP_LIST
#define __SKIP_LIST

#include <iostream>
#include <cstring>
#include <queue>

/*	
	 _________________
	|ñò/ñò| àäð | aäð |
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


#endif // !__SKIP_LIST
