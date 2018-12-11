#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int visited[10000] = {0};
	int nums[120];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
		int tmp = nums[i];
		while (tmp != 1)
		{
			if(tmp % 2 == 0)
			{
				tmp = tmp / 2;
				visited[tmp] = 1;
			}else
			{
				tmp = (3 * tmp + 1) / 2;
				visited[tmp] = 1;
			}
		}
	}
	set<int> num_set;
	for(int i = 0; i < n; i++)
	{
		if(visited[nums[i]] == 0)
		{
			num_set.insert(nums[i]);
		}
	}
	set<int>::reverse_iterator it = num_set.rbegin();
	if(it != num_set.rend())
	{
		printf("%d", *it);
		it++;
		for(it;it != num_set.rend(); it++)
		{
			printf(" %d", *it);
		}
	}
	system("pause");
	return 0;
}