#include <iostream>
#include <algorithm>
using namespace std;

int grid[100][100], N, memo[100][100] = { 0, };

int calc(int r, int c)
{
	if (memo[r][c] != 0)
		return memo[r][c];

	else
	{
		if (r == 0)
		{
			memo[r][c] = grid[r][c] + calc(r, c + 1);
		}
		else if (c == N-1)
		{
			memo[r][c] = grid[r][c] + calc(r - 1, c);
		}
		else
		{
			memo[r][c] = grid[r][c] + min(calc(r, c + 1), calc(r - 1, c));
		}
	}
	return memo[r][c];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	}

	memo[0][N - 1] = grid[0][N - 1];

	calc(N - 1, 0);

	cout << memo[N - 1][0];
}