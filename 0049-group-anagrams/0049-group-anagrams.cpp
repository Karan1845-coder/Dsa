class Solution {
public:

    bool isAnagram(string a, string b) {

        if(a.size()!=b.size())
            return false;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a==b;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();

        vector<bool> visited(n,false);

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){

            if(visited[i])
                continue;

            visited[i]=true;

            vector<string> group;

            group.push_back(strs[i]);

            for(int j=i+1;j<n;j++){

                if(!visited[j] && isAnagram(strs[i],strs[j])){

                    visited[j]=true;
                    group.push_back(strs[j]);

                }

            }

            ans.push_back(group);
        }

        return ans;
    }
};