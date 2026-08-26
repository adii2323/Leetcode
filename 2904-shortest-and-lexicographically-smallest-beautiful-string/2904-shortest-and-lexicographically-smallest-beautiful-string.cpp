class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int ones=0;
        int left=0;
        for(int right=0;right<n;right++){
            if(s[right]=='1'){
                ones++;
            }
            while((left<=right)&&(ones>k || s[left]=='0')){
                if(s[left]=='1'){
                    ones--;
                }
                left++;
            }
            if(ones==k){
                string ans2 = s.substr(left,right-left+1);
            if(ans.empty()){
                ans=ans2;
            }
            else if(ans2.length()<ans.length()){
                ans=ans2;
            }
            else if(ans2.length()==ans.length() && ans2<ans){
                ans=ans2;
            }
            }
        }
        return ans;
    }
};