#include <iostream>
using namespace std;

int count = 0;
long long memo[1000] = {0, };

int stairs(int n)
{
    if(n < 0){
        return 0;
    }
    if(memo[n] != 0){
        return memo[n];
    }
    else
        memo[n] = (stairs(n-2) + stairs(n-3)) % 10007;
    return memo[n];
}
int main() {
    int num;
    memo[0] = 1;
    memo[2] = 1;
    memo[3] = 1;
    cin >> num;
    count = stairs(num) % 10007;
    cout << count;
    return 0;
}