//Convert Decimal number

#include<stdio.h>
#define BIT 16

int main()
{
    int num;
    int Bi[BIT] = {0};
    scanf("%d", &num);
    printf("%o\n", num);           //octal number (ฐาน 8)
    printf("%x\n", num);          //hexadecimal  (ฐาน 16)
    for(int i=(BIT-1); i>=0; i--)
    {
        Bi[i] = (num%2 == 0) ? 0 : 1;
        num /= 2;
    }
    for(int i=0; i<BIT; i++)
    printf("%d", Bi[i]);
    return 0;
}
