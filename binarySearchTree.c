#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node node;

node* insert(node* tree, int x)
{
	if (tree == NULL) {
		node* temp = (node*) malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = x;
		return temp;
	}

	if (tree->data < x) {
		tree->right = insert(tree->right, x);
		return tree;
	}
	tree->left = insert(tree->left, x);
	return tree;
}

void preOrder(node* tree)
{
	if (tree == NULL)
		return;
    preOrder(tree->left);
    printf("%d ", tree->data);
    preOrder(tree->right);
}

int main()
{
	node* tree = NULL;
	for(int i = 0; i < 1001; i++)
		tree = insert(tree, i);
	preOrder(tree);
	printf("\n");
}
