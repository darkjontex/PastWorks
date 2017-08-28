#include <stdio.h>
int maior, menor; //globais

void calculaMaior(int m, int n)
{
	if(m>n)
	{
		maior=m;
		menor=n;
	}
	else
	{
		maior=n;
		menor=m;
	}
	return;
}


int main()
{
    int cont1, cont2, m, n, t; //locais
	scanf("%d %d %d", &m, &n, &t);
	calculaMaior(m,n);
	for(cont2=0;;cont2++)
		if((cont2*maior)%menor==t%menor)
		{
			cont1=(t-(cont2*maior))/menor;
			printf("%d %d %d", cont1, cont2, cont1+cont2);
			break;
		}
	return 0;
}
