class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int n1 = s1.length();
      int n2 = s2.length();

      vector<int>need(26);
      vector<int>window(26);

      for(int i=0;i<n1;i++){
        char ch = s1[i];
        need[ch-'a']++;
      }

      int i =0;

      for(int j=0;j<n2;j++){
        window[s2[j]-'a']++;

        if(j-i+1==n1){

            if(need == window)
            return true;

            window[s2[i]-'a']--;
            i++;
        }
      }

return false;
    }
};
