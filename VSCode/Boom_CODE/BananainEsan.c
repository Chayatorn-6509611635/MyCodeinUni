#include<stdio.h>
#include<string.h>

int main(){
    char c[100];
    int res[12] = {0};
    int bloom[12][26] = {0};

    scanf("%s", c);

    for(int i = 0; i < strlen(c); i += 2){
        int month;
        if(c[i] > '0' && c[i] <= '9') {month = c[i] - '0' - 1;}
        else if(c[i] >= 'A') {month = c[i] - 'A' + 9;}
        int type = c[i+1] - 'A';

        if(bloom[month][type] == 0){
            bloom[month][type] = 1;
            res[month]++;
        }
    }
    int max = res[0];
    for(int i = 0; i < 12; i++){
        if(res[i] > max){
            max = res[i];
        }
        printf("%d\n", res[i]);
    }
    printf("%d", max);
    return 0;
}