class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp=arr;

        sort(temp.begin(),temp.end());
        unordered_map<int,int>rank;

        int r=1;

        for(int i=0;i<n;i++){
            if(!rank.count(temp[i])){
                rank[temp[i]]=r;
                r++;
            }
        }
        vector<int>ans;

        for(int i=0;i<n;i++){
            ans.push_back(rank[arr[i]]);
        }
        return ans;
    }
};