#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;
int n;
int min_length = 0;
int total_teams = 0;
int roads[510][510] = {0};
int c1,c2;
int visited[510] = {0};
int minNum = 0;
int len_tmp;
int teams_tmp;
map <int, int> teamNum;
int calRoad(int c1)
{
	if(c1 == c2)//³ö¿Ú
	{
		if(len_tmp < min_length)
		{
			minNum = 1;
			min_length = len_tmp;
			total_teams = teams_tmp;
		}else if(len_tmp == min_length)
		{
			minNum ++;
			if(teams_tmp > total_teams)
			{
				total_teams = teams_tmp;
			}
		}
		return 0;                                                                                                
	}
	visited[c1] = 1;
	teams_tmp += teamNum[c1];
	for(int i = 0; i < n; i++)
	{
		if(roads[c1][i] != 0 && visited[i] != 1)
		{
			len_tmp += roads[c1][i];
			calRoad(i);
			teams_tmp -= teamNum[i];
			len_tmp -= roads[c1][i];
		}
	}
	return 0;
}
int main()
{
	int m;
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		teamNum.insert(tmp);
	}
	for(int i = 0; i < m; i++)
	{
		int n1,n2,wght;
		scanf("%d%d%d", &n1, &n2, &wght);
		roads[n1][n2] = wght;
		roads[n2][n1] = wght;
		min_length += wght;
	}
	calRoad(c1);
	printf("%d %d", min_length, total_teams);
	system("pause");
	return 0;
}