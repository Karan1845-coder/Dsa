class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i + k <= nums.size(); i++) {
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                mp[x]++;
            }
        }

        int ans = -1;

        for (auto [x, cnt] : mp) {
            if (cnt == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};