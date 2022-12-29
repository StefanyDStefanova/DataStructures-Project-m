#ifndef __SKIP_LIST
#define __SKIP_LIST

#include <iostream>
#include <cstring>
#include <queue>
#include "skip_list_node.h"
#include "skip_list_iterator.h"

template <typename T>
class SkipList
{
private:
	SkipListNode<T>* frontL, * endL;

	void copy(SkipList<T> const& l);
	void erase();

	SkipListNode<T>* getNodeAt(int index);
	//print final queue of cities 
	void printQueue(std::queue<T> q);


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

	bool insertElem(T const& x);
	//bool deleteElem(T& x);
	bool deleteQueue();

	//take pointer from the first to the second city -> this is skip field
	bool connect(T& first, T& second);

	// helper fuction for give index of city from list
	int indexOf(T& city);	

	//creates a path from the available cities taking the shortest path with the most important ones 
	void wayForAnyaAndVankata(std::queue<T> importantCities);

};



#endif // !__SKIP_LIST
