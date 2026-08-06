class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);

        for (auto &x : logs) {
            diff[x[0] - 1950]++;
            diff[x[1] - 1950]--;
        }

        int cur = 0;
        int mx = 0;
        int ans = 1950;

        for (int i = 0; i < 101; i++) {
            cur += diff[i];

            if (cur > mx) {
                mx = cur;
                ans = i + 1950;
            }
        }

        return ans;
    }
};