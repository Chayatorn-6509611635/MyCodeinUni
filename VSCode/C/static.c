#include<stdio.h>

void printVal(float value, int times){
    static int count = 1;
    printf("value = %f count = %d\n",value, count);
    count++;
    times--;
    if(times > 0){
        printVal(value, times);
    }
}

int main(int argc, char* argv){
    printVal(350, 3);
    return 0;
}