#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, A[100];
	cin >> n >> m;
	vector <int> v(m + 1, 100000);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	v[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = m; j >= A[i]; j--)
		{
			if (v[j - A[i]] != 100000)
			{
				v[j] = min(v[j], v[j - A[i]] + 1);
			}
		}
	}

	if (v[m] == 100000)
		v[m] = -1;
	cout << v[m];
}