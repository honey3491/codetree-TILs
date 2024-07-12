#include <iostream>
using namespace std;

int main() {
    int n, m, count, result = 0, space[100][100];

    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> space[i][j];
        }
    }

    if (m == 1)
        result = n * 2;
    else
    {
        for (int i = 0; i < n; i++)
        {
            count = 1;
            for (int j = 1; j < n; j++)
            {
                if (space[j][i] == space[j - 1][i]) {
                    count++;
                    if (count >= m) {
                        result++;
                        break;
                    }
                }
                else
                    count = 1;

            }
        }

        for (int i = 0; i < n; i++)
        {
            count = 1;
            for (int j = 1; j < n; j++)
            {
                if (space[i][j] == space[i][j - 1]) {
                    count++;
                    if (count >= m) {
                        result++;
                        break;
                    }
                }
                else
                    count = 1;
            }
        }
    }
    cout << result;
    return 0;
}