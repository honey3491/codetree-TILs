#include <iostream>
using namespace std;

short T, N, M, ball_count, dxdy[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
pair<short, short> ball[50][50], tmp[50][50]; //first: the number of balls, second: balls direction 

void init_balls()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ball[i][j] = {0, 0};
		}
	}
}

void move_ball(int r, int c)
{
	if (r + dxdy[ball[r][c].second][0] < 0 || r + dxdy[ball[r][c].second][0] >= N || c + dxdy[ball[r][c].second][1] < 0 || c + dxdy[ball[r][c].second][1] >= N)
	{
		tmp[r][c].first++;
		tmp[r][c].second = (ball[r][c].second +2)% 4;
	}
	else
	{
		tmp[r + dxdy[ball[r][c].second][0]][c + dxdy[ball[r][c].second][1]].first++;
		tmp[r + dxdy[ball[r][c].second][0]][c + dxdy[ball[r][c].second][1]].second = ball[r][c].second;
	}
}

void remove_duplication()
{
	ball_count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tmp[i][j].first == 1)
			{
				ball_count++;
				ball[i][j].first = tmp[i][j].first;
				ball[i][j].second = tmp[i][j].second;
			}
			else
			{
				ball[i][j].first = 0;
				ball[i][j].second = 0;
			}
			//cout << ball[i][j].first << ' ';
			tmp[i][j].first = tmp[i][j].second = 0;
		}
		//cout << '\n';
	}
	//cout << '\n';
}

void simulation()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ball[i][j].first != 0)
				move_ball(i, j);
		}
	}
	remove_duplication();
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		init_balls();

		for (int j = 0; j < M; j++)
		{
			short r, c;
			char cmd;

			cin >> r >> c >> cmd;
			ball[r - 1][c - 1].first++;
			switch (cmd)
			{
			case 'L':
				ball[r - 1][c - 1].second = 0;
				break;
			case 'U':
				ball[r - 1][c - 1].second = 1;
				break;
			case 'R':
				ball[r - 1][c - 1].second = 2;
				break;
			case 'D':
				ball[r - 1][c - 1].second = 3;
				break;
			}
		}
		for (int k = 0; k < 100; k++) {
			simulation();
			if (ball_count <= 1)
				break;
		}
		cout << ball_count << '\n';
	}
}