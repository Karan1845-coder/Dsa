class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty,
                            vector<int>& profit,
                            vector<int>& worker) {

        vector<pair<int, int>> jobs;

        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int j = 0;
        int bestProfit = 0;
        int ans = 0;

        for (int i = 0; i < worker.size(); i++) {

            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                bestProfit = max(bestProfit, jobs[j].second);
                j++;
            }

            ans += bestProfit;
        }

        return ans;
    }
};