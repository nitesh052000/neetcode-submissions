class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int>left(n);
        vector<int>right(n);

        stack<int>l;
        stack<int>r;

        
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
           
           while(!l.empty() && heights[l.top()]>=heights[i])
           l.pop();

           if(l.empty())
           left[i] = -1;
           else
           left[i] = l.top();

           l.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!r.empty() && heights[r.top()]>=heights[i])
            r.pop();

            if(r.empty())
            right[i] = n;
            else
            right[i] = r.top();

            r.push(i);
        }

        for(int i=0;i<n;i++){
            ans = max(ans,abs(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};
