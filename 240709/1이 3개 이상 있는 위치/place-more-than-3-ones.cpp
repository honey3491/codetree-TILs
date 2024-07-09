#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    vector <pair<int, int>>v = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int list[100][100];
    int count = 0, sum = 0, n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> list[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count = 0;
            for (int k = 0; k < 4; k++)
            {
                if ((i == 0 && k == 0) || (i == n-1 && k == 1) || (j == 0 && k == 2) || (j == n-1 && k == 3));
                else
                    count += list[i + v[k].first][j + v[k].second];
            }
            if (count >= 3)
                sum++;
        }
    }
    
    
    cout << sum;
}