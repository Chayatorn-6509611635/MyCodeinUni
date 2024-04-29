#include <stdio.h>

int main()
{
	float ft,in;
	printf ("How height are you (in feet and inches):");
	scanf ("%f %f",&ft,&in);
	printf ("Your height is %.2f centimeters.",((ft*12)+in)*2.54);
	return 0;

}
