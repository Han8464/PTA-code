
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef struct Info
{
	char level;
	int site;
	int date;
	int number;
	int score;
	string s;

}Info;
Info info[100];

int com(Info info1, Info info2)
{
	return info1.score > info2.score;
}
int com1(Info info1, Info info2)
{
	return info1.s > info2.s;
}
int main()
{
	Info info_tmp[100];
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		char in[14];
		scanf("%s", &in);
		info[i].level = in[0];
		info[i].site = (in[1] - '0') * 100 + (in[2] - '0' ) * 10 + in[3] - '0';
		info[i].date = (in[4] - '0') * 100000 + (in[5] - '0') * 10000 + (in[6] - '0' ) * 1000 + (in[7] - '0') * 100 + (in[8] - '0' ) * 10 + in[9] - '0';
		info[i].number = (in[10] - '0') * 100 + (in[11] - '0' ) * 10 + in[12] - '0';
		info[i].s = in;
		scanf("%d", &info[i].score);
	}
	for(int i = 0; i < m ; i++)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)
		{
			char term;
			getchar();
			scanf("%c", &term);
			int level_s = 0;
			for(int j = 0; j < n; j++)
			{
				if(info[j].level == term)
				{
					info_tmp[level_s] = info[j];
					level_s++;
				}
			}
			sort(info_tmp, info_tmp + level_s, com);
			printf("Case %d: %d %c\n", i+1, type, term);
			if(level_s == 0)
			{
				printf("NA\n");
			}
			int k = 1;
			for(int j = 0; j < level_s;j++)
			{
				if(j != 0)
				{
					if(info_tmp[j].score == info_tmp[j - 1].score)
					{
						k++;
					}else
					{
						sort(info_tmp + j + 1, info_tmp + j + k + 2, com1);
						k = 1;
					}
				}
			}
			for(int j = 0; j < level_s; j++)
			{
				printf("%c%03d%06d%03d %d\n", info_tmp[j].level, info_tmp[j].site, info_tmp[j].date, info_tmp[j].number, info_tmp[j].score);	
			}
		}else if(type == 2)
		{
			int g_site;
			scanf("%d", &g_site);
			int s_num = 0;
			int s_score = 0;
			for(int j = 0; j < n; j++)
			{
				if(info[j].site == g_site)
				{
					s_num++;
					s_score += info[j].score;

				}
			}
			printf("Case %d: %d %d\n", i+1, type, g_site);
			if(s_num == 0)
			{
				printf("NA\n");
			}else
			{
				printf("%d %d\n", s_num, s_score);
			}
		}else if(type ==3)
		{
			int g_date;
			scanf("%d", &g_date);
			map<int, int> site_n_map;
			map<int, set<int>> n_site_map;
			multiset<int> n_set;
			int sites[1010];
			int numOfSites = 0;
			for(int j = 0; j < n; j++)
			{
				if(info[j].date == g_date)
				{
					if(site_n_map.find(info[j].site) == site_n_map.end())
					{
						sites[numOfSites] = info[j].site;
						numOfSites ++;
						site_n_map[info[j].site] = 1;
					}else
					{
						site_n_map[info[j].site]++;
					}
				}
			}
			for(int x = 0; x < numOfSites; x++)
			{
				n_site_map[site_n_map[sites[x]]].insert(sites[x]);
				n_set.insert(site_n_map[sites[x]]);
			}
			printf("Case %d: %d %d\n", i+1, type, g_date);
			if(numOfSites == 0)
			{
				printf("NA\n");
			}else
			{
				multiset<int>::reverse_iterator it = n_set.rbegin();
				for(; it != n_set.rend(); it++)
				{
					set<int>::iterator it1 = n_site_map[*it].begin();
					printf("%d %d\n", *it1, *it);
					n_site_map[*it].erase(it1);
				}
			}
		}
	}
	system("pause");
	return 0;
}