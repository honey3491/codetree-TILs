#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
short grid[100][100] = { 0, }, visited[100][100] = { 0, };
vector <int> v;

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
    if (!InRange(x, y))
        return false;
    if (visited[y][x] || grid[y][x] == 0)
        return false;
    return true;
}

int counting;

void DFS(int x, int y)
{
    counting++;
    visited[y][x] = 1;

    int dx[4] = { 1, 0, - 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (CanGo(new_x, new_y))
        {
            DFS(new_x, new_y);
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[j][i] && grid[j][i])
            {
                counting = 0;
                DFS(i, j);
                v.push_back(counting);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}