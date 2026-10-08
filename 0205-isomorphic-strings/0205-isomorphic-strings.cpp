class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        if(s.length()!=t.length())return false;
        unordered_map<int,int>mppst;
        unordered_map<int,int>mppts;
        for(int i=0;i<n;i++){
            char st=s[i],ts=t[i];
            while(mppst.count(st)&&mppst[st]!=ts)return false;
            while(mppts.count(ts)&&mppts[ts]!=st)return false;
            mppst[st]=ts;
            mppts[ts]=st;
        }
        return true;
    }
};