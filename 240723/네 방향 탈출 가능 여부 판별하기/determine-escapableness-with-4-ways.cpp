#include <iostream>
#include <queue>
using namespace std;

bool result = false;
int n, m;
short grid[100][100] = { 0, }, visited[100][100] = { 0, };
queue<pair<short, short>> q;

bool InRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;

}

bool CanGo(int x, int y) {
    if (!InRange(x, y))
        return false;
    if (visited[x][y] || grid[x][y] == 0)
        return false;
    return true;
}

void Push(int x, int y)
{
    visited[x][y] = true;
    q.push({ x, y });
}
void BFS() {
    int dx[4] = { 1, 0 , -1, 0};
    int dy[4] = { 0, 1 , 0, -1};

    while (!q.empty())
    {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        //cout << x << y << endl;

        if (x == m - 1 && y == n - 1)
        {
            result = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (CanGo(new_x, new_y))
                Push(new_x, new_y);
        }
    }
    cout << result;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    Push(0, 0);
    BFS();
}