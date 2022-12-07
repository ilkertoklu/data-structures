#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node node;

node* add(node* tree, int x)
{
	if(tree == NULL) {
		node* temp = (node*) malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = x;
		return temp;
	}

	if(tree->data < x) {
		tree->right = add(tree->right, x);
		return tree;
	}
	tree->left = add(tree->left, x);
	return tree;
}

void traverse(node* tree)
{
	if(tree == NULL)
		return;
	traverse(tree->left);
	printf("%d\n", tree->data);
	traverse(tree->right);
}

int main()
{
	node* tree = NULL;

	tree = add(tree, 5);
	tree = add(tree, 10);
	tree = add(tree, 15);
	tree = add(tree, 20);
	tree = add(tree, 25);
	traverse(tree);
}
