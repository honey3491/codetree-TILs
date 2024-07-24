#include <iostream>
#define max_size 45

using namespace std;

int memo[max_size] = {0, }, num;

int fibbo(int n)
{
    if(memo[n] != 0)
        return memo[n];
    if(n <= 2)
        memo[n] = 1;
    else
        memo[n] = fibbo(n-1) + fibbo(n-2);
    return memo[n];
}

int main() {
    cin >> num;
    cout <<fibbo(num);
    
    return 0;
}