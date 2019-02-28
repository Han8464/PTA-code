#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;
vector<int> numbers;
int ans[10010][10010];
int main()
{
	int n;
	scanf("%d", &n);
	for(int ii = 0; ii < n; ii++)
	{
		int tmp;
		scanf("%d", &tmp);
		numbers.push_back(tmp);
	}
	sort(numbers.begin(), numbers.end(), greater<int>());
	int z = sqrt((double)n);
	int b;
	for(int ii = z; ii >= 1; ii++)
	{
		if(n % ii == 0)
		{
			b = ii;
			break;
		}
	}
	int a = n / b;
	if(a < b)
	{
		int ta = a;
		a = b;
		b = ta;
	}

	int dir = 0;
	int t1 = 0;
	int	t2 = a;
	int t3 = 0;
	int t4 = b;
	int i = 0;//0-a
	int j = 0;//0-b
	for(int k = 0; k < numbers.size(); k++)
	{
		if(dir == 0)
		{
			ans[i][j] = numbers[k];
			j++;
			if(j == t4)
			{
				t4--;
				dir = 1;
				j--;
				i++;
				continue;
			}
		}
		if(dir == 1)
		{
			ans[i][j] = numbers[k];
			i++;
			if(i == t2)
			{
				t2--;
				dir = 2;
				i--;
				j--;
				continue;
			}
		}
		if(dir == 2)
		{
			ans[i][j] = numbers[k];
			j--;
			if(j < t3)
			{
				t3++;
				dir = 3;
				j++;
				i--;
				continue;
			}
		}
		if(dir == 3)
		{

			ans[i][j] = numbers[k];
			i--;
			if(i == t1)
			{
				t1++;
				dir = 0;
				i = t1;
				j = t3;
				continue;
			}
		}
	}

	for(int aa = 0; aa < a; aa++)
	{
		for(int bb = 0; bb < b; bb++)
		{
			if(bb == b - 1)
			{
				printf("%d\n", ans[aa][bb]);
			}else
			{
				printf("%d ", ans[aa][bb]);
			}
		}
	}

	system("pause");
	return 0;

}