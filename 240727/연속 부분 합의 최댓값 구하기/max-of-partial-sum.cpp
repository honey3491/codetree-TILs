#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	vector <int> A;


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}

	vector <int> D(n + 1, -10000);

	D[0] = A[0];
	for (int i = 1; i < n; i++) {
		D[i] = max(A[i], D[i - 1] + A[i]);
	}
	cout << *max_element(D.begin(), D.end());
}