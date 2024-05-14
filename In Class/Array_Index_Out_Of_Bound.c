#include<stdio.h>
int mainx()
{
    int nums[4]= {10,20,30,40}; //num[0]=10 num[1]=20 num[2]=30 num[3]=40
    printf("%d\n", nums[0]);
    printf("%d\n", nums[4]); //Incorrect meaning but correct syntax
}
/*num[4]=Index out of bound
*/
int main()
{
    mainx();
    char myWord[5] = {'L','i','s','a'};
    printf("%s\n",myWord);
    printf("%c",myWord[6]);
}
