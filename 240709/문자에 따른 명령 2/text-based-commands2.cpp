#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    vector <pair<int, int>>v = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int now[2] = {0, 0};

    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case 'L':
            rotate(v.begin(), v.begin() + 3, v.end());
            break;
        case 'R':
            rotate(v.begin(), v.begin() + 1, v.end());
            break;
        case 'F':
            now[0] = now[0] + v.front().first;
            now[1] = now[1] + v.front().second;
            break;
        }
    }
    cout << now[0] << ' ' << now[1];
}