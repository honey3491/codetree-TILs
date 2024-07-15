#include <iostream>
#include <cmath>
using namespace std;

int N, K;

void print_num(int a)
{
    if (a == pow(K, N))
        exit(0);
    int tmp = a, arr[8] = { 0, };
    for (int i = N - 1; i >= 0; i--)
    {
        arr[N-i-1] = tmp / int(pow(K, i)) + 1;
        tmp = tmp % int(pow(K, i));
    }
    if (K >= 3)
    {
        for (int i = 2; i < N; i++)
        {
            if (arr[i] == arr[i - 1] && arr[i] == arr[i - 2])
            {
                print_num(a + 1);
                exit(0);
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    print_num(a + 1);
}
int main() {

    cin >> K >> N;
    print_num(0);

    return 0;
}