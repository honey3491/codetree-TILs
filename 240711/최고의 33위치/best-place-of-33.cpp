#include <iostream>
#include <algorithm>
using namespace std;

int map[20][20];

int get_gold(int r, int c)
{
	int count = 0;
	for (int i = r; i < r + 3; i++)
	{
		for (int j = c; j < c + 3; j++) {
			count += map[i][j];
		}
	}
	return count;
}

int main()
{
	int N, max_gold = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < N - 2; j++)
			max_gold = max(get_gold(i, j), max_gold);
	}
	cout << max_gold;
	return 0;
}