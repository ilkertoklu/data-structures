#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node node;
node* top = NULL;
node* root = NULL;

void pop()
{
	if (root == NULL)
		return;
	node* iter = root;
	while (iter->next->next != NULL)
		iter = iter->next;
	iter->next = NULL;
    printf("popped value: %d\n", top->data);
	free(top);
	top = iter;
}

void dump()
{
    node* temp = root;
	while(temp != NULL) {
		printf("data: %d\n", temp->data);
		temp = temp->next;
	}
}

void push(int x)
{
	if (root == NULL) {
		root = (node*) malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
        return;
	}

    node* temp = root;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = (node*) malloc(sizeof(node));
	temp = temp->next;
	temp->data = x;
	temp->next = NULL;
	top = temp;
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	dump(root);
	printf("top of the stack is: %d\n", top->data);
	pop(root);
	dump(root);
	printf("top of the stack is: %d\n", top->data);
}
