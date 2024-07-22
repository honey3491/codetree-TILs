#include <iostream>
using namespace std;

bool result = false;
int n, m, answer = 0;
short grid[1001][1001] = { 0, }, visited[1001] = { 0, };

void DFS(int a)
{
    for (int i = 2; i <= n; i++)
    {
        if (grid[a][i] && !visited[i])
        {
            visited[i] = 1;
            answer++;
            DFS(i);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
        grid[b][a] = 1;
    }

    visited[1] = 1;
    DFS(1);

    cout << answer;
    return 0;
}