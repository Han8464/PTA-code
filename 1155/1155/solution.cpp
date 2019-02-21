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
}Node;
Node* root;
int allnodes[1010];
int n;
vector<int> leaves;
Node* create(int k)
{
	if(k <= n)
	{
		Node* r = (Node*)malloc(sizeof(Node));
		r->data = allnodes[k];
		r->left = create(k + k);
		r->right = create(k + k + 1);
		if(r->left == NULL && r->right == NULL)
			leaves.push_back(k);

		return r;
	}else
	{
		return NULL;
	}

}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &allnodes[i]);
	}

	root = create(1);
	int len = leaves.size();
	set<bool>heaptype;
	while(len > 0)
	{
		len--;
		int k = leaves[len];
		vector<int> path;
		path.push_back(k);
		set<bool> pathtype;
		while(k != 1)
		{
			if(k % 2 == 0)
			{
				path.push_back(k / 2);
				if(allnodes[k / 2] - allnodes[k] > 0)
				{
					pathtype.insert(true);
				}else
				{
					pathtype.insert(false);
				}
				k = k / 2;
			}else
			{
				path.push_back(k - k / 2 - 1);
				if(allnodes[k - k / 2 - 1] - allnodes[k] > 0)
				{
					pathtype.insert(true);
				}else
				{
					pathtype.insert(false);
				}
				k = k - k / 2 - 1;
			}
		}
		int l = path.size();
		for(int i = l - 1; i >= 0; i--)
		{
			if(i == 0)
			{
				printf("%d\n", allnodes[path[i]]);
			}else
			{
				printf("%d ", allnodes[path[i]]);
			}
		}
		if(pathtype.size() == 2)
		{
			heaptype.insert(true);
			heaptype.insert(false);
		}else
		{
			heaptype.insert(*pathtype.begin());
		}

	}
	if(heaptype.size() == 2)
	{
		printf("Not Heap");
	}else if(*heaptype.begin() == true)
	{
		printf("Max Heap");
	}else
	{
		printf("Min Heap");
	}
	system("pause");
	return 0;


}