class Solution {
public:
    
    void findComb(int k,int target,int start,vector<int>&ds,vector<vector<int>>&ans){
       //base case
       if(k==0&&target==0){
        ans.push_back(ds);
        return;
       }

       for(int i=start;i<=9;i++){
          if(i>target||k<=0)break;
          ds.push_back(i);
          findComb(k-1,target-i,i+1,ds,ans);
          ds.pop_back();


       }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        findComb(k,n,1,ds,ans);
        return ans;
    }
};