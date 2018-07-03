#include <cstdio>
#include <cstdlib>
char Mars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
char RGB[6];
void change(int digit,int a, int b)
{
	int tmp = digit/13;
	digit = digit - tmp * 13;
	RGB[a] = Mars[tmp];
	RGB[b] = Mars[digit];
	printf("%c%c",RGB[a], RGB[b]);
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("#");
	change(a, 0, 1);
	change(b, 2, 3);
	change(c, 4, 5);
	system("pause");
	return 0;
}