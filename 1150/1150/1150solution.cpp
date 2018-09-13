#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
bool vis[220];
int main()
{
	int g[220][220] = {0};
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int>res1;
	int shortestd = 20000;
	int shortesti = 0;
	vector<string>res2;
	for(int i = 0; i < m; i++)
	{
		int c1, c2 , d;
		scanf("%d%d%d", &c1, &c2, &d);
		g[c1][c2] = g[c2][c1] = d;
	}
	int k;
	scanf("%d", &k);
	for(int p = 0; p < k; p++)
	{
		int tl_ct;
		scanf("%d", &tl_ct);
		int len = 0;
		vector<int>ct;
		memset(vis,0,sizeof(vis));
		int cnt = n;
		for(int i = 0; i < tl_ct; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			ct.push_back(tmp);
			if(!vis[tmp]) 
			{
			     vis[tmp]=true;
			     cnt--;
		     }
			//vector<int> ::iterator it = Iscycle.end() - 1;
		}
		if(tl_ct <= n)
		{
			int flag = 0;
			for(int i = 0; i < tl_ct - 1; i++)
			{
				if(g[ct.at(i)][ct.at(i + 1)] == 0 && ct.at(i) != ct.at(i + 1))
					{
						res1.push_back(-1);
						res2.push_back("(Not a TS cycle)");
						flag = 1;
						break;
					}else
					{
						len += g[ct.at(i)][ct.at(i + 1)];
					}
			}	
			if(flag == 0)
			{
				res1.push_back(len);
				res2.push_back("(Not a TS cycle)");
			}
		}else
		{
			int flag = 0;
			for(int i = 0; i < tl_ct - 1; i++)
			{
				if(g[ct.at(i)][ct.at(i + 1)] == 0 && ct.at(i) != ct.at(i + 1))
				{
					res1.push_back(-1);
					res2.push_back("(Not a TS cycle)");
					flag = 1;
					break;
				}else
				{
					len += g[ct.at(i)][ct.at(i + 1)];
				}
			}
			if(flag == 0)
				{
					if(ct[0] == ct[tl_ct - 1]  && !cnt)
					{
						if(tl_ct == (n + 1))
						{
							res1.push_back(len);
							if(len < shortestd)
							{
								shortestd = len;
								shortesti = p;
							}
							res2.push_back("(TS simple cycle)");
						}else
						{
							res1.push_back(len);
							if(len < shortestd)
							{
								shortestd = len;
								shortesti = p;
							}
							res2.push_back("(TS cycle)");
								
						}
					}else
					{
						res1.push_back(len);
						res2.push_back("(Not a TS cycle)");
					}
				}
		}

	}

	vector<int>::iterator it1 = res1.begin();
	vector<string>::iterator it2 = res2.begin();
	int i = 1;
	while(it1 != res1.end())
	{
		if(*it1 == -1)
		{			
			printf("Path %d: NA ", i);
			cout<<*it2<<endl;

		}else
		{
			printf("Path %d: %d ", i, *it1);
			cout<<*it2<<endl;
		}
		it1++;
		it2++;
		i++;
	}
	printf("Shortest Dist(%d) = %d", shortesti + 1, shortestd);

	system("pause");
	return 0;
}