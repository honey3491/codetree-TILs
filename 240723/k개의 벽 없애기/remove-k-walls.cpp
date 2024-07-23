#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS function to find the shortest path from start to end
int bfs(vector<vector<int>>& grid, pii start, pii end, int n) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pii> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return dist[end.first][end.second];
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    
    pii start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    start.first--; start.second--;
    end.first--; end.second--;
    
    vector<pii> walls;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 1)
                walls.push_back({i, j});
    
    int min_time = INT_MAX;
    int total_walls = walls.size();
    vector<bool> mask(total_walls, false);
    fill(mask.begin(), mask.begin() + k, true);
    
    do {
        vector<vector<int>> new_grid = grid;
        for (int i = 0; i < total_walls; ++i)
            if (mask[i])
                new_grid[walls[i].first][walls[i].second] = 0;
        
        int time = bfs(new_grid, start, end, n);
        if (time != INT_MAX)
            min_time = min(min_time, time);
    } while (prev_permutation(mask.begin(), mask.end()));
    
    if (min_time == INT_MAX)
        cout << -1 << endl;
    else
        cout << min_time << endl;
    
    return 0;
}