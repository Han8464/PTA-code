#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef struct Node
{
	int address;
	int data;
	int next;
}Node;
vector<Node*> bigger;
vector<Node*> negtive;
vector<Node*> normal;
vector<Node*> allnodes;
int main()
{
	int start, n, k;
	scanf("%d%d%d", &start, &n, &k);
	int start_index;
	for(int i = 0; i < n; i++)
	{
		int add, data, next;
		scanf("%d%d%d", &add, &data, &next);
		Node* node = (Node*) malloc(sizeof(Node));
		node->address = add;
		node->data = data;
		node->next = next;
		allnodes.push_back(node);
		if(node->address == start)
			start_index = i;
	}
	Node* snode = allnodes[start_index];
	while(snode->next != -1)
	{
		if(snode->data < 0)
		{
			negtive.push_back(snode);
			if(negtive.size() > 1)
			{
				negtive[negtive.size() - 2]->next = snode->address;
			}
		}else if(snode->data <= k)
		{
			normal.push_back(snode);
			if(normal.size() > 1)
			{
				normal[normal.size() - 2]->next = snode->address;
			}
		}else
		{
			bigger.push_back(snode);
			if(bigger.size() > 1)
			{
				bigger[bigger.size() - 2]->next = snode->address;
			}
		}
		vector<Node*>::iterator it = allnodes.begin();
		for(;it != allnodes.end(); it++)
		{
			if((*it)->address == snode->next)
			{
				snode = *it;
				allnodes.erase(it);
				break;
			}
		}
		/*
		for(int i = 0; i < n; i++)
		{
			if(allnodes[i]->address == snode->next)
			{
				snode = allnodes[i];
				break;
			}
	
		}
		*/
	}

	if(snode->data < 0)
	{
		negtive.push_back(snode);
		if(negtive.size() > 1)
		{
			negtive[negtive.size() - 2]->next = snode->address;
		}
	}else if(snode->data <= k)
	{
		normal.push_back(snode);
		if(normal.size() > 1)
		{
			normal[normal.size() - 2]->next = snode->address;
		}
	}else
	{
		bigger.push_back(snode);
		if(bigger.size() > 1)
		{
			bigger[bigger.size() - 2]->next = snode->address;
		}
	}
	int c = negtive.size() - 1;
	for(int i = 0; i < c; i++)
	{
		printf("%05d %d %05d\n", negtive[i]->address, negtive[i]->data, negtive[i]->next);
	}
	if(negtive.size() > 0)
	{
		if(normal.size() > 0)
		{
			printf("%05d %d %05d\n", negtive[c]->address, negtive[c]->data, normal[0]->address);
		}else if(bigger.size() > 0)
		{
			printf("%05d %d %05d\n", negtive[c]->address, negtive[c]->data, bigger[0]->address);
		}else
		{
			printf("%05d %d -1\n", negtive[c]->address, negtive[c]->data);
		}
	}

	int a = normal.size() - 1;
	for(int i = 0; i < a; i++)
	{
		printf("%05d %d %05d\n", normal[i]->address, normal[i]->data, normal[i]->next);
	}
	if(normal.size() > 0)
	{
		if(bigger.size() > 0)
		{
			printf("%05d %d %05d\n", normal[a]->address, normal[a]->data, bigger[0]->address);
		}else
		{
			printf("%05d %d -1\n", normal[a]->address, normal[a]->data);
		}
	}
	int b = bigger.size() - 1;
	for(int i = 0; i < b; i++)
	{
		printf("%05d %d %05d\n", bigger[i]->address, bigger[i]->data, bigger[i]->next);
	}
	if(bigger.size() > 0)
		printf("%05d %d -1\n", bigger[b]->address, bigger[b]->data);
	system("pause");
	return 0;

}