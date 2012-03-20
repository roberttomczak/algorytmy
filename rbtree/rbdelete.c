#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum { BLACK, RED } nodeColor;

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    nodeColor color;
} Node;

Node *root;
Node *aktualny;
Node *nil;



void left_rotate(Node *x) {
	Node *y;
	y=x->right;
	x->right = y->left;
	if(y->left!=nil)
		y->left->parent=x;
	if(y!=nil)
		y->parent=x->parent;
	if(x->parent == nil)
		root=y;
	else{
		if(x==x->parent->left)
			x->parent->left=y;
		else
			x->parent->right=y;
	}
	y->left=x;
	if(x!=nil) x->parent=y;
}

void right_rotate(Node *x) {
	Node *y;
	y=x->left;
	x->left = y->right;
	if(y->right!=nil)
		y->right->parent=x;
	if(y!=nil)
		y->parent=x->parent;
	if(x->parent == nil)
		root=y;
	else{
		if(x==x->parent->right)
			x->parent->right=y;
		else
			x->parent->left=y;
	}
	y->right=x;
	if(x!=nil) x->parent=y;
}

void tree_insert(int z) {
	Node *new=(Node*)malloc(sizeof(Node));
	Node *y;
	Node *x;
	new->key=z;
	new->left=nil;
	new->right=nil;
	new->color=RED;
	y=nil;
	x=root;
	while(x!=nil) {
  		y=x;
  		if(new->key < x->key)
   			x=x->left;
		else
   			x=x->right;
	}
	new->parent=y;
	if (y==nil)
		root=new;
	else
		if (new->key < y->key)
			y->left=new;
		else
			y->right=new;
aktualny=new;
}


void rb_insert(int z) {
	Node *x;
	Node *y;
	tree_insert(z);
	x=aktualny;
	x->color=RED;
	while(x!=root && x->parent->color==RED) {
		if(x->parent==x->parent->parent->left) {
			y=x->parent->parent->right;
			if(y->color==RED) {
				x->parent->color=BLACK;	/*Przypadek 1*/
				y->color=BLACK;
				x->parent->parent->color=RED;
				x=x->parent->parent;
			} else {
				if(x==x->parent->right) {
					x=x->parent;		/*Przypadek 2*/
					left_rotate(x);
				}
					x->parent->color=BLACK;	/*Przypadek 3*/
					x->parent->parent->color=RED;
					right_rotate(x->parent->parent);
			}
		} else {
			y=x->parent->parent->left;
			if(y->color==RED) {
				x->parent->color=BLACK;	/*Przypadek 1 v.2*/
				y->color=BLACK;
				x->parent->parent->color=RED
				;
				x=x->parent->parent;
			} else {
				if(x==x->parent->left) {
					x=x->parent;		/*Przypadek 2 v.2*/
					right_rotate(x);
				}
					x->parent->color=BLACK;	/*Przypadek 3 v.3*/
					x->parent->parent->color=RED;
					left_rotate(x->parent->parent);
			}
		}
	}
	root->color=BLACK;
}

void szukaj_synow(Node *w) {
		if(w->color)
			printf("%i[style=filled, fillcolor=red]\n",w->key);
		else
			printf("%i[style=filled, fillcolor=gray]\n",w->key);
		if(w->left != nil) {
			printf("%i->%i;\n",w->key,w->left->key);
			szukaj_synow(w->left);
		}
		if(w->right != nil) {
			printf("%i->%i;\n",w->key,w->right->key);
			szukaj_synow(w->right);
		}
}

void graph() {
	printf("digraph G{\n");
	szukaj_synow(root);
	printf("}\n");
}
