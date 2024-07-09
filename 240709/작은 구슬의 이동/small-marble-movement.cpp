#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    map <char, int>m;
    m['U'] = 0;
    m['L'] = 1;
    m['D'] = 2;
    m['R'] = 3;
    vector <pair<int, int>>v = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    int now[2], way, count = 0, n, t;
    char direction;

    cin >> n >> t >> now[0] >> now[1] >> direction;
    way = m[direction];

    for (int i = 0; i < t; i++)
    {
        if (now[0] ==  1&& way == 0 || now[0] == n && way == 2 || now[1] == 1 && way == 1 || now[1] == n  && way == 3) {
            way = (way + 2) % 4;
        }
        else
        {
            now[0] += v[way].first;
            now[1] += v[way].second;
        }

    }
    
    cout <<  now[0] << ' ' << now[1];
}