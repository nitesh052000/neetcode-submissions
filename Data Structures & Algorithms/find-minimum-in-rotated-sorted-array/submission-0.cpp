class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int miniele = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[low]<=nums[mid]){
               miniele = min(miniele,nums[low]);
               low = mid+1;
            }
            else{
                miniele = min(miniele,nums[mid]);
                high = mid-1;
            }
        }
        return miniele;
    }
};
