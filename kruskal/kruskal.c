#include <stdio.h>
#include <stdlib.h>


void makeset();
void graph(int);
void kruskal();
struct node *findset(struct node *);
void union1(struct node *,struct node *);


int j=0;

/*Deklaracja struktuktury wezla*/
struct node{
  int dane,ranga;
	struct node *next,*parent;
};
/*Deklaracja struktury krawedzi*/
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

void makeset(int a)/*Funkcja tworzaca zbiory jednoelementowe*/
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
	for(i=1;i<=n;i++)/*Ilosc iteracji petli zgodnie z iloscia wierzcholkow */
	{
		printf("\nDla wierzcholka %d podaj liczbe krawedzi ",i);
		scanf("%d",&l);/*Pobranie ilosci krawedzi wychodzacych z podanej krawedzi*/
		for(k=1;k<=l;k++)
		{
		printf("Podaj drugi wierzcholek %d-ej krawedzi dla wierzcholka %d ",k,i);
		scanf("%d",&dest);/*podanie drugiego wierzcholka skladajacego polaczonego krawedzia z podanym */
		j++;
		e[j]=(struct edge*)malloc(sizeof(struct edge));
		e[j]->zrodlo=head[i];/*ustalenie poczatku krawedzi*/
		e[j]->cel=head[dest];/*ustalenie konca krawedzi*/
		printf("Podaj dlugosc krawedzi : ");
		scanf("%d",&len);
		e[j]->dlugosc=len;/*dlugosc, waga krawedzi*/
		}
	}
}


void kruskal()	
{
	int i,k,p;
	struct edge *temp;
	i=1;
	while(i<j)/*sortowanie krawedzi pod wzgledem wag przy pomocy sortowania przez wstawianie*/
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
	printf("\n\ngraph G{");/*Rozpoczynamy rysowanie grafu*/
	for(i=1;i<=j;i++)
	{
	  if(findset(e[i]->zrodlo)!=findset(e[i]->cel))/*Sprawdzanie reprezentantow poczatku i konca krawedzi jesli wartosci sa rozne to laczymy krawedzia wieszcholki*/	
		{							
		  union1((findset(e[i]->zrodlo)),(findset(e[i]->cel)));/*wyznaczanie i rysowanie wieszcholkow skladajace sie na drzewo spinajace*/
		printf("\n%i[style=filled, fillcolor=red]",e[i]->zrodlo->dane);
		printf("  %i[style=filled, fillcolor=red]",e[i]->cel->dane);
		printf("\n%d--%d",e[i]->zrodlo->dane,e[i]->cel->dane);		
		}
	}
	printf("\n}");
}


struct node *findset(struct node *a){/*funkcja znajdujaca reprezentanta*/
	if(a!=a->parent)
	{
		a->parent=findset(a->parent);
	}
		return a->parent;
}

void union1(struct node *x,struct node *y){/*funkcja laczaca dwa wierzcholki*/
	if(x->ranga>y->ranga)
		y->parent=x;
	else
		x->parent=y;
	if(x->ranga==y->ranga)
	y->ranga=y->ranga+1;
}
