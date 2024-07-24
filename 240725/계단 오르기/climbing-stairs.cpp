#include <iostream>
using namespace std;

int count = 0;

void stairs(int n)
{
    if(n == 0){
        count++;
        return;
    }
    else if(n == 1)
        return;
    else if(n < 0)
        return;
    else
    {   
        stairs(n-2);
        stairs(n-3);
    }
    return;
}
int main() {
    int num;
    cin >> num;
    stairs(num);
    cout << count;
    return 0;
}