#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef struct Node
{
	int data;
	Node* left;
	Node* right;
	int flag;
}Node;
vector<int> allnodes;
set<bool> isheap;
Node* create(int k, int m)
{
	if(k > m)
	{
		return NULL;
	}else
	{
		Node* root = new Node;
		root->data = allnodes[k];
		root->flag = 0;
		root->left = create(k + k, m);
		root->right = create(k + k + 1, m);
		return root;
	}
}

void judgeHeap(Node* root)
{
	if(root->left != NULL)
	{
		if(root->left->data > root->data)
		{
			isheap.insert(true);
		}else if(root->left ->data < root->data)
		{
			isheap.insert(false);
		}
		judgeHeap(root->left);
	}
	if(root->right != NULL)
	{
		if(root->right->data > root->data)
		{
			isheap.insert(true);
		}else if(root->right ->data < root->data)
		{
			isheap.insert(false);
		}
		judgeHeap(root->right);
	}
}

void postorder(Node* root, int k)
{
	if(root->left != NULL)
	{
		postorder(root->left, k);
	}
	if(root->right != NULL)
	{
		postorder(root->right, k);
	}
	if(root->flag != 1)
	{
		printf("%d ", root->data);
	}else
	{
		printf("%d\n", root->data);
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		allnodes.push_back(0);

		for(int j = 0; j < m; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			allnodes.push_back(tmp);
		}
		if(m == 1)
		{
			printf("Not Heap\n%d\n", allnodes[1]);
			allnodes.clear();
			isheap.clear();
			continue;
		}
		Node* root = create(1, m);
		root->flag = 1;
		judgeHeap(root);
		if(isheap.size() == 2)
		{
			printf("Not Heap\n");
		}else if(isheap.find(false) != isheap.end())
		{
			printf("Max Heap\n");
		}else if(isheap.find(true) != isheap.end())
		{
			printf("Min Heap\n");
		}
		postorder(root, root->data);
		allnodes.clear();
		isheap.clear();
	}
	system("pause");
	return 0;

}