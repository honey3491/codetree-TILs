#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, A[100];
	cin >> n >> m;
	vector <int> v(m + 1, -1);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	v[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = m; j >= A[i]; j--)
		{
			if (v[j - A[i]] != -1)
			{
				if (v[j] == -1)
					v[j] == 1;
				v[j] = min(v[j], v[j - A[i]] + 1);
			}
		}
	}

	cout << v[m];
}