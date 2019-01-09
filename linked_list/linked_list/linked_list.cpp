/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <assert.h>

using namespace std;

typedef struct Node
{
	int number;
	struct Node* next;
}Node;

class LinkedList
{
private:
	Node* head;
	int listsize;
public:
	LinkedList();
	
	int get(int i);

	int remove(int i);

	int insert(int i, int value);

	int size();
};

LinkedList::LinkedList()
{
	this->head = new Node;
	this->head->number = 0;
	this->head->next = NULL;
	this->listsize = 0;
}

int LinkedList::get(int i)
{
	int n = 0;
	Node* cur = head;
	while(n <= i && cur != NULL)
	{
		cur = cur->next;
		n++;
	}
	if (cur == NULL)
	{
		printf("error: index out of range\n");
		return -1;
	}
	return cur->number;
}

int LinkedList::remove(int i)
{
	int n = 0;
	Node* cur = head;
	while(n < i && cur != NULL)
	{
		cur = cur->next;
		n++;
	}
	if (cur == NULL || cur->next == NULL)
	{
		printf("error: index out of range\n");
		return -1;
	}
	Node* node = cur->next;
	cur->next = node->next;
	delete node;
	listsize--;
	return 0;
}

int LinkedList::insert(int i, int value)
{
	int n = 0;
	Node* cur = head;
	Node* node = new Node;
	while(n < i && cur != NULL)
	{
		cur = cur->next;
		n++;
	}
	if (cur == NULL)
	{
		printf("error: index out of range\n");
		return -1;
	}
	node->number = value;
	node->next = cur->next;
	cur->next = node;
	listsize++;
	return 0;
}

int LinkedList::size()
{
	return this->listsize;
}

int main()
{
	LinkedList list;
	list.insert(0, 1);
	list.insert(1, 2);
	list.insert(2, 3);
	
	assert(list.size() == 3);
	assert(list.get(0) == 1);
	assert(list.get(1) == 2);

	list.remove(0);
	assert(list.get(0) == 2);
	assert(list.size() == 2);
	list.remove(1);
	assert(list.get(0) == 2);

	system("pause");
	return 0;
	
}
*/