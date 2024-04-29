#include <stdio.h>

int main()
{
	int age;
	printf("How old are you? ");
	scanf ("%d", &age);
	if(age>=15)
		printf("Hello!!\n");
	else
		printf("Hello, Kid.\n");
		return 0;
}
