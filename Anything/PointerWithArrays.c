#include <stdio.h>

int main()
{
    char x[10] = {'L','i', 's', 'a'};     // "Lisa" �繢����Ū�Դ string ��Сͺ仴��� char 5 ��� ��� 'L''i''s''a'
    char *xPtr = NULL;
    xPtr = x; // *�������� & ���� Array �ѹ���º����͹�Ѻ pointer �������� (���� Array ���� pointer �������ѧ�� Array ����ͧ)

    while(*xPtr != '\0')
    {
       printf("%c", *xPtr);
       xPtr++;          //����͹ pointer 价�� "xPtr+1" (xPtr = xPtr+1)
    }

    printf("\n");
    printf("%p %p %p %p\n", xPtr, (xPtr+1), (xPtr+2), (xPtr+3));
    printf("%s",NULL);

    int y[4];
    int *yPtr = y;

    return 0;
}
