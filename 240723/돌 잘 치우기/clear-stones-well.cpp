#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS function to count reachable cells
int bfs(vector<vector<int>>& grid, vector<pii>& starts, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pii> q;
    int count = 0;
    
    for (const auto& start : starts) {
        q.push(start);
        visited[start.first][start.second] = true;
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        count++;
        
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    return count;
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<vector<int>> grid(n, vector<int>(n));
    vector<pii> starts(k);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        starts[i] = {r-1, c-1};
    }
    
    vector<pii> stones;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 1)
                stones.push_back({i, j});
    
    int max_reachable = 0;
    int total_stones = stones.size();
    vector<bool> mask(total_stones, false);
    fill(mask.begin(), mask.begin() + m, true);
    
    do {
        vector<vector<int>> new_grid = grid;
        for (int i = 0; i < total_stones; ++i)
            if (mask[i])
                new_grid[stones[i].first][stones[i].second] = 0;
        
        int reachable = bfs(new_grid, starts, n);
        max_reachable = max(max_reachable, reachable);
    } while (prev_permutation(mask.begin(), mask.end()));
    
    cout << max_reachable << endl;
    
    return 0;
}