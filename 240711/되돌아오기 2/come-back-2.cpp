#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	bool moved = false;
	int now[2] = { 0, 0 }, t = 0;
	vector <pair<int, int>> move = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	string cmd;

	cin >> cmd;
	for (int i = 0; i < cmd.length(); i++)
	{
		switch (cmd[i])
		{
		case 'F':
			now[0] += move[0].first;
			now[1] += move[0].second;
			moved = true;
			break;
		case 'L':
			rotate(move.begin(), move.begin() + 3, move.end());
			break;
		case 'R':
			rotate(move.begin(), move.begin() + 1, move.end());
			break;
		}

		t++;
		if (moved && now[0] == 0 && now[1] == 0) {
			cout << t;
			return 0;
		}
	}
	cout << -1;	
}