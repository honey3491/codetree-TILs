#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    int cloth[201][200] = { 0, }, dp[200][201] = {0,};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        for (int j = s; j <= e; j++)
            cloth[i][j] = v;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int max_diff = 0;
            if (cloth[j][i] == 0)
                continue;
            for (int k = 0; k < n; k++)
            {
                if (k == j)
                    continue;
                if (cloth[k][i - 1] == 0)
                    continue;
                max_diff = max(max_diff, dp[i-1][k] + abs(cloth[j][i] - cloth[k][i - 1]));
            }
            dp[i][j] = max_diff;
        }
    }
    cout << *max_element(dp[m], dp[m] + n);
    return 0;
}