#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_prefix_function(char P[])
{
	int m,i,k,q;
	int *pi;
	m=strlen(P);
	pi = (int*)malloc(sizeof(int)*m);
	pi[1] = 0;
	k=0;
	for (q = 2; i < m; i++) {
		while (k > 0 && P[k+1] != P[q])
			k = pi[k];
		if (P[q] == P[k+1])
			k++;
		pi[q] = k;
	}
	return pi;
}

int kmp(char T[], char P[])
{
	int n,m,i;
	int *pi;
	int q;
	n=strlen(T);
	m=strlen(P);
	pi=compute_prefix_function(P);
	q = 0;
	for (i = 1; i < n; i++) {
		while (q > 0 && P[q+1] != T[i])
			q = pi[q];
		if (T[i] == P[q+1])
			q++;
			/*printf("q:%d m:%d ",q,m);*/
		if (q == m-1) {
			printf("wzorzec na miejscu %d\n",i-m);
			q=pi[q];
		}
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	char T[1000];
	char P[1000];
	gets(T);
	gets(P);
	kmp(T, P);
	return 0;
}
