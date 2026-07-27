class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();

        vector<long long> best(nums.begin(), nums.end());

        long long ans = accumulate(best.begin(), best.end(), 0LL);

        for (int k = 1; k < n; k++) {

            long long sum = 1LL * k * x;

            for (int i = 0; i < n; i++) {
                best[i] = min(best[i], 1LL * nums[(i - k + n) % n]);
                sum += best[i];
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};