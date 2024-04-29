#include<stdio.h>
int main()
{
    FILE *fptr = fopen("ASCII_Table.txt","w");
    char ch;
    int i;
    for(i=0;i<=127;i++)
    {
        ch = i;
        fprintf(fptr,"The %dth in ASCII table is %c\n", i,ch);
    }
}
