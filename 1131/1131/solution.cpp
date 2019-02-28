#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
typedef struct Node
{
	int number;
	vector<int> line;
	vector<Node*> nextNode;
}Node;

map<int, Node*> number_map;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		vector<int> nodes;
		if(m > 0)
		{
			int tmp;
			scanf("%d", &tmp);
			nodes.push_back(tmp);
			Node* r = new Node;
			r->number = tmp;
			r->line.push_back(i + 1);
			number_map[tmp] = r;
		}
		for(int j = 1; j < m; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			nodes.push_back(tmp);
			if(number_map.find(tmp) == number_map.end())
			{
				Node* r = new Node;
				r->number = tmp;
				r->line.push_back(i);
				number_map[tmp] = r;
			}else
			{
				number_map[tmp]->line.push_back(i + 1);
			}
			number_map[nodes[j - 1]]->nextNode.push_back(number_map[tmp]);
			number_map[tmp]->nextNode.push_back(number_map[nodes[j - 1]]);
		}
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		Node* r1 = number_map[a];
		Node* r2 = number_map[b];


	}

	system("pause");
	return 0;

}