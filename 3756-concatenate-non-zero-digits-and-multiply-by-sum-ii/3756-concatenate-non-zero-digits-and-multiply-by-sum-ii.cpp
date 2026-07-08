class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const int MOD = 1000000007;
        const int MX = 100001;

        static vector<long long> pow10 = []() {
            vector<long long> p(MX);
            p[0] = 1;
            for (int i = 1; i < MX; i++) {
                p[i] = (p[i - 1] * 10) % MOD;
            }
            return p;
        }();

        int n = s.size();

        vector<int> sumD(n + 1, 0);
        vector<int> cntN0(n + 1, 0);
        vector<long long> prefixNum(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            int digit = s[i - 1] - '0';

            sumD[i] = sumD[i - 1] + digit;

            cntN0[i] = cntN0[i - 1] + (digit > 0);

            if (digit != 0)
                prefixNum[i] = (prefixNum[i - 1] * 10 + digit) % MOD;
            else
                prefixNum[i] = prefixNum[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int nonZero = cntN0[r + 1] - cntN0[l];

            int digitSum = sumD[r + 1] - sumD[l];

            long long x =
                (prefixNum[r + 1] -
                 (prefixNum[l] * pow10[nonZero]) % MOD +
                 MOD) % MOD;

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};