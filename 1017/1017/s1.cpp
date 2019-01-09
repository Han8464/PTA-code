#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct Customer
{
	int arrival, p;
}Customer;

Customer customers[10010];

int comp(int a, int b)
{
	return a < b;
}

int customer_comp(Customer c1, Customer c2)
{
	return comp(c1.arrival, c2.arrival);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		scanf("%d", &customers[i].p);
		customers[i].arrival = h * 3600 + m * 60 + s;
	}
	int start = 8 * 3600;
	int end = 17 * 3600;
	int end_time[110];
	for(int i = 0; i < 110; i++)
	{
		end_time[i] = start;
	}
	int x = 0, no_count = 0;
	int total = 0;
	sort(customers, customers + n, customer_comp);
	for(int i = 0; i < n; i++)
	{
		if(customers[i].arrival > end)
		{
			no_count++;
			continue;
		}
		sort(end_time, end_time + k, comp);
		if(customers[i].arrival < end_time[0])
		{
			total += (end_time[0] - customers[i].arrival);
			end_time[0] = end_time[0] + customers[i].p * 60;
		}else
		{
			end_time[0] = customers[i].arrival + customers[i].p * 60;
		}
	
	}
	n -= no_count;
	if(n == 0)
	{
		printf("0.0");
	}else
	{
		double res = total / 60.0 / n;
		printf("%.1lf", res);
	}
	system("pause");
	return 0;

}