#include <iostream>
using namespace std;

int main()
{
	int n, m, value[100][100] = { { 0, } }, now[2] = { 0, 0 }, move[4][2] = { {0, 1} ,{1, 0}, {0, -1}, {-1, 0} };
	int move_val = 0;

	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
	{
		value[now[0]][now[1]] = i+1;
		if ((now[1] == m - 1 && move_val == 0) || (now[0] == n - 1 && move_val == 1 )|| (now[1] == 0 && move_val == 2) || (now[0] == 0 && move_val == 3) || value[now[0] + move[move_val][0]][now[1] + move[move_val][1]] != 0)
			move_val = (move_val + 1) % 4;

		now[0] += move[move_val][0];
		now[1] += move[move_val][1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << value[i][j] << ' ';
		cout << '\n';
	}
}