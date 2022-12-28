#ifndef __SKIP_LIST_ITERATOR
#define __SKIP_LIST_ITERATOR

#include <iostream>
#include <cstring>
#include <queue>
#include "skip_list_node.h"

template <typename T>
class SkipList;

template <typename T>
class SkilListIterator
{
	friend class SkipList<T>;

	SkipListNode<T>* ptr;

public:
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

#endif // !__SKIP_LIST_ITERATOR
