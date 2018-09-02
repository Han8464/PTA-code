#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int main()
{
	int k;
	string result[250];
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		set<int> set_q;
		int q[1012];
		int n;
		scanf("%d", &n);
		int flag = 0;
		for(int j = 1; j <= n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if(set_q.find(tmp) == set_q.end())
			{
				set_q.insert(tmp);
				q[j] = tmp;
			}else{
				result[i] = "NO";
				flag = 1;
			}
		}
		if (flag == 1)
		{
			continue;
		}
		for(int j = 1; j <= n; j++)
		{
			for(int m = j + 1; m <= n; m++)
			{
				if((m - j) == (q[m] - q[j]) || (m - j) == -(q[m] - q[j]))
				{
					result[i] = "NO";
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				break;
			}
		}
		if(flag == 1)
		{
			continue;
		}else
		{
			result[i] = "YES";
		}
	}
	for(int i = 0; i < k; i++)
	{
		cout<<result[i]<<endl;
	} 
	system("pause");
	return 0;
}