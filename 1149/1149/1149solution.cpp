#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;
short pairincom[100000][10010] = {0};
//vector <string> pairIn;

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	string result[110];
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		
		for(int j = 0; j < 10010; j++)
		{
			if(pairincom[a][j] == 0)
			{
				pairincom[a][j] = b;
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		set<int> s;
		for(int j = 0; j < k; j++)
		{
			int g;
			scanf("%d", &g);
			s.insert(g);
		}
		int flag = 0;
		set<int>::iterator it = s.begin();
		for(; it != s.end(); it++)
		{
			for(int p = 0; p < 10010; p++)
			{
				if(pairincom[*it][p] != 0)
				{
					if(s.find(pairincom[*it][p]) != s.end())
					{
						result[i] = "No";
						flag = 1;
						break;
					}
				}else
				{
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 0)
		{
			result[i] = "Yes";
		}
	}

	for(int i = 0; i < m; i++)
	{
		cout<<result[i]<<endl;
	}
	system("pause");
	return 0;
}