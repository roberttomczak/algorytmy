#include <stdio.h>
#include <stdlib.h>


void makeset();
void graph(int);
void kruskal();
struct node *findset(struct node *);
void union1(struct node *,struct node *);

int j=0;
struct node{
	int dane,ranga;
	struct node *next,*parent;
};

struct edge{
	int dlugosc;
	struct node *zrodlo,*cel;
};

struct node *head[10];
struct edge *e[40];

int main()
{
	int n,i;
	printf("\nPodaj liczbe wierzcholkow w grafie : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		makeset(i);
	}
	graph(n);
	kruskal();
printf("\n");
return 0;
}


void makeset(int a)
{
	struct node *x;
	x=(struct node*)malloc(sizeof(struct node));
	x->dane=a;
	x->parent=x;
	x->ranga=0;
	x->next=NULL;
	head[a]=x;
}

void graph(int n){
	int i,k,l,len;
	int dest;
	for(i=1;i<=n;i++)
	{
		printf("\nDla wierzcholka %d podaj liczbe krawedzi ",i);
		scanf("%d",&l);
		for(k=1;k<=l;k++)
		{
		printf("Podaj drugi wierzcholek %d-ej krawedzi dla wierzcholka %d ",k,i);
		scanf("%d",&dest);
		j++;
		e[j]=(struct edge*)malloc(sizeof(struct edge));
		e[j]->zrodlo=head[i];
		e[j]->cel=head[dest];
		printf("Podaj dlugosc krawedzi : ");
		scanf("%d",&len);
		e[j]->dlugosc=len;
		}
	}
}


void kruskal()	
{
	int i,k,p;
	struct edge *temp;
	i=1;
	while(i<j)
	{		
		p=i;
		k=i+1;
		while(k<=j)
		{
			if(e[p]->dlugosc>e[k]->dlugosc)
			{
				p=k;
			}
			k++;
		}
		if(p!=i)
		{
		temp=e[p];
		e[p]=e[i];
		e[i]=temp;
		}
		i++;
	}
	printf("\nMaksymalne drzewo rozpinajace uwzglednia krawedzie :\n");
	for(i=1;i<=j;i++)
	{
		if(findset(e[i]->zrodlo)!=findset(e[i]->cel))	
		{							
		union1((findset(e[i]->zrodlo)),(findset(e[i]->cel)));	
		printf("\n%d->%d",e[i]->zrodlo->dane,e[i]->cel->dane);	
		}
	}
}

struct node *findset(struct node *a){
	if(a!=a->parent)
	{
		a->parent=findset(a->parent);
	}
	return a->parent;
}

void union1(struct node *x,struct node *y){
	if(x->ranga>y->ranga)
		y->parent=x;
	else
		x->parent=y;
	if(x->ranga==y->ranga)
	y->ranga=y->ranga+1;
}