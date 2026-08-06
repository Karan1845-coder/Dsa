class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {

        priority_queue<int> pq;
        int ans = 0;

        for (int x : r2)
            ans += x;

        for (int i = 0; i < r1.size(); i++)
            pq.push(r1[i] - r2[i]);

        while (k--) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};