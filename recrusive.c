#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int n)
{
	if(n > 0) {
		foo(n - 1);
		printf("%d\n", n);
  }
}

int factorialCheck(int n)
{
	int result = 1;
	for (int i = n; i > 0; i--)
		result = result * i;
	return result;
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

int main()
{
	printf("%d\n", factorialCheck(5));
	printf("%d\n", factorial(5));
}

