class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        map<int,int>mp;
        vector<int>ans;
        int i=0,j=0,cneg=0;

        while(j<n){
            //put the negative elements to map
            if(nums[j]<0){
                mp[nums[j]]++;
                cneg++;
            }

            //if the window is completed
            if(j-i+1==k){
                //ans calcultion
                if(cneg<x)ans.push_back(0);
                else{
                    int cnt=x;
                    for(auto it:mp){
                        if(it.second>=cnt){ans.push_back(it.first); break;}
                        else{
                            cnt-=it.second;
                        }

                    }
                }
                //removal of i
                if(nums[i]<0){
                mp[nums[i]]--;
                cneg--;
                }
                i++;
            }
            j++;

            
        }
        return ans;


    }
};