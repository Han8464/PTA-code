#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;
	int level;
}Node;
Node* root;
vector<int> inorder;
vector<int> preorder;
map<int, Node*> data_add_map;
int k = 0;
Node* create(int a, int b, int level)
{
	if(b < a)
		return NULL;
	if(a == b)
	{
		k++;
		Node* r = new Node;
		r->data = inorder[a];
		r->level = level;
		data_add_map[r->data] = r;
		r->left = NULL;
		r->right = NULL;
		return r;
	}
	for(int i = a; i <= b; i++)
	{
		if(inorder[i] == preorder[k])
		{
			k++;
			Node* r = new Node;
			r->data = inorder[i];
			r->level = level;
			data_add_map[r->data] = r;
			r->left = create(a, i - 1, level + 1);
			if(r->left != NULL)
				r->left->parent = r;
			r->right = create(i + 1, b, level + 1);
			if(r->right != NULL)
				r->right->parent = r;
			return r;
		}
	}
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		inorder.push_back(tmp);
	}
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		preorder.push_back(tmp);
	}
	Node* root = create(0, n - 1, 1);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(data_add_map.find(a) == data_add_map.end() && data_add_map.find(b) == data_add_map.end())
		{
			printf("ERROR: %d and %d are not found.\n", a, b);
			continue;
		}
		if(data_add_map.find(a) == data_add_map.end())
		{
			printf("ERROR: %d is not found.\n", a);
			continue;
		}
		if(data_add_map.find(b) == data_add_map.end())
		{
			printf("ERROR: %d is not found.\n", b);
			continue;
		}
			Node* n1 = data_add_map[a];
			Node* n2 = data_add_map[b];
			if(n2->left == n1 || n2->right == n1)
			{
				printf("%d is an ancestor of %d.\n", b, a);
			}else if(n1->left == n2 || n1->right == n2)
			{
				printf("%d is an ancestor of %d.\n", a, b);
			}else
			{
				Node* x1;
				Node* x2;
				if(n1->level > n2->level)
				{
					x1 = n1;
					x2 = n2;
				}else
				{
					x1 = n2;
					x2 = n1;
				}
				while(x1->level != x2->level)
					x1 = x1->parent;
				while(x1->data != x2->data)
				{
					x1 = x1->parent;
					x2 = x2->parent;
				}
				if(x1->data == a)
				{
					printf("%d is an ancestor of %d.\n", a, b);
				}else if(x1->data == b)
				{
					printf("%d is an ancestor of %d.\n", b, a);
				}else
				{
					printf("LCA of %d and %d is %d.\n", a, b, x1->data);
				}
			}

	}
	system("pause");
	return 0;

}