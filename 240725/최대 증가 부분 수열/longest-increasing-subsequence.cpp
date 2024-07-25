#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

	int A[1000], N;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	vector <int> v;

	for (int i = 0; i < N; i++)
		v.push_back(1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
				v[i] = max(v[i], v[j] + 1);
		}
	}

	cout << *max_element(v.begin(), v.end());
	return 0;
}