/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct Time
{
	int h, m, s;
}time;
typedef struct Customer
{
	time t;
	int p;
}customer;

customer customers[10010] ;
bool com(customer c1, customer c2)
{
	if(c1.t.h > c2.t.h)
	{
		return false;
	}else if(c1.t.h == c2.t.h)
	{
		if(c1.t.m > c2.t.m)
		{
			return false;
		}else if(c1.t.m == c2.t.m)
		{
			if(c1.t.s > c2.t.s)
				return false;
		}
	}
	return true;
}
bool time_com(time t1, time t2)
{
	if(t1.h > t2.h)
	{
		return false;
	}else if(t1.h == t2.h)
	{
		if(t1.m > t2.m)
		{
			return false;
		}else if(t1.m == t2.m)
		{
			if(t1.s > t2.s)
				return false;
		}
	}
	return true;
}
double time_minus(time t1, time t2)
{
	time t;
	double m = 0;
	if(t1.s >= t2.s)
	{
		t.s = t1.s - t2.s;
	}else
	{
		t.s = t1.s + 60 - t2.s;
		t1.m = t1.m - 1;
	}
	if(t1.m  >= t2.m)
	{
		t.m = t1.m - t2.m;
	}else
	{
		t.m = t1.m + 60 - t2.m;
		t1.h = t1.h - 1;
	}
	t.h = t1.h - t2.h;
	m = (double)t.s / 60 + t.h * 60 + t.m;
	return m;
}
time time_plus(time t1, int m)
{
	time t;
	t.s = t1.s;
	t.m = t1.m + m;
	if(t.m >= 60)
	{
		t.m -= 60;
		t.h = t1.h + 1;
	}else
	{
		t.h = t1.h;
	}
	return t;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d:%d:%d", &customers[i].t.h, &customers[i].t.m, &customers[i].t.s);
		scanf("%d", &customers[i].p);
	}
	sort(customers, customers + n, com);
	double total_time = 0;
	time end_time[110];
	int x = 1;
	int no_count = 0;
	time start = {8, 0, 0};
	time end = {17, 0, 0};
	for(int i = 0; i < n; i++)
	{
		if(!time_com(customers[i].t, end))
		{
			no_count ++;
			continue;
		}
		if(x <= k)
		{
			if(customers[i].t.h < 8)
			{
				total_time += time_minus(start, customers[i].t);
				end_time[x] = time_plus(start, customers[i].p);
				x++;
			}else
			{
				end_time[x] = time_plus(customers[i].t, customers[i].p);
				x++;
			}

		}else
		{
			sort(end_time + 1, end_time + k + 1, time_com);
			if(!time_com(customers[i].t, end_time[1]))
			{
				end_time[1] = time_plus(customers[i].t, customers[i].p);
			}else
			{
				double tmp = time_minus(end_time[1], customers[i].t);
				total_time += tmp;
				end_time[1] = time_plus(end_time[1], customers[i].p);
			}
		}
	}
	n -= no_count;
	if(n != 0)
	{
		printf("%.1lf", total_time / n);
	}else
	{
		printf("0.0");
	}
	system("pause");
	return 0;
}
*/