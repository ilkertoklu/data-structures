#include <stdio.h>
#include <stdlib.h>

int* array = NULL;
int first = 0;
int last = 0;
int size = 2;

int deque()
{
	if (first == last) {
		printf("Queue is empty");
		return -1;
	}
	return array[first++];
}

void enque(int enq_val)
{
	if (array == NULL) {
		array = (int*) malloc(sizeof(int)*2);
	}
	array[last++] = enq_val; //dizinin last`inci elemanina enq_value`yi koy, last`i bir arttir.
	if (last >= size)
		size *= 2;
		int* array_new = (int*) malloc(sizeof(int)*size);
		for(int i = 1; i < size/2; i++){
			array_new[i] = array[i];
		}
		free(array);
		array = array_new;
}

void shift()
{
	if(first == 0)
		return;
	for (int i = 0; i < size; i++) {
		array[i] = array[i + first];
	}
	last -= first;
	first = 0;
}

int main()
{
	for (int i = 0; i < 20; i++)
		enque(i*10);
	for (int i = 0; i < 10; i++)
		deque(i*10);

	printf("Before shift: %d, %d, %d\n", first, last, size);
	shift();
	printf("After shift: %d, %d, %d\n", first, last, size);
}
