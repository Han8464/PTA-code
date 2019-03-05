
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int nums[100010];
int main()
{
	int k;
	scanf("%d", &k);
	int x = 0;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &nums[i]);
		if(nums[i] < 0)
			x++;
	}
	if(x == k)
	{
		printf("0 %d %d", nums[0], nums[k - 1]);
		system("pause");
		return 0;
	}
	int sum = 0;
	int index = 0;
	int s = 0;
	int maxsum = -1; 
	int mins, mine;
	for(int i = 0; i < k; i++)
	{
		sum += nums[i];
		if(sum < 0)
		{
			sum = 0;
			s = i + 1;
		}else if(sum > maxsum)
		{
			maxsum = sum;
			mins = s;
			mine = i;

		}
	}
	printf("%d %d %d", maxsum, nums[mins], nums[mine]);
	return 0;
}
