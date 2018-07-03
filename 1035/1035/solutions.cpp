#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	int record[1000];
	string ids[1000];
	string pwds[1000];
	scanf ("%d",&N);
	int r = 0;
	for(int i = 0; i < N ;i++)
	{
		int sig = 0;
		cin>>ids[i]>>pwds[i];
		int len = pwds[i].length();
		for(int j = 0; j < len; j++)
		{
			if(pwds[i][j] == '1')
			{
				pwds[i][j] = '@';
				sig = 1;
			}else if(pwds[i][j] == '0')
			{
				pwds[i][j] = '%';
				sig = 1;
			}else if(pwds[i][j] == 'l')
			{
				pwds[i][j] = 'L';
				sig = 1;
			}else if(pwds[i][j] == 'O')
			{
				pwds[i][j] = 'o';
				sig = 1;
			}
		}
		if(sig == 1)
		{
			record[r] = i;
			r ++;
		}

	}
	if(r == 0 && N == 1)
	{
		cout<<"There is "<<N<<" account and no account is modified"<<endl;
		system("pause");
		return 0;
	}else if(r == 0 && N > 1)
	{
		cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
		system("pause");
		return 0;
	}
	cout<<r<<endl;
	r = r - 1;
	int j = 0;
	while(j <= r)
	{
		cout<<ids[record[j]]<<" "<<pwds[record[j]]<<endl;
		j++;
	}
	system("pause");
	return 0;

}