class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini_ele = prices[0];
        int maxi = 0;

        for(int i=1;i<n;i++){

            if(prices[i]<mini_ele){
                mini_ele = prices[i];
            }
            else{
                maxi = max(maxi,(prices[i]-mini_ele));
            }
        }
        return maxi;
    }
};
