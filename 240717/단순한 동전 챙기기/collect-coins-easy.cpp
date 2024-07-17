#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX_N = 20;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct State {
    int x, y, steps, coins_collected, last_coin;
};

bool is_valid(int x, int y, int N, const vector<string>& grid) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != '.';
}

int bfs(const vector<string>& grid, int N, pair<int, int> start, pair<int, int> end) {
    queue<State> q;
    bool visited[MAX_N][MAX_N][10][10];
    memset(visited, false, sizeof(visited));
    
    q.push({start.first, start.second, 0, 0, 0});
    visited[start.first][start.second][0][0] = true;
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        if (make_pair(current.x, current.y) == end && current.coins_collected >= 3) {
            return current.steps;
        }
        
        for (const auto& dir : directions) {
            int nx = current.x + dir[0];
            int ny = current.y + dir[1];
            if (is_valid(nx, ny, N, grid)) {
                int new_steps = current.steps + 1;
                if (isdigit(grid[nx][ny])) {
                    int coin = grid[nx][ny] - '0';
                    if (coin == current.last_coin + 1) {
                        int new_coins_collected = current.coins_collected + 1;
                        if (!visited[nx][ny][new_coins_collected][coin]) {
                            visited[nx][ny][new_coins_collected][coin] = true;
                            q.push({nx, ny, new_steps, new_coins_collected, coin});
                        }
                    }
                } else {
                    if (!visited[nx][ny][current.coins_collected][current.last_coin]) {
                        visited[nx][ny][current.coins_collected][current.last_coin] = true;
                        q.push({nx, ny, new_steps, current.coins_collected, current.last_coin});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<string> grid(N);
    pair<int, int> start, end;

    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'E') {
                end = {i, j};
            }
        }
    }

    int result = bfs(grid, N, start, end);
    cout << result << endl;

    return 0;
}