class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        string ans="";
        while(!mpp.empty()){
            int maxfreq=0;
            char maxchar=0;
            for(auto it:mpp){
                if(it.second>maxfreq){
                    maxfreq=it.second;
                    maxchar=it.first;
                }
            }
            while(maxfreq--){
                ans.push_back(maxchar);
            }
            mpp.erase(maxchar);
        }
        return ans;
    }
};