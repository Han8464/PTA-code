#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
    vector<int> num;
	map<int, int> num_map;
	int tmp;
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&tmp);
		num.push_back(tmp);
		num_map[tmp] ++;
	}
	for(int j = 0; j < N; j++)
	{
		if(num_map[num[j]] == 1)
		{
			printf("%d",num[j]);
			system("pause");
			return 0;
		}
	}
	printf("None");
	system("pause");
	return 0;
}