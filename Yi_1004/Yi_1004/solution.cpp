#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Info
{
	string name;
	string id;
	int score;
}Info;
Info info [1010];
int com(Info info1, Info info2)
{
	return info1.score > info2.score;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		cin>>info[i].name;
		cin>>info[i].id;
		cin>>info[i].score;
	}
	sort(info, info + n, com);
	cout<<info[0].name<<" "<< info[0].id<<endl;
	cout<<info[n - 1].name<<" "<<info[n - 1].id;
	system("pause");
	return 0;
}