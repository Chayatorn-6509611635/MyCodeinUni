#include <stdio.h>

int main()
{
    char x[10] = {'L','i', 's', 'a'};     // "Lisa" เป็นข้อมูลชนิด string ประกอบไปด้วย char 5 ตัว คือ 'L''i''s''a'
    char *xPtr = NULL;
    xPtr = x; // *ที่ไม่ใช้ & เพราะ Array มันเปรียบเสมือนกับ pointer อยู่แล้ว (ชื่อ Array ก็คือ pointer ที่ชี้ไปยังต้น Array นั่นเอง)

    while(*xPtr != '\0')
    {
       printf("%c", *xPtr);
       xPtr++;          //เลื่อน pointer ไปที่ "xPtr+1" (xPtr = xPtr+1)
    }

    printf("\n");
    printf("%p %p %p %p\n", xPtr, (xPtr+1), (xPtr+2), (xPtr+3));
    printf("%s",NULL);

    int y[4];
    int *yPtr = y;

    return 0;
}
