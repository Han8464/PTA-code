#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Stu
{
	string id;
	int gp, gm, gf;
	int g;
}Stu;
Stu stus[10010];
map<string, Stu>id_stu_map;

bool comp(Stu s1, Stu s2)
{
	if(s1.g == s2.g)
	{
		return s1.id < s2.id;
	}
	return s1.g > s2.g;
}

int main()
{
	int p, m, n;
	scanf("%d%d%d", &p, &m, &n);
	for(int i = 0; i < p; i++)
	{
		string id;
		int score1;
		cin>>id>>score1;
		id_stu_map[id].id = id;
		id_stu_map[id].gp = score1;
		id_stu_map[id].gm = -1;
		id_stu_map[id].gf = -1;
	}
	for(int i = 0; i < m; i++)
	{
		string id; 
		int score2;
		cin>>id>>score2;
		if(id_stu_map.find(id) == id_stu_map.end())
		{
			id_stu_map[id].id = id;
			id_stu_map[id].gm = score2;
			id_stu_map[id].gp = -1;
			id_stu_map[id].gf = -1;
		}else
		{
			id_stu_map[id].gm = score2;
		}
	}
	for(int i = 0; i < n; i++)
	{
		string id; 
		int score3;
		cin>>id>>score3;
		if(id_stu_map.find(id) == id_stu_map.end())
		{
			id_stu_map[id].id = id;
			id_stu_map[id].gf = score3;
			id_stu_map[id].gp = -1;
			id_stu_map[id].gm = -1;
		}else
		{
			id_stu_map[id].gf = score3;
		}
	}

	map<string, Stu>::iterator it = id_stu_map.begin();
	int index = 0;
	for(; it != id_stu_map.end(); it++)
	{
		if(it->second.gp >= 200)
		{
			if(it->second.gm > it->second.gf)
			{
				float tmp = it->second.gm * 0.4 + it->second.gf * 0.6;
				it->second.g = int(tmp + 0.5);
			}else
			{
				it->second.g = it->second.gf;
			}
			if(it->second.g >= 60)
			{
				stus[index].id = it->second.id;
				stus[index].gp = it->second.gp;
				stus[index].gm = it->second.gm;
				stus[index].gf = it->second.gf;
				stus[index].g = it->second.g;
				index++;
			}
		}
	}

	sort(stus, stus + index, comp);
	for(int i = 0; i < index; i++)
	{
		cout<<stus[i].id;
		printf(" %d %d %d %d\n", stus[i].gp, stus[i].gm, stus[i].gf, stus[i].g);
	}
	system("pause");
	return 0;
}