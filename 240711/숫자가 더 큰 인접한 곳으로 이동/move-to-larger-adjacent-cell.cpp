#include <iostream>
using namespace std;

int main()
{
	short n, r, c;
	short map[100][100], move[4][2] = { {-1, 0},{1, 0}, {0, -1}, {0, 1} };

	cin >> n >> r >> c;

	r--;
	c--;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	bool t = true;

	cout << map[r][c] << ' ';
	while (t)
	{
		t = false;
		for (int i = 0; i < 4; i++)
		{
			if (r + move[i][0] < 0 || r + move[i][0] >= n || c + move[i][1] < 0 || c + move[i][1] >= n)
				continue;

			if (map[r + move[i][0]][c + move[i][1]] > map[r][c])
			{
				r += move[i][0];
				c += move[i][1];
				cout << map[r][c] << ' ';
				t = true;
				break;
			}
		}
	}
}