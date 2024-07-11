#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, r, c, sum ;
	short board[102][102], move[4][2] = { {0, 1} ,{1, 0}, {0, -1}, {-1, 0} };

	vector <int> v;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c;
		board[r][c] = 1;

		short count = 0;
		
		for (int j = 0; j < 4; j++)
		{
			if (board[r + move[j][0]][c + move[j][1]] == 1)
				count++;
		}
		if (count == 3)
			v.push_back(1);
		else
			v.push_back(0);
	}
	for (int i = 0; i < M; i++)
		cout << v[i] << '\n';

}