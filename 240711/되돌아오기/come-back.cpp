#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, now[2] = { 0, 0 }, move[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }, jump, time = 0;
	char cmd;

	vector <pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd >> jump;
		int direction;
		switch (cmd)
		{
		case 'N':
			direction = 0;
			break;
		case 'E':
			direction = 1;
			break;
		case 'W':
			direction = 2;
			break;
		case 'S':
			direction = 3;
			break;
		}
		v.push_back({ direction, jump });
	}
	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < v[i].second; j++)
		{
			now[0] += move[v[i].first][0];
			now[1] += move[v[i].first][1];
			time++;
			if (now[0] == 0 && now[1] == 0)
			{
				cout << time;
				return 0;
			}
		}
	}
	cout << -1;
	
}