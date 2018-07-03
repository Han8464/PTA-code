#include <cstdio>
#include <cstdlib>
int main(){
	double bet[3][3];
	char sig[3] = {'W','T','L'};
	int big[3] = {0,0,0};
	double profit = 1.000;
	for(int i = 0; i < 3;i ++)
	{
		for (int j = 0; j < 3;j ++)
		{
			scanf("%lf",&bet[i][j]);
			if ((j != 0) && (bet[i][j] > bet[i][j - 1]))
			{
				big[i] = j;
			}
		}
		profit = profit * bet[i][big[i]];
	}
	profit = (profit * 0.65 - 1) * 2;
	printf ("%c %c %c ",sig[big[0]],sig[big[1]],sig[big[2]]);
	printf("%.2f",profit);
	system("pause");
	return 0;
}