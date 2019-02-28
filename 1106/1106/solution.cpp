#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
int minLen = 100001;
int nowLen = 0;
int counts = 0;
void dfs(int root)
{
	if(tree[root].size() == 0)
	{
		 if(nowLen < minLen)
		{
			minLen = nowLen;
			counts = 1;
		 }else if(nowLen == minLen)
			counts++;
		return;
	}
	for(int i = 0; i < tree[root].size(); i++)
	{
		nowLen++;
		dfs(tree[root][i]);
		nowLen--;
	}
}

int main()
{
	int n;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	for(int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		vector<int> tm;
		for(int j = 0; j < k; j++)
		{
			int ch;
			scanf("%d", &ch);
			tm.push_back(ch);
		}
		tree.push_back(tm);
	}
	dfs(0);
	double ans = p * pow((r * 0.01 + 1.0), minLen);
	printf("%.4lf %d", ans, counts);
	system("pause");
	return 0;
}