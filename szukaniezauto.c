#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char alfabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

const int min ( const int a, const int b ) {
	if(a<=b)
		return a;
	else
		return b;
}

void pokaz(char T[], char P[],int delta[][100], int x, int m){
	int i;
	printf("\ni:       ");
	for(i=0;i<strlen(T);i++){
		printf("%d ", i);
	}
	printf("\nTekst:   ");
	for(i=0;i<strlen(T);i++){
		printf("%c ", T[i]);
	}
	printf("\nWzorzec:   ");
	for(i=0;i<x;i++){
		printf(" ");
	}
	for(i=1;i<=m;i++){
		printf("%c ",P[i]);
	}
	printf("\n");
	return;
}

int cmp(int symbol, int q, int delta[][100]){
	int i;
	for(i=1;i<strlen(alfabet);i++){
		if(delta[i][0]==symbol)
			return delta[i][q+1];
	}
	return 0;
}

void matcher(char T[], char P[],int delta[][100], int m){
	int n=strlen(T),i,q=0;
	for(i=0;i<n;i++){
		q=cmp(T[i],q,delta);
		if(q==m){
			printf("\nWzorzec wystepuje z przesunieciem rownym %d\n", i-m+1);
			pokaz(T,P,delta,i-m+1, m);
			return;
		}
	}
}

int suff(char P[], int k, int q, char symbol){
	int i,j=0;
	if(P[k]==symbol){
		for(i=k-1;i>0;i--){
			if(P[i]!=P[q-j])
				return 0;
			j++;
		}
		return 1;
	}
	return 0;
}

void tabela(int delta[][100],int m){
	int i,j;
	printf("q");
	for(i=0;i<=strlen(alfabet);i++){
		if(delta[i][0]!=0){
			printf("  %c", delta[i][0]);
		}
	}
	printf("\n");
	for(i=0;i<m+1;i++){
		printf("%d", delta[0][i+1]);
		for(j=1;j<=strlen(alfabet);j++){
			if(delta[j][0]!=0)
				printf("  %d", delta[j][i+1]);
		}
		printf("\n");
	}
}

void buduj(char P[], int delta[][100]){
	int m=strlen(P+(sizeof(char))), q, k, i;
	char symbol;
	for(q=0;q<m+1;q++){
		for(i=0;i<strlen(alfabet);i++){
			symbol=alfabet[i];
			k=min(m+1,q+2);
			while(suff(P,k,q,symbol)!=1){
				k=k-1;
				if(k<1)
					break;
			}
			if(k>0){
				delta[i+1][0]=symbol;
				delta[0][q+1]=q;
				delta[i+1][q+1]=k;
			}
		}

	}
	tabela(delta, m);
}

int main(){
	char T[100], P[127];
	int delta[27][100],i,j;
	for(i=0;i<100;i++){
		for(j=0;j<=strlen(alfabet);j++)
			delta[j][i]=0;
	}
	for(i=0;i<100;i++){
		P[i]=0;
	}
	scanf("%s", T);
	scanf("%s", P+sizeof (char));
	buduj(P, delta);
	matcher(T,P,delta,strlen(P+sizeof (char)));

	return 0;
}
