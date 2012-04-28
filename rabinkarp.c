#include<stdio.h>
#include<string.h>

#define d 256 

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
    char T[1000];
    char P[20];
    int q = 101;  
    gets(T);
    gets(P);
    rksearch(T, P, q);
    getchar();
    return 0;
}
