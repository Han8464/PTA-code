#include <cstdio>
#include <cstdlib>
#include <set>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	set<int>set_t;
	for(int i = 0; i < n; i++)
	{
		int number;
		cin>>number;
		if(number <= 9)
		{
			if(set_t.find(number) == set_t.end())
			{
				set_t.insert(number);
			}

		}else
		{
			int id = 0;
			while(number > 0)
			{
				id += (number % 10);
				number = number / 10;
			}
			if(set_t.find(id) == set_t.end())
			{

				set_t.insert(id);
			}
		}
	}
	printf("%d\n", set_t.size());
	set<int>::iterator it;
	int length = set_t.size();
	for(it = set_t.begin(); it != set_t.end(); it++)
	{
		if(length == 1)
		{
			printf("%d", *it);
		}else
		{
			printf("%d ", *it);
		}
		length --;
	}
	
	system("pause");
	return 0;
}