#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//Function Overload
void printHelloWorld(); // non-returned & no parameter function
int randomNumber(); // returned function
void printSum(int num1, int num2); // non-returned parameter function
double pow(int b, int n); // returned & parameter function

int main(){
    int num1, num2;
    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;
    printHelloWorld();
    cout << randomNumber() << '\n';
    printSum(num1, num2);
    cout << pow(num1, num2);
    return 0;
}

//non-returned & no parameter function
void printHelloWorld(){
    cout << "HelloWorld!"<< "\n";
}

//returned function
int randomNumber(){
    srand((unsigned)time(NULL));
    int random;
    random = (rand()%10) + 1; //random 1 - 10
    return  random;
}

//non-returned parameter function
void printSum(int num1, int num2){
    cout << num1 + num2 << '\n';
}

//returned & parameter function
double pow(int b, int n){
    double result = b;
    int count = 1;
    while (count < n){
        result *= b;
        count++;
    }
    return result;
}