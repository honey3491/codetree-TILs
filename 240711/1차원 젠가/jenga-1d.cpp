#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	short n, a;
	vector <short> v;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < 2; i++)
	{
		int s, e;
		cin >> s >> e;
		v.erase(v.begin() + s - 1, v.begin() + e);
	}

	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}