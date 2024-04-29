#include<stdio.h>
#define MAXLEN 50 //ถ้าเจอ MAXLEN มันจะเป็นเลข 50
struct StudentRec
{
    char lastname[MAXLEN]; // == char lastname[50]
    float mark;
};
int main()
{
    struct StudentRec studA;
    struct StudentRec studB;

    printf("Enter last name and mark fot student A: ");
    scanf("%s %f",studA.lastname, &(studA.mark));
    printf("Enter last name and mark fot student B: ");
    scanf("%s %f",studB.lastname, &(studB.mark));

    printf("Studen A: %s\t%.2f\n",studA.lastname, studA.mark);
    printf("Studen B: %s\t%.2f\n",studB.lastname, studB.mark);

    return 0;
}
