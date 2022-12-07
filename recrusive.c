#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int i)
{
	if(i > 0) {
		foo(i - 1);
		printf("%d\n", i);
  }
}

int main()
{
	foo(3);
}
