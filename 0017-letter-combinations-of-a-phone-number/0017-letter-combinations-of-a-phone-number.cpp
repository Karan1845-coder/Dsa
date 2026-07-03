class Solution {
public:
   void comb( string&digits,string&s,unordered_map<int,string>&mp,int index,vector<string>&ans){
       if(s.size()==digits.size()){
        ans.push_back(s);
        return;
       }
      string letters = mp[digits[index] - '0'];

       for(int i=0;i<letters.size();i++){
          s.push_back(letters[i]);
          comb(digits,s,mp,index+1,ans);
          s.pop_back();
       }

   }


    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string>ans;
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string s="";

        comb(digits,s,mp,0,ans);
        return ans;



    }
};