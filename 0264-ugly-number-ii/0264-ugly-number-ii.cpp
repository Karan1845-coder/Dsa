class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);

        dp[0] = 1;

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int i = 1; i < n; i++) {
            int x = dp[i2] * 2;
            int y = dp[i3] * 3;
            int z = dp[i5] * 5;

            dp[i] = min({x, y, z});

            if (dp[i] == x)
                i2++;

            if (dp[i] == y)
                i3++;

            if (dp[i] == z)
                i5++;
        }

        return dp[n - 1];
    }
};