#include<stdio.h>

int main(){
    int grade;
    scanf("%d", &grade);
    if(grade >= 90 && grade <= 100) printf("A");
    else if(grade >= 85) printf("B+");
    else if(grade >= 80) printf("B");
    else if(grade >= 75) printf("C+");
    else if(grade >= 70) printf("C");
    else if(grade >= 65) printf("D+");
    else if(grade >= 60) printf("D");
    else printf("See ya next term, Bro. You so Fucking noob. INAHEE");
    return 0;
}
