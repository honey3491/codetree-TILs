#include <iostream>
#include <stack>

using namespace std;

int N, M, K, grid[50][50] = { 0, }, visited[50][50];
stack<pair<int, int>> s;

int max_safe_areas = 0, best_K = 0;

bool InRange(int y, int x)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

bool CanGo(int y, int x) {
	if (!InRange(x, y)) {
		return false;
	}
	if (visited[y][x] || grid[y][x] <= K)
		return false;
	return true;

}

void dfs(int y, int x)
{
	short direction[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + direction[i][0], dy = y + direction[i][1];
		if (CanGo(dy, dx))
		{
			//cout << dx << dy<< endl;
			visited[dy][dx] = 1;
			dfs(dy, dx);
		}
	}
	return;
}

void reset_visited()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			//cout << visited[j][i];
			visited[j][i] = 0;
		}
		//cout << endl;
	}
}

void find_max_safe_area()
{
	for (K = 1; K < 101; K++)
	{
		reset_visited();
		int safe_areas = 0;
		//cout << K << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (grid[j][i] > K && !visited[j][i])
				{
					dfs(j, i);
					safe_areas++;
				}
			}
		}

		if (safe_areas > max_safe_areas)
		{
			max_safe_areas = safe_areas;
			best_K = K;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> grid[j][i];
	}

	find_max_safe_area();
	cout << best_K << ' ' << max_safe_areas;
}