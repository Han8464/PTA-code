#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
typedef struct Node
{
	int id;
	int left;
	int right; 
}Node;

map<int, Node*> id_map;
map<int, int>pre;
vector<int> q;
void check(Node* root)
{
	int x = 0;
	q.push_back(root->id);
	while(x < q.size())
	{
		if(q[x] != -1)
		{
			q.push_back(id_map[q[x]]->left);
			q.push_back(id_map[q[x]]->right);
		}
		x++;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		char a[20];
		char b[20];
		scanf("%s%s", a, b);
		Node* root = new Node;
		root->id = i;
		root->left = root->right = -1;
		if(pre.find(i) == pre.end())
		{
			pre[i] = i;
		}
		if(a[0] != '-')
		{
			int t1;
			sscanf(a, "%d", &t1);
			root->left = t1;
			pre[t1] = i;
		}
		if(b[0] != '-')
		{
			int t2;
			sscanf(b, "%d", &t2);
			root->right = t2;
			pre[t2] = i;
		}
		id_map[i] = root;
	}
	map<int, int>::iterator it = pre.begin();
	Node* node;
	for(; it != pre.end(); it++)
	{
		if(it->first == it->second)
		{
			 node = id_map[it->first];
			break;
		}
	}
	check(node);
	int flag = 0;
	int lastid;
	bool iscomplete = true;
	for(int i = 0; i < q.size(); i++)
	{
		if(q[i] != -1 && flag == 1)
		{
			iscomplete = false;
			break;
		}
		if(q[i] == -1 && flag == 0)
		{
			flag = 1;
			lastid = q[i - 1];
		}
	}
	if(iscomplete)
	{
		printf("YES %d", lastid);
	}else
	{
		printf("NO %d", q[0]);
	}
	system("pause");
	return 0;
}
