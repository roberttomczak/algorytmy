#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct W {
	int key,symbol, bracpoduwage;
	struct W *left, *right;
} wezel;

void wyswietl(wezel* root) {
	if (root!=NULL) {
		if(root->symbol>=0)
			printf("%d [label=\"%d:%d\", shape=rect, style=filled]\n",root->symbol,  root->symbol, root->key);
		else
			printf("W%d [style=filled]\n", root->key);
		if (root->left!=NULL && root->right!=NULL) {

			if (root->left!=NULL && root->left->symbol>=0 && root->symbol<0) {
				printf("W%d->%d [label=0];",root->key, root->left->symbol);
			}
			else
				printf("W%d->W%d [label=0];",root->key, root->left->key);


			if (root->right!=NULL && root->right->symbol>=0) {
				printf("W%d->%d [label=1];",root->key, root->right->symbol);
			}
			else
				printf("W%d->W%d [label=1];",root->key, root->right->key);

			printf("\n");
			if (root->left!=NULL ) {
				wyswietl(root->left);
			}
			if (root->right!=NULL ) {
				wyswietl(root->right);
			}
		}
	}
}

wezel *findmin(wezel *T[], int pom){
	int i,x=2147483647,y;
	for(i=0;i<pom*2-1;i++){
		if(T[i]->key<x &&  T[i]->bracpoduwage == 1){
			x=T[i]->key;
			y=i;
		}
	}
	T[y]->bracpoduwage=0;
	return T[y];
}

void huffman(wezel *T[], int pom){
	int i;
	wezel *z, *x, *y;
	for(i=0;i<pom-1;i++){
		z=malloc(sizeof(wezel));
		x=findmin(T,pom);
		z->left=x;
		y=findmin(T,pom);
		z->right=y;
		z->key=x->key+y->key;
		z->bracpoduwage=1;
		z->symbol=-2;
		T[i+pom]=z;
	}

	printf("digraph G {\n");
	wyswietl(z);
	printf("}\n");
}

int main(int argc, char **argv){
	int A[256],i,pom=0,j=0,dlugosc;
	char x;
	wezel *wypelniacz;
	FILE *fp;
	for(i=0;i<256;i++){
		A[i]=0;
	}
	fp = fopen(argv[1], "rb");
	if( fp == NULL ){
		perror("Blad otwarcia pliku");
		exit(-10);
	}
	fseek (fp, 0, SEEK_END);
	fgetpos (fp, &dlugosc);
	fseek(fp,0,0);
	for(i=0;i<dlugosc;i++){
		fscanf(fp, "%c", &x);
		A[(int)x]++;
	}
	for(i=0;i<256;i++){
		if(A[i]!=0)
			pom++;
	}
	wezel *T[pom*2-1];
	wypelniacz=malloc(sizeof(wezel));
	wypelniacz->symbol=0;
	wypelniacz->key=0;
	wypelniacz->left=NULL;
	wypelniacz->right=NULL;
	wypelniacz->bracpoduwage=0;
	for(i=0;i<pom*2;i++){
		T[i]=wypelniacz;
	}
	for(i=0;i<256;i++){
		if(A[i]!=0){
			wezel *z=malloc(sizeof(wezel));
			z->key=A[i];
			z->symbol=i;
			z->left=NULL;
			z->right=NULL;
			z->bracpoduwage=1;
			T[j]=z;
			j++;
		}
	}
	huffman(T,pom);
	fclose (fp);
	return 0;
}
