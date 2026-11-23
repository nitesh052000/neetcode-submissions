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
    // take
    res.push_back(nums[index]);
    solve(nums,target,ans,res,sum+nums[index],index);
    res.pop_back();

    // not take
    solve(nums,target,ans,res,sum,index+1);
   }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        int sum = 0;
        solve(nums,target,ans,res,sum,0);
        return ans;
    }
};
