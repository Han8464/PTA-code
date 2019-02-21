#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> preorder;
vector<int> inorder;
int find(int a, int b, int k)
{
	if(a == b)
		return a;
	for(int i = a; i <= b; i++)
	{
		if(inorder[i] == preorder[k])
		{
			if(i == a)
			{
				find(i + 1, b, k+1);
				break;
			}else
			{
				find(a, i - 1, k+1);
				break;
			}
		}
	}
}
int main()
{

	int n;
	scanf("%d", &n);
	int root;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		preorder.push_back(tmp);
	}
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if(tmp == preorder[0])
		{
			root = i;
		}
		inorder.push_back(tmp);
	}
	int index = find(0,n - 1, 0);
	printf("%d", inorder[index]);
	system("pause");
	return 0;
}