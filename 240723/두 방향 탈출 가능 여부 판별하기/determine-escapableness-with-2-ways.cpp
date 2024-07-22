#include <iostream>
using namespace std;

bool result = false;
int n, m;
short grid[100][100] = { 0, }, visited[100][100] = { 0, };

bool InRange(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
        
}

bool CanGo(int x, int y) {
    if (!InRange(x, y))
        return false;
    if (visited[y][x] || grid[y][x] == 0)
        return false;
    return true;

}
void DFS(int x, int y)
{
    if (x == m-1 && y == n-1)
    {
        cout << 1;
        result = true;
        return;
    }

    int dx[2] = { 1, 0 };
    int dy[2] = { 0, 1 };

    for (int i = 0; i < 2; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (CanGo(new_x, new_y))
        {
            visited[new_y][new_x] = 1;
            DFS(new_x, new_y);
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = 1;
    DFS(0, 0);

    
    if (!result)
        cout << 0;
    return 0;
}