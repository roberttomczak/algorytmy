#include <stdio.h>
#include <stdlib.h>


typedef struct wezel{
    int key;
    struct wezel* parent;
    
} wezel;

wezel *s[50];

wezel* MakeSet(int value){
	wezel *new=(wezel*)malloc(sizeof(wezel));
	new -> key = value;
	new -> parent = new;
	return new;
}


wezel* FindSet(wezel* node){
	
	if(node!=node->parent){
		return FindSet(node->parent);
	}else{
		return node;
	}



}

void Union(wezel* node1,wezel* node2){

node2 -> parent = node1; 

}

void drukuj(wezel* node, wezel* node1){
printf("%i[style=filled, fillcolor=red]\n", node->key);	
printf("%i -> ", node -> key);
printf("%i\n", node1->parent->key);	
}

int main(){

  int i;
  for(i=1;i<=7;i++){
	s[i]=MakeSet(i);
  }
  printf("digraph G{\n");
  Union(s[2],s[5]);
  drukuj(s[5],FindSet(s[5]));
  drukuj(s[1],FindSet(s[1]));
  Union(s[1],s[2]);
  drukuj(s[2],FindSet(s[2]));
  Union(s[3],s[4]);
  drukuj(s[4],FindSet(s[4]));
  Union(s[1],s[3]);
  drukuj(s[3],FindSet(s[3]));
  Union(s[6],s[7]);
  drukuj(s[7],FindSet(s[7]));
  printf("}\n");	


  return 0;
}
