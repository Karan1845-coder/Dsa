class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

       
        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;

        int p = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < m; ++i) {

            while (p < n) {

                // Exact match
                if (word1[p] == word2[i]) {
                    ans.push_back(p);
                    p++;
                    break;
                }

                // Try using the one mismatch here
                if (!mismatchUsed) {

                    int remaining = m - i - 1;

                    if (suf[p + 1] >= remaining) {
                        ans.push_back(p);
                        p++;
                        mismatchUsed = true;
                        break;
                    }
                }

                p++;
            }

            if ((int)ans.size() != i + 1)
                return {};
        }

        return ans;
    }
};