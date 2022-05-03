#include<stdio.h>
#include<stdlib.h>
struct NODE{
	int data;
	struct NODE *next;
};

void make_five_nodes(struct NODE **node){
	for(int k=0;k<5;k++){
		*node = (struct NODE*)malloc(sizeof(struct NODE));
		(*node)->data = k;
		printf("%x\n",&(*node)->next);
		node = &(*node)->next;
	}
	*node = NULL;
}

void print_data(struct NODE *node){
	while(node != NULL){
		printf("address:%x data:%d\n",node,node->data);
		node = node->next;
	}
}

void func(struct NODE *node){
	struct NODE *t;
	for(t = node; t->next != NULL; t = t->next){}
	t->next = node;
}

int main(void){
	struct NODE *node;
	make_five_nodes(&node);
	print_data(node);
}