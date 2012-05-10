#include <stdio.h>
#include <string.h>

/*Naiwne szukanie*/

int main(){

char T[100];
char P[10];
int i, j, m, n;
printf("Podaj tekst\n");
gets(T);
printf("Podaj wzorzec\n");
gets(P);
n=strlen(T);
m=strlen(P);
printf("Indeksy wystapien wzorca w tekscie\n");
i=0;
	while(i<=n-m)
	{
		j=0;
		while((j<m)&&(P[j]==T[i+j])) 
		j++;
		if (j==m) 
			printf("Indeks nr %d\n", i+1);
		i++;
	}
return 0;
}
