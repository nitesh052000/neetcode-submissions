class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        int n = s.length();

        for(int i=0;i<n;i++){
           char ch = s[i];

           if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
           }
           else{

               if(st.empty())
               return false;

            
                if(s[i]=='}' && st.top()=='{'|| s[i] ==')' && st.top()=='(' || s[i]==']' && st.top() =='[')
                st.pop();
                else
                return false;
             
           }
        }
        
        return st.empty();
    }
};
