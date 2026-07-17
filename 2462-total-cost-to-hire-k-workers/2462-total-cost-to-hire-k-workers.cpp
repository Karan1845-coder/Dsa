class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0;
        int j = costs.size() - 1;

        for (int c = 0; c < candidates && i <= j; c++) {
            left.push(costs[i++]);
        }

        for (int c = 0; c < candidates && i <= j; c++) {
            right.push(costs[j--]);
        }

        long long ans = 0;

        while (k--) {
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                ans += left.top();
                left.pop();

                if (i <= j) {
                    left.push(costs[i++]);
                }
            } else {
                ans += right.top();
                right.pop();

                if (i <= j) {
                    right.push(costs[j--]);
                }
            }
        }

        return ans;
    }
};