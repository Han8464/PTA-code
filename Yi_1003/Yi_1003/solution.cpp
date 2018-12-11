
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int tag = 0;
bool judge(string s)
{
	int numP = 0, numT = 0;
	for(int j = 0; j < s.size(); j++)
	{
		if(s[j] != 'P' && s[j] != 'A' && s[j] != 'T')
		{
			tag = 1;
			return false;
		}else if(s[j] == 'P')
		{
			numP ++;
		}else if(s[j] == 'T')
		{
			numT ++;
		}
	}
	if(s.find("PAT") != s.npos && numP == 1 && numT == 1)
	{
		int diP = s.find("P");
		int diT = s.find("T");
		string x1 = s.substr(0, diP);
		string x2 = s.substr(diT + 1, s.size() - diP);
		if(x1 == x2)
		{
			return true;
		}else 
		{
			return false;
		}
	}else if (numP > 1 || numT > 1 || s.size() < 3 || numP == 0 ||  numT == 0)
	{
		tag = 2;
		return false;
	}else
	{
		int diP = s.find("P");
		int diT = s.find("T");
		string x1 = s.substr(0, diP);
		string b(s.substr(diP + 1, diT - diP - 1));
		string x2 = s.substr(diT + 1, s.size() - diP);
		if(x1.size() * b.size() == x2.size())
		{
			return true;
		}else
		{
			return false;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		string s;
		cin>>s;
		bool tmp = judge(s);
		if(tmp == false)
		{
			printf("NO\n");
		}else if(tmp == true)
		{
			printf("YES\n");
		}
	}
	system("pause");
	return 0;
}