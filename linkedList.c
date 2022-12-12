#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node node;

void dump(node* root)
{
    node* temp = root;
	while(temp != NULL) {
		printf("data: %d\n", temp->data);
		temp = temp->next;
	}
}

node* add(node* root, int x)
{
	if (root == NULL) {
		root = (node*) malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
        return root;
	}

    node* temp = root;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = (node*) malloc(sizeof(node));
	temp = temp->next;
	temp->data = x;
	temp->next = NULL;
    return root;
}

int main()
{
    node* root = NULL;
	for (int i = 1; i <= 10; i++)
		root = add(root, i);
	dump(root);
}
