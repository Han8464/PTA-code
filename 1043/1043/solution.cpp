#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct Node
{
	int data;
	Node* left;
	Node* right;
}Node;
vector<int> allnodes;
void insert(Node* &root, int x)
{
	if(root == NULL)
	{
		root = new Node;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if(x >= root->data)
	{
		insert(root->right, x);
	}else
	{
		insert(root->left, x);
	}
}


Node* create()
{
	Node* root = NULL;
	for(int i = 0; i < allnodes.size(); i++)
	{
		insert(root, allnodes[i]);
	}
	return root;

}

int main()
{
	int n;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		allnodes.push_back(tmp);
	}
	Node* root = create();


}
