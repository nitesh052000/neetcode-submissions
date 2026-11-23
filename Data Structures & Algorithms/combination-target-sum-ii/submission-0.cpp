class Solution {
public:


void solve(vector<int>& nums, int target, vector<vector<int>>&ans,vector<int>&res,int sum,int index){
     
      if(sum == target) {
        ans.push_back(res);
        return;
    }

    if(index >= nums.size() || sum > target) {
        return;
    }
    // take and not take dono isme ho jaega isliye not take ki call nahi kar rahe 
    for(int i=index;i<nums.size();i++){
        
        if(i>index && nums[i]==nums[i-1])
        continue;

         res.push_back(nums[i]);
         solve(nums,target,ans,res,sum+nums[i],i+1);
         res.pop_back();
    }
   
   }
  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>res;
        int sum = 0;
        solve(candidates,target,ans,res,sum,0);
        return ans;
    }
};
