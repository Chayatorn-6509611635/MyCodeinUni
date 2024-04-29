#include<stdio.h>
typedef struct Date{
    int day;
    int month;
    int year;
} day;
day today, tomorrow, yesterday;

int main(){
    scanf("%d %d %d", &today.day, &today.month, &today.year);
    printf("%d/%d/%d", today.day, today.month, today.year);
    tomorrow.day = today.day++;
    yesterday.day = today.day--;
    switch(tomorrow.month){
    case 1 :;
    case 3 :;
    case 5 :;
    case 7 :;
    case 8 :;
    case 10 : if(tomorrow.day > 31) {
    tomorrow.day = tomorrow.day%31;
    tomorrow.month++;
    }
    case 12 : if(tomorrow.month++ >12) {tomorrow.year++;
        tomorrow.month = tomorrow.day%12;
     } break;
    case 2 : if(tomorrow.day > 28) {
        tomorrow.month++;
        tomorrow.day = tomorrow.day%28 break;
    case 4 :;
    case 6 :;
    case 9 :;
    case 11 : if(tomorrow.day > 30) tomorrow.month++; break;
    }
    printf("Tomorrow is %d/%d/%d", tomorrow.day)
}
