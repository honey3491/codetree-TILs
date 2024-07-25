#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, A[1000];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	vector <int> v;

	for (int i = 0; i <= M; i++)
		v.push_back(-1);

	v[0] = 0;

	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int remain = i - A[j];
			if (remain < 0 || v[remain] == -1)
				continue;
			if (v[i] == -1 || v[i] > v[remain] + 1)
				v[i] = v[remain] + 1;
		}
	}

	cout << v[M];
}