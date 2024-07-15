#include <iostream>
using namespace std;

int N, K;
void print_num(int k, int n)
{
    cout << k << ' ' << n << '\n';

    if(k == K && n == N);
    else if(n == N)
        print_num(k+1, 1);
    else
        print_num(k, n+1);
        
}
int main() {

    cin >> K >> N;
    print_num(1, 1);
    return 0;
}