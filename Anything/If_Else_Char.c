#include <stdio.h>
int main()
{
    char gen;
    printf("Please enter your gender? < M/F >: ");
    scanf ("%c", &gen);
    if (gen == 'M' || gen == 'm')
    {
        printf("Hello,Sir!");
    }
    else if (gen == 'F' || gen == 'f')
    {
        printf("Hello,Ma'am!");
    }
    else
        printf("\"Invalid\"");
    return 0;
}
