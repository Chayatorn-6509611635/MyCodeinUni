#include<stdio.h>

int main(){
    int s1, s2, s3;
    int check = 0;
    scanf("%d %d %d", &s1, &s2, &s3);

    if((s1+s2 < s3)||(s2+s3 < s1)||(s3+s1 <s2)) {printf("0"); check = 1;} //if sum of 2 side less than another side, print 0.
    else { //if it's not 0 then do inside this
        if(s1 == s2 && s2 == s3) {printf("1");} //if s1 equals to s2 and s2 equals to s3, then s3 eqauls to s1 and if all side are equals, print 1
        else if(s1 == s2 || s2 == s3 || s3 == s1) {printf("2");} //if s1 equals to s2, or s2 equals to s3, or s3 equals to s1, if some of this condition is true, print 2
        else printf("3"); //if it's not 1 and 2, then print 3
    }
    printf("\n");
    if(check){printf("0");}
    else if(s1 >= s2 && s1 >= s3){printf("%d", s1);}
    else if(s2 >= s1 && s2 >= s3){printf("%d", s2);}
    else if(s1 >= s2 && s1 >= s3){printf("%d", s3);}
    printf("\n");
    return 0;
}