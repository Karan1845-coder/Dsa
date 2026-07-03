class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);

        int mx = 0;

        // Build graph while removing offline intermediate nodes
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if ((u != 0 && u != n - 1 && !online[u]) ||
                (v != 0 && v != n - 1 && !online[v]))
                continue;

            adj[u].push_back({v, w});
            mx = max(mx, w);
        }

        auto check = [&](int limit) {

            vector<ll> dist(n, INF);

            priority_queue<
                pair<ll,int>,
                vector<pair<ll,int>>,
                greater<pair<ll,int>>
            > pq;

            dist[0] = 0;
            pq.push({0, 0});

            while (!pq.empty()) {

                auto [d, u] = pq.top();
                pq.pop();

                if (d != dist[u])
                    continue;

                if (d > k)
                    continue;

                if (u == n - 1)
                    return true;

                for (auto &[v, w] : adj[u]) {

                    if (w < limit)
                        continue;

                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            return false;
        };

        int low = 0;
        int high = mx;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};