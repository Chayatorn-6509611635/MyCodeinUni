#include <stdio.h>
#include <math.h>

float average (int A[], int size);
float stdev (int A[], int size, float mean);int max(int A[], int size);
int min(int A[], int size);
void display(int A[], int size);

int main()
{
    int i;
    int num[10];
    printf("Enter the integers of the array: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    display(num, 10);
    return 0;
}

float average (int A[], int size)
{
    int sum = 0;
    float AVG;
    for(int i = 0; i < size; i++)
        sum += A[i];
    AVG = (float)sum / size;
    return AVG;
}

float stdev (int A[], int size, float mean)
{
    float sum1 = 0, SD;
    for(int i = 0; i < size; i++)
        sum1 += pow(A[i] - mean, 2);
    SD = sqrt(sum1/(size-1));
    return SD;
}

int max(int A[], int size)
{
    int MAX = A[0];
    for(int i = 0; i < size; i++)
        MAX = MAX < A[i] ? A[i] : MAX;
    return MAX;
}

int min(int A[], int size)
{
    int MIN = A[0];
    for(int i = 0; i < size; i++)
        MIN = MIN > A[i] ? A[i] : MIN;
    return MIN;
}

void display(int A[], int size)
{
    float mean, sd;
    int MAX, MIN;
    printf("The elements of an array are: ");
    for(int i = 0; i < size; i++)
        printf("%d ", A[i]);
        printf("\n");

    mean = average(A, 10);
    sd = stdev(A, 10, mean);
    MAX = max(A, 10);
    MIN = min(A, 10);

    printf("The average is: %.1f\n", mean);
    printf("The Sample standard deviation is %.2f\n", sd);
    printf("The max number is %d\n",MAX);
    printf("The min number is %d\n", MIN);

    return 0;
}
