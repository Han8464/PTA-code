#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
typedef struct Student
{
	int id;
	int c, m, e, a;
	int rank_c, rank_m, rank_e, rank_a;
}Student;
Student students[5000];

int com_c(Student student1, Student student2)
{
	return student1.c > student2.c;
}
int com_m(Student student1, Student student2)
{
	return student1.m > student2.m;
}
int com_e(Student student1, Student student2)
{
	return student1.e > student2.e;
}
int com_a(Student student1, Student student2)
{
	return student1.a > student2.a;
}

int min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int n, m, s_id;
	scanf("%d%d", &n, &m);
	map<int, Student> id_map;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &students[i].id, &students[i].c, &students[i].m, &students[i].e);
		students[i].a = (students[i].c + students[i].e + students[i].m)/3;
	}
	sort(students, students + n, com_c);
	for(int i = 0; i < n; i++)
	{  
		if(i == 0)
		{
			students[i].rank_c = i + 1;
		}else if(students[i].c == students[i - 1].c)
		{
			students[i].rank_c = students[i - 1].rank_c;
		}else
		{
			students[i].rank_c = i + 1; 
		}
	}
	sort(students, students + n, com_m);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			students[i].rank_m = i + 1;
		}else if(students[i].m == students[i - 1].m)
		{
			students[i].rank_m = students[i - 1].rank_m;
		}else
		{
			students[i].rank_m = i + 1; 
		}
	}
	sort(students, students + n, com_e);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			students[i].rank_e = i + 1;
		}else if(students[i].e == students[i - 1].e)
		{
			students[i].rank_e = students[i - 1].rank_e;
		}else
		{
			students[i].rank_e = i + 1; 
		}		
	}
	sort(students, students + n, com_a);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			students[i].rank_a = i + 1;
		}else if(students[i].a == students[i - 1].a)
		{
			students[i].rank_a = students[i - 1].rank_a;
		}else
		{
			students[i].rank_a = i + 1; 
		}
		id_map[students[i].id] = students[i];
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &s_id);
		int grade;
		char type;
		if(id_map.find(s_id) == id_map.end())
		{
			printf("N/A\n");
			return 0;
		}

		int min_rank = min(id_map[s_id].rank_a, min(id_map[s_id].rank_c, min(id_map[s_id].rank_m, id_map[s_id].rank_e)));

		if (min_rank == id_map[s_id].rank_a)
		{
			type = 'A';
		} 
		else if (min_rank == id_map[s_id].rank_c)
		{
			type = 'C';
		}
		else if (min_rank == id_map[s_id].rank_m)
		{
			type = 'M';
		}
		else if (min_rank == id_map[s_id].rank_e)
		{
			type = 'E';
		}

		printf("%d %c\n", min_rank, type);
	}
	return 0;
}
