#include <iostream>
#include <algorithm>

using namespace std;

int n, m, table[20][20], balls[20][20] = { 0, }, tmp[20][20] = { 0, }, dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }, t, c = 0;

bool can_move(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= n)
		return false;
	else
		return true;
}

void remove_duplication()
{
	c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tmp[i][j] >= 2)
			{
				m -= tmp[i][j];
				tmp[i][j] = 0;
			}
			balls[i][j] = tmp[i][j];
			c += balls[i][j];
			tmp[i][j] = 0;
		}
	}
}

void move_to_maximum(int r, int c)
{
	short maximum = -1, max_r, max_c;
	for (int i = 0; i < 4; i++)
	{
		if (can_move((r + dxdy[i][0]), (c + dxdy[i][1])))
		{
			if (maximum < table[r + dxdy[i][0]][c + dxdy[i][1]])
			{
				maximum = table[r + dxdy[i][0]][c + dxdy[i][1]];
				max_r = r + dxdy[i][0];
				max_c = c + dxdy[i][1];
			}
		}
	}

	tmp[max_r][max_c]++;
}

void simulate()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (balls[i][j] != 0)
				move_to_maximum(i, j);
		}
	}
	remove_duplication();
}

int main()
{
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> table[i][j];
	}

	for (int i = 0; i < m; i++)
	{
		short r, c;
		cin >> r >> c;
		balls[r - 1][c - 1]++;
	}

	for (int i = 0; i < t; i++)
	{
		simulate();
	}

	cout << c;
}