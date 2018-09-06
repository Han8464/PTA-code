#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int m,n,s;
	set<string> set;
	string result[1010];
	int res_index = 0;
	scanf("%d%d%d", &m, &n, &s);
	int tmp = n;
for(int i = 0; i < m; i++)
		{
			string name;
			cin>>name;
			if(i == s - 1)
			{
				result[res_index] = name;
				res_index ++;
				set.insert(name);
				tmp --;
			}else if(i > s - 1)
			{
				if(tmp == 0)
				{
					if(set.find(name) == set.end())
					{
						set.insert(name);
						result[res_index] = name;
						res_index++;
						if(n == 1)
						{
							tmp = n;
						}else
						{
							tmp = n + 1;
						}
					}else
					{
						tmp = 1;
					}
	
				}
				tmp --;
			}
		}
	if(res_index == 0)
	{
		printf("Keep going...");
	}else
	{
		for(int i = 0; i < res_index; i++)
		{
			cout<<result[i]<<endl;
		}
	}
	return 0;
}