#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXLEN 1000
int main() {
    char sen[MAXLEN];
    printf("Enter the sentence: ");
    gets(sen);
    int n = strlen(sen);
    for (int i; i<n; i++){
        if ((int)sen[i] >= 65 && (int)sen[i] <= 65+26){
            printf("%c", tolower(sen[i]));
        }
        else if ((int)sen[i] >= 65+32 && (int)sen[i] <= 65+26+32){
            printf("%c", toupper(sen[i]));
        }
        else printf("%c", sen[i]);
    }
}
