class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> dist;
    string beginWord;

    void dfs(string word, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        int steps = dist[word];

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (dist.count(word) && dist[word] == steps - 1) {
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        this->beginWord = beginWord;

        queue<string> q;
        q.push(beginWord);

        dist[beginWord] = 0;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int steps = dist[word];

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.count(word)) {
                        dist[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path = {endWord};
        dfs(endWord, path);

        return ans;
    }
};