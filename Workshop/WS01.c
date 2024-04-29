#include <stdio.h>
void determine_grade(int A)
{
    if(A <= 100 && A >= 90) printf("Score %d grade : A\n",A);
    else if(A <= 89  && A >= 80) printf("Score %d grade : B\n",A);
    else if(A <= 79  && A >= 70) printf("Score %d grade : C\n",A);
    else if(A <= 69  && A >= 60) printf("Score %d grade : D\n",A);
    else printf("Score %d grade : F\n",A);
}
float calc_average(int sum)
{
    float avg;
    avg = (float)sum/5;
    printf("The average is: %.1f",avg);
}
int main()
{
        int i, score[5],x;
        for (i=0;i<5;i++)
        {
        printf("Enter test score: ");
        scanf("%d",&score[i]);
        determine_grade(score[i]);
        x = x+score[i];
        }
        calc_average(x);
}
