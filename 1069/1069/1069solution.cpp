#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
using namespace std;
int main()
{
	int same[] = {1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999};
	int N;
	scanf("%d", &N);
	for(int i = 0 ; i < 9; i++)
	{
		if(N == same[i])
		{
			printf("%d - %d = 0000", N , N);
			system("pause");
			return 0;
		}
	}
	while(true)
	{
		multiset <int> digits;
		int tmp = N;
		if(N < 10)
		{
			digits.insert(0);
			digits.insert(0);
			digits.insert(0);
		}else if(N < 100)
		{
			digits.insert(0);
			digits.insert(0);
		}else if(N < 1000)
		{
			digits.insert(0);
		}
		while (tmp > 0)
		{
			int d = tmp % 10;
			tmp = tmp / 10;
			digits.insert(d);
		}
		int big = 0, small = 0;
		multiset<int>::reverse_iterator it = digits.rbegin();
		int i = 0, j = 3;
		for(; it != digits.rend(); it++)
		{
			int q = *it;
			big += q * pow(10.0, j);
			small += q * pow(10.0, i);
			i++;
			j--;
		}
		N = big - small;
		printf("%04d - %04d = %04d\n", big, small, N);
		if(N == 6174)
			break;
	}

	system("pause");
	return 0;
}