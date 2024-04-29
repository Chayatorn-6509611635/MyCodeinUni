#include <stdio.h>

int main(){
    int size;
    printf("Enter of your square: ");

    scanf("%d", &size);

    printf("Enter your square:\n");
    int arr[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d", &arr[i][j]);
        }
    }

/*
    Vocab:
        declare = ประกาศ
        variables = ตัวแปร
        initialize = กำหนดค่าเริ่มต้น
        assign = กำหนดค่า
*/

    int check = 1; //check for magic square (true(is magic square) = 1, false(is not magic square) = 0)
    int max; //variable for store maximum value of sum
    for(int i = 0; i < size; i++){
        int colsum = 0; //declare and initialize colsum and rowsum variables every beginning of the loop
        int rowsum = 0;
        for(int j = 0; j < size; j++){
            colsum += arr[i][j];
            rowsum += arr[j][i];
        } //loop j finish here!

        if(i == 0){ //if i is 0 set max to colsum
            max = colsum;
        }

        //check each row and column (Because loop i is not finish)
        if(colsum > max){ //if colsum > max, then assign max = colsum
            check = 0;
            max = colsum;
        }
        if(rowsum > max){ //if rolsum > max, then assign max = colsum
            check = 0;
            max = colsum;
        }
        /*
        Test code for each colsum and row sum:
            printf("colsum %d: %d\n", i, colsum);
            printf("rowsum %d: %d\n", i, rowsum);
            printf("max: %d\n", max);
        */
    } //loop i finish here

    int diagsum[2] = {0}; //declare sum of diagnal
    /*
        you can declare and initialize value 2 more ways:
        1.  int diagsum[2];
            diagsum[0] = 0;
            diagsum[1] = 0;

        2.  int diagsum1 = 0;
            int diagsum2 = 0;
        ** if you do the second way, you have to change variable below and cannot use some loop
    */
    
   
    //loop to caluculate sum of diagnal
    for(int j = 0; j < size; j++){
        diagsum[0] += arr[j][j];
        diagsum[1] += arr[j][size-j-1];
    }
    //loop to check each diagnalsum if they are equal.
    //if you use initalize on the second way you cannot use this loop
    for(int i = 0; i < 2; i++){
        if(diagsum[i] > max){
            check = 0;
            max = diagsum[i];
        }
        /*
        Test code for each diagnal:
            printf("diagsum %d: %d\n", i, diagsum[i]);
            printf("m: %d\n", max);
        */
    }

    //output
    //if (check == 0) --> (is not a magic square)
    if(check == 0){
        printf("Your square is not a magic square.\n");
        printf("The maximum sum is %d", max);
    }
    //else --> (is a magic square)
    else{
        printf("Your square is a magic square!!\n");
        printf("The magic constant is %d", max);
    }
    return 0;
}