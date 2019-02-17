#include<cstdio>
#include <cstdlib>
#include <math.h>
#include <cstring>
using namespace std;
bool IsPrime(int n)
{
	if(n == 2 || n == 3)
		return true;
	if(n % 6 != 5 && n % 6 != 1)
		return false;
	for(int i = 5; i < sqrt(double(n)); i += 6)
	{
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

int NextPrime(int n)
{
	int i = n + 1;
	while(!IsPrime(i))
	{
		i++;
	}
	return i;
}

int main()
{

	int msize, n, m;
	int table[10010];
	memset(table, -1, sizeof(table));
	scanf("%d%d%d", &msize, &n, &m);
	if(!IsPrime(msize))
		msize = NextPrime(msize);
	for(int i = 0; i < n; i++)
	{
		int tmp; 
		scanf("%d", &tmp);
		int tag = 0;
		for(int x = 0; x < msize; x++)
		{
			int d = x * x;
			int index = (tmp % msize + d) % msize;
			if(table[index] == -1)
			{
				table[index] = tmp;
				tag = 1;
				break;
			}
		}
		if(tag == 0)
		{
			printf("%d cannot be inserted.\n", tmp);
		}
	}

	int total = 0;
	for(int i = 0; i < m; i++)
	{
		int number;
		scanf("%d", &number);
		bool found = false;
		for(int x = 0; x < msize; x++)
		{
			total++;
			int d1 = x * x;
			int index1 = (number % msize + d1) % msize;
			if(table[index1] == number || table[index1] == -1)
			{
				found = true;
				break;
			}
		}
		if(found == false)
			total++;

	}

	printf("%0.1f\n", total / (double)m);
	system("pause");
	return 0;

}