class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int,int>>st;
        int n = temperatures.size();
        vector<int>ans;

        ans.push_back(0);
        st.push({temperatures[n-1],n-1});

        for(int i=n-2;i>=0;i--){
           while(!st.empty() && temperatures[i] >= st.top().first){
            st.pop();
           }

           if(st.empty())
           ans.push_back(0);
           else
           ans.push_back(st.top().second-i);

           st.push({temperatures[i],i});
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
