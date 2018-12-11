#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;
int toll[25];
typedef struct Record
{
	string name;
	set <int> on_time;
	set <int> off_time;
}Record;
int main()
{
	int n;
	map<string, Record*> user_map;
	for(int i = 0; i <= 24; i++)
	{
		scanf("%d", &toll[i]);
	}
	for(int i = 0; i < n; i++)
	{
		string user;
		cin>>user;
		if(user_map.find(user) == user_map.end())
		{
			Record record;
			record.name = user;
			user_map[user] = &record;
		}
		int month, day, hour, minute, time;
		scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
		string on_or_off;
		cin>>on_or_off;
		time = day * 24 * 60 + hour * 60 + minute;
		if(on_or_off == "on-line")
		{
			(*user_map[user]).on_time.insert(time);
		}else if(on_or_off == "off-line")
		{
			(*user_map[user]).off_time.insert(time);
		}
	}
	map<string, Record*>::iterator it = user_map.begin();
	for(;it != user_map.end(); it++)
	{
		if()
	}
	

}