#ifndef __SKIP_LIST_NODE
#define __SKIP_LIST_NODE

/*
	 _________________
	|ст/ст| адр | aдр |
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


#endif // !__SKIP_LIST_NODE
