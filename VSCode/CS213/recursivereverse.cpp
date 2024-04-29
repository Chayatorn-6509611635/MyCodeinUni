#include <iostream>

using namespace std;

void Reverse()
{
    char ch;
    cin.get(ch);
    if (ch != '\n')
    {
        Reverse();
        cout.put(ch);
    }
}

int main(){
    Reverse();
}