#include <iostream>
#include <queue>
using namespace std;

#define not_visited -1

bool answer = false;
short n, m, grid[100][100] = { 0, }, visited[100][100] = { 0, }, counting = 0;
queue <pair<short, short>>q;

bool cango(int r, int c )
{
	if (!grid[r][c] || visited[r][c])
	{
		return false;
	}
	if (r < 0 || r >= n || c < 0 || c >= m)
		return false;
	return true;
}

void bfs(int r, int c)
{

	//cout << r << c << ' ' << counting << endl;
	int dr[4] = {0, 1, -1, 0};
	int dc[4] = { 1, 0, 0, -1 };

	for (int i = 0; i < 4; i++)
	{
		int new_r = r + dr[i];
		int new_c = c + dc[i];
		if (cango(new_r, new_c))
		{
			visited[new_r][new_c] = visited[r][c] + 1;
			q.push({ new_r, new_c });
		}
	}
}

void finding_way()
{
	while (!q.empty())
	{
		short r = q.front().first, c = q.front().second;
		if (r == n - 1 && c == m - 1)
		{
			answer = true;
			return;
		}
		q.pop();
		bfs(r, c);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
	q.push({ 0, 0 });
	finding_way();

	if (answer)
		cout << visited[n-1][m-1];
	else
		cout << "-1";
}