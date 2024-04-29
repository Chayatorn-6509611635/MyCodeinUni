#include<stdio.h>

int main()
{
    int n = 10;
    int number[n];
    int i, tmp;

    for(i=0; i<n; i++)
    {
        printf(" Enter number %d : ", i+1);
        scanf("%d", &number[i]);
    }

    i = 0;
    while(i<n)
    {
        if(i < n-1 && number[i] > number[i+1])
        {
            tmp = number[i];                  //ถ้าเข้าเงื่อนไข สลับ 2 ตัว
            number[i] = number[i+1];
            number[i+1] = tmp;
            i = 0;                                         //set ให้เริ่มเช็คเงื่อนไขใหม่ ถ้าผ่านก็เพิ่มค่า i ตรง else
        }
        else
            i++;
    }

    printf("\n Ascending order : ");
    for(i=0; i<n; i++)
    {
        printf(" %d", number[i]);
    }

    return 0;
}
