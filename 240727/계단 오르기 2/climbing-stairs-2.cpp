#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, A[1001], stairs[1001][4] = { -1, };
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    stairs[1][1] = A[1];
    if (n > 1) {
        stairs[2][2] = A[1] + A[2];
        stairs[2][0] = A[2];
    }

    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if (stairs[i - 2][j] != 0) // 두 칸 전진
                stairs[i][j] = max(stairs[i][j], stairs[i - 2][j] + A[i]);
            if (j && stairs[i - 1][j - 1] != 0) // 한 칸 전진
                stairs[i][j] = max(stairs[i][j], stairs[i - 1][j - 1] + A[i]);
        }
        /*for (int j = 0; j <= 3; j++)
            cout << stairs[i][j] << ' ';
        cout << endl;*/
    }

    cout << *max_element(stairs[n], stairs[n]+4);
    return 0;
}