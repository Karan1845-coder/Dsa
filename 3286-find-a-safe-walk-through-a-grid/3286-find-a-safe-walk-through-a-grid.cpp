class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        dist[0][0] = grid[0][0];
        q.push({0,0});

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;

                int newCost = dist[x][y] + grid[nx][ny];

                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    q.push({nx,ny});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};