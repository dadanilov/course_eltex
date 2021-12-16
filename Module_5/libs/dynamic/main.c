#include <stdio.h>

// описываем функцию f1() и f2() как внешнюю
extern int f1();
extern int f2();

int main()
{
	int n1, n2;
	n1 = f1();
	n2 = f2();
	printf("f1() = %d\n", n1);
	printf("f2() = %d\n", n2);
	return 0;
}
