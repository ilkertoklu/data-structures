#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node node;

node* root = NULL;
node* last = NULL;

void enque(int x)
{
	if (root == NULL) {
		root = (node*) malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
		last = root;
		return;
	}
	last->next = (node*) malloc(sizeof(node));
	last->next->data = x;
	last = last->next;
	last->next = NULL;
}

int deque()
{
	if (root != NULL) {
		node* temp = root;
		int deqValue = root->data;
		root = root->next;
		free(temp);
		return deqValue;
	}
}

int main()
{
	enque(10);
	enque(20);
	enque(30);

	printf("%d\n", deque());
	printf("%d\n", deque());
	printf("%d\n", deque());
}
