class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 0; i + 1 < nums.size(); i++) {
            while (nums[i] + 1 < nums[i + 1]) {
                ans.push_back(++nums[i]);
            }
        }

        return ans;
    }
};