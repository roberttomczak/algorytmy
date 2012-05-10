#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define d 256 


ulong getTimeOfDay() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000000+tv.tv_usec;
}

/*Naiwne szukanie*/

void naiwne(char T[], char P[]){
int i, j, m, n;
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
			printf("Indeks nr %d\n", i);
		i++;
	}

}



void rksearch(char T[], char P[], int q)
{
    int m = strlen(P);
    int n = strlen(T);
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;
 
    for (i = 0; i < m-1; i++)
        h = (h*d)%q;
 
    for (i = 0; i < m; i++)
    {
        p = (d*p + P[i])%q;
        t = (d*t + T[i])%q;
    }
 
    for (i = 0; i <= n - m; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < n; j++)
            {
                if (T[i+j] != P[j])
                    break;
            }
            if (j == m)  
            {
                printf("Wzprzec znaleziony na indeksie %d \n", i);
            }
        }
 
        if ( i < n-m )
        {
            t = (d*(t - T[i]*h) + T[i+m])%q;
            if(t < 0)
              t = (t + q);
        }
    }


}

int main()
{
    
    
    ulong startPomiaru, stopPomiaru;



    char T[1000];
    char P[20];
    int q = 101;  
    gets(T);
    gets(P);
    startPomiaru = getTimeOfDay();
    rksearch(T, P, q);
    stopPomiaru = getTimeOfDay();
    printf("t=%d\n",(int)((stopPomiaru-startPomiaru)%0x0fffffff));   
    startPomiaru = getTimeOfDay();
    naiwne(T, P);
    stopPomiaru = getTimeOfDay();
    printf("t=%d\n",(int)((stopPomiaru-startPomiaru)%0x0fffffff)); 
    getchar();
    return 0;
}
