#include<stdio.h>
#include<string.h>

/*Longest common sequence*/

void PRINT_LCS(char b[][20],char x[],int i,int j){
	if(i==0 || j==0)
		return;
	if(b[i][j]=='u'){				/*Jesli w tablicy b jest u to drukuje litere na ukos*/
		PRINT_LCS(b,x,i-1,j-1);
		printf("%c",x[i-1]);
	}else if(b[i][j]=='g')			/*Jesli w tablicy b jest u to drukuje litere gorna*/
		PRINT_LCS(b,x,i-1,j);
	else
		PRINT_LCS(b,x,i,j-1);		/*Jesli jest inaczej (tzn. jest l) to drukuje litere lewa*/
}  


void LCS_LENGTH(char x[],char y[]){

int m,n,i,j,c[20][20];
char b[20][20];
m=strlen(x);			/*Dlugosc x*/
n=strlen(y);    		/*Dlugosc y*/
for(i=0;i<=m;i++)		
	c[i][0]=0;			/*Wstawiamy zera do pierwszej kolumny*/
for(i=0;i<=n;i++)
	c[0][i]=0;			/*Wstawiamy zera do pierwszego wiersza*/
for(i=1;i<=m;i++)
	for(j=1;j<=n;j++){
		if(x[i]==y[j])  /*sprawdzamy czy litery na tych samych indeksach sa takie same*/
		{
				c[i][j]=c[i-1][j-1]+1; 
				b[i][j]='u';           /*jesli tak to wstawiamy u myslac o indeksie literze na ukos*/
		}
		else if(c[i-1][j]>=c[i][j-1])	/*jesli nie to sprawdzamy który indeks jest większy*/
		{
			c[i][j]=c[i-1][j];			/*Jesli gorny to wstawiamy g*/
			b[i][j]='g';         
		}
		else{
			c[i][j]=c[i][j-1];
			b[i][j]='l';         		/*jesli nie to wstawiamy lewy*/
		}

	}          
PRINT_LCS(b,x,m,n);      				/*wywolujemy funkcje print*/
}   

int main(){



  return 0;
}
