#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int toll[25];
typedef struct Record
{
	char name[22];
	int num_on;
	int num_off;
	int on_time[1010];
	int off_time[1010];
}Record;
Record records[1010];
int main()
{
	int n;

	for(int i = 0; i <= 24; i++)
	{
		scanf("%d", &toll[i]);
	}
	for(int i = 0; i < n; i++)
	{
		char user[22];
		scanf("%s", user);
		int month, day, hour, minute, time;
		scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
		string on_or_off;
		cin>>on_or_off;
		time = day * 24 * 60 + hour * 60 + minute;
		if(on_or_off == "on-line")
		{

		}
	}
	

}