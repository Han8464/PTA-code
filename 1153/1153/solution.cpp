/*
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
Info info[10010];
Info info_tmp[10010];
typedef struct SiteNumber
{
	int site;
	int n;
}SiteNumber;
SiteNumber siteNs[10010];

int com(Info info1, Info info2)
{
	if(info1.score == info2.score)
	{
		return info1.s < info2.s;
	}
	return info1.score > info2.score;
}
int com2(SiteNumber s1, SiteNumber s2)
{
	if(s1.n == s2.n)
	{
		return s1.site < s2.site;
	}else
	{
		return s1.n > s2.n;
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	//输入
	for(int i = 0; i < n; i++)
	{
		char in[14];
		scanf("%s", in);
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

			int level_s = 0;//level为term的考生总数
			//找到所有Level为term的info存到info_tmp
			for(int j = 0; j < n; j++)
			{
				if(info[j].level == term)
				{
					info_tmp[level_s] = info[j];
					level_s++;
				}
			}
			//排序
			sort(info_tmp, info_tmp + level_s, com);
			printf("Case %d: %d %c\n", i+1, type, term);
			if(level_s == 0)
			{
				printf("NA\n");
			}else
			{
				for(int j = 0; j < level_s; j++)
				{
					printf("%c%03d%06d%03d %d\n", info_tmp[j].level, info_tmp[j].site, info_tmp[j].date, info_tmp[j].number, info_tmp[j].score);
				}
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
			printf("Case %d: %d %03d\n", i+1, type, g_site);
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
			map<int, int>site_n_map;
			for(int j = 0; j < n; j++)
			{
				if(info[j].date == g_date)
				{
					if(site_n_map.find(info[j].site) == site_n_map.end())
					{
						site_n_map[info[j].site] = 1;
					}else
					{
						site_n_map[info[j].site]++;
					}

				}
			}
			map<int, int>::iterator it = site_n_map.begin();
			int nOfSites = 0;
			for(; it != site_n_map.end(); it++)
			{
				siteNs[nOfSites].site = it->first;
				siteNs[nOfSites].n = it->second;
				nOfSites++;
			}
			sort(siteNs, siteNs + nOfSites, com2);
			printf("Case %d: %d %06d\n", i+1, type, g_date);
			if(nOfSites == 0)
			{
				printf("NA\n");
			}else
			{
				for(int j = 0; j < nOfSites; j++)
				{
					printf("%03d %d\n", siteNs[j].site, siteNs[j].n);
				}
			}
		}else
		{
			char tmp[10000];
			scanf("%s", tmp);
			printf("Case %d: %d %s\n", i+1, type, tmp);
			printf("NA\n");
		}
	}
	system("pause");
	return 0;
}*/