class Solution {
public:
  
   void solve(vector<int>&nums,int index,vector<vector<int>>&ans,vector<int>&res){
      
      if(index>=nums.size()){
        ans.push_back(res);
        return;
      }
     
     // take case 
      res.push_back(nums[index]);
      solve(nums,index+1,ans,res);
      res.pop_back();

      // not take case 
      solve(nums,index+1,ans,res);

   }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,0,ans,res);
        return ans;
    }
};
