#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	map<string, int>RankList;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		string id;
		cin>>id;
		RankList[id] = i;
	}
	int k;
	scanf("%d", &k);
	set<string> query;
	map<int, string>result;
	vector<string> v;
	for(int i = 0; i < k; i++)
	{
		string q_id;
		cin>>q_id;
		v.push_back(q_id);
		int order;
		if(RankList.find(q_id) == RankList.end())
		{
			order = 0;
		}else if(query.find(q_id) == query.end())
		{
			
			query.insert(q_id);
			order = RankList[q_id];
		}else
		{
			order = -1;
		}
		if(order == 1)
		{
			result[i] = "Mystery Award";
			continue;
		}else if(order == 0)
		{
			result[i] = "Are you kidding?";
			continue;
		}else if(order == -1)
		{
			result[i] = "Checked";
			continue;
		}
		int flag = 1;
		for(int j = 2; j < order/2; j++)
		{
			if((order % j) ==0)
			{
				flag = 0;
			}
		}
		if(flag == 0)
		{
			result[i] = "Chocolate";
		}else
		{
			result[i] = "Minion";
		}	
	}
	vector<string>::iterator it = v.begin();
	int i = 0;
	for(; it != v.end(); it++)
	{
		cout<<*it<<": ";
		cout<<result[i]<<endl;
		i++;
	}
	system("pause");
	return 0;
}