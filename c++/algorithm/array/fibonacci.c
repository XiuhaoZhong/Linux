#include <stdio.h>


int fibonacci(int n) {
	if (n < 0)
		return 0;

	if (n == 1 || n == 2)
		return 1;

	int i, c;
	int a = 1;
	int b = 1;
	for (i = 3; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int main() {
	int n;
	printf("The n value: : ");
	scanf("%d", &n);
	int res = fibonacci(n);
	printf("The result is: %d\n", res);
	
	return 0;
}
