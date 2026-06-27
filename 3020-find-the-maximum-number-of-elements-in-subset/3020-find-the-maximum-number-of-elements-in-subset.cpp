class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int ans = 1;

        // Handle the special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = freq[1] - 1;
            else
                ans = freq[1];
        }

        unordered_map<long long, int>::iterator it;

        for (it = freq.begin(); it != freq.end(); it++) {

            long long num = it->first;

            if (num == 1)
                continue;

            long long x = num;
            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {
                len += 2;
                x = x * x;
            }

            if (freq.count(x))
                len += 1;
            else
                len -= 1;

            ans = max(ans, len);
        }

        return ans;
    }
};