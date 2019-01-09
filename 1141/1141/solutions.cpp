#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct Stu
{
	string id;
	int score;
	string school;
}Stu;

typedef struct Sch
{
	string name;
	int sa, sb, st, cnt;
	int total;
}Sch;

bool comp(Sch* s1, Sch* s2)
{
	if(s1->total == s2->total)
	{
		if(s1->cnt == s2->cnt)
		{
			return s1->name < s2->name;
		}else
		{
			return s1->cnt < s2->cnt;
		}
	}
	return s1->total > s2->total;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<Sch*> sch_v;
	map<string, Sch*> sch_map;
	for(int i = 0; i < n; i++)
	{
		string id, school;
		int score;
		cin>>id>>score>>school;
		transform(school.begin(), school.end(), school.begin(), tolower);
		if(sch_map.find(school) == sch_map.end())
		{
			Sch* s = new Sch();
			s->name = school;
			s->cnt = 1;
			if(id[0] == 'A')
			{
				s->sa = score;
				s->sb = 0;
				s->st = 0;
			}else if(id[0] == 'B')
			{
				s->sa = 0;
				s->sb = score;
				s->st = 0;
			}else if(id[0] == 'T')
			{
				s->sa = 0;
				s->sb = 0;
				s->st = score;
			}
			sch_map[school] = s;
		}else
		{
			sch_map[school]->cnt ++;
			if(id[0] == 'A')
			{
				sch_map[school]->sa += score;
			}else if(id[0] == 'B')
			{
				sch_map[school]->sb += score;
			}else if(id[0] == 'T')
			{
				sch_map[school]->st += score;
			}
		}
	}
	map<string, Sch*>::iterator it = sch_map.begin();
	for(; it != sch_map.end(); it++)
	{
		it->second->total = it->second->sa + it->second->sb / 1.5 + it->second->st * 1.5;
		sch_v.push_back(it->second);
	}

	sort(sch_v.begin(), sch_v.end(), comp);
	cout<<sch_v.size()<<endl;
	int i = 1;
	int pre_scor = sch_v[0]->total;
	for(int t = 0; t < sch_v.size(); t++)
	{
		if(sch_v[t]->total == pre_scor)
		{
			cout<<i<<" "<<sch_v[t]->name<<" "<<sch_v[t]->total<<" "<<sch_v[t]->cnt<<endl;
		}else
		{
			i = t + 1;
			cout<<i<<" "<<sch_v[t]->name<<" "<<sch_v[t]->total<<" "<<sch_v[t]->cnt<<endl;
		}
		pre_scor = sch_v[t]->total; 
	}
	system("pause");
	return 0;
}