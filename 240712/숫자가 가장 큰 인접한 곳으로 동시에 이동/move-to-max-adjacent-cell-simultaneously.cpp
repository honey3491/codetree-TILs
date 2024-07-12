#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

short n, m, table[20][20], dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1 }, {0, 1} }, t;
deque <pair<short, short>> balls;

bool can_move(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= n)
		return false;
	else
		return true;
}

void remove_duplication()
{
	balls.erase(unique(balls.begin(), balls.end()), balls.end());
}

void move_to_maximum(int r, int c)
{
	short maximum = 0, max_r, max_c;
	for (int i = 0; i < 4; i++)
	{
		if (can_move(r + dxdy[i][0], c + dxdy[i][1]))
		{
			if (maximum < table[r + dxdy[i][0]][c + dxdy[i][1]])
			{
				maximum = table[r + dxdy[i][0]][c+dxdy[i][1]];
				max_r = r + dxdy[i][0];
				max_c = c + dxdy[i][1];
			}
		}
	}
	if(find(balls.begin(), balls.end(), make_pair(max_r, max_c))== balls.end())
		balls.push_back({ max_r, max_c });
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
		balls.push_back({ r-1, c-1 });
	}

	for (int i = 0; i < t; i++)
	{
		short ball = balls.size();
		for (int j = 0; j < ball; j++)
		{
			move_to_maximum(balls[0].first, balls[0].second);
			balls.erase(balls.begin());
		}
		remove_duplication();
		sort(balls.begin(), balls.end());
		reverse(balls.begin(), balls.end());
	}
	cout << balls.size();
}