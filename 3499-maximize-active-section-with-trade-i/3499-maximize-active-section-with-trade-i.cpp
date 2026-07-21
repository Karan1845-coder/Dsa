class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();

        int ans = 0;
        int i = 0;

        int pre = INT_MIN;
        int mx = 0;

        while (i < n) {

            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            int cur = j - i;

            if (s[i] == '1') {
                ans += cur;
            } else {
                mx = max(mx, pre + cur);
                pre = cur;
            }

            i = j;
        }

        return ans + mx;
    }
};