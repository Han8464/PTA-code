#include <cstdio>
using namespace std;
typedef struct List
{
	int number;
	List* next;
}*list;

class TList
{
	int get(list head, int i)
	{
		int n = 0;
		list  tmp1 = head;
		while(n >= i)
		{
			tmp1 = tmp1->next;
			n++;
			if(n == i)
			{
				return tmp1->number;
			}
		}
		return 0;
	}
	int remove(list head, int i)
	{
		int n = 0;
		list tmp1 = head, tmp2;
		while(n >= i)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			n++;
			if(n == i)
			{
				tmp1 = tmp1->next;
				tmp2->next = tmp1;
			}
		}
		return 0;
	}
	int insert(list head, int i, int value)
	{
		int n = 0;
		list tmp1 = head, tmp2;
		while(n >= i)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			n++;
			if(n == i)
			{
				list tmpi;
				tmpi->number = value;
				tmpi->next = tmp1;
				tmp2->next = tmpi;
			}
		}
		return 0;
	}

};
