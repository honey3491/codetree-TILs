#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main()
{
	short n, t, a;
	deque <short> v;
	cin >> n >> t;
	
	for (int i = 0; i < n*3; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	
	t = t % (n * 2);

	for (int i = 0; i < t; i++)
	{
		short tmp = v.back();
		v.pop_back();
		v.push_front(tmp);
	}
	
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << '\n';
	for (int i = n; i < n * 2; i++)
		cout << v[i] << ' ';
	cout << '\n';
	for (int i = n * 2; i < n * 3; i++)
		cout << v[i] << ' ';

}