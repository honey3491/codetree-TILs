#include <iostream>
using namespace std;

int main() {
    int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 }, now[2] = {0, 0}, N, dist;
    char cmd;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> cmd >> dist;
        switch (cmd)
        {
        case 'W':
            now[0] = now[0] + dx[0] * dist;
            now[1] = now[1] + dy[0] * dist;
            break;
        case 'S':
            now[0] = now[0] + dx[1] * dist;
            now[1] = now[1] + dy[1] * dist;
            break;
        case 'N':
            now[0] = now[0] + dx[2] * dist;
            now[1] = now[1] + dy[2] * dist;
            break;
        case 'E':
            now[0] = now[0] + dx[3] * dist;
            now[1] = now[1] + dy[3] * dist;
            break;
        }
    }

    cout << now[0] << ' ' << now[1];
    return 0;
}