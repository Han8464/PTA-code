#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node
{
	int number;
	struct Node* next;
}Node;

class Stack
{
	Node* head;
	int stack_size;
public:
	Stack()
	{
		head = new Node;
		head->number = 0;
		head->next = NULL;
		stack_size = 0;
	}
	void push(int value);
	int pop();
	int top(int* value);
	int size();
};

void Stack::push(int value)
{
	Node* tmp = new Node;
	tmp->number = value;
	tmp->next = head->next;
	head->next = tmp;
	stack_size++;
}

int Stack::pop()
{
	if(stack_size == 0)
	{
		printf("error\n");
		return 0;
	}
	int tmp = head->next->number;
	Node* cur = head->next;
	head->next = cur->next;
	delete cur;
	stack_size--;
	return tmp;
}

int Stack::top(int* value)
{
	if(stack_size == 0)
	{
		printf("NULL\n");
		return -1;
	}
	*value = head->next->number;
	return 0;
}

int Stack::size()
{
	return stack_size;
}

int main()
{
	Stack* stack = new Stack();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	cout<<stack->size()<<endl;
	cout<<stack->top()<<endl;
	cout<<stack->pop()<<endl;
	cout<<stack->top()<<endl;
	cout<<stack->pop()<<endl;
	cout<<stack->top()<<endl;
	cout<<stack->pop()<<endl;
	system("pause");
	return 0;
}