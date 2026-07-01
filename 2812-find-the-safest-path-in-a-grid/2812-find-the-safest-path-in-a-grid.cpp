class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Multi-source BFS to calculate distance from nearest thief
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    dist[nx][ny] == INT_MAX) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Dijkstra (Max Heap)
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (vis[x][y])
                continue;

            vis[x][y] = 1;

            if (x == n - 1 && y == n - 1)
                return safe;

            for (int k = 0; k < 4; k++) {

                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    !vis[nx][ny]) {

                    int newSafe = min(safe, dist[nx][ny]);
                    pq.push({newSafe, nx, ny});
                }
            }
        }

        return 0;
    }
};