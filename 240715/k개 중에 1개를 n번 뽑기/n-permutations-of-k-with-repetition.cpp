#include <iostream>
#include <cmath>
using namespace std;

int N, K;

void print_num(int a)
{
    int tmp = a;
    for (int i = N - 1; i >= 0; i--)
    {
        cout << tmp / int(pow(K, i)) + 1 << ' ';
        tmp = tmp % int(pow(K, i));
    }
    cout << '\n';
    if (a == pow(K, N)-1);
    else
        print_num(a + 1);
}
int main() {

    cin >> K >> N;
    print_num(0);
    return 0;
}