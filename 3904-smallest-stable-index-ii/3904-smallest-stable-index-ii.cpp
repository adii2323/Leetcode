class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffmin(n);
        suffmin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffmin[i] = min(suffmin[i+1],nums[i]);
        }
        int prefmax=nums[0];
        for(int i=0;i<n;i++){
            prefmax=max(prefmax,nums[i]);
            int ins_score = prefmax-suffmin[i];
            if(ins_score<=k){
                return i;
            }
        }
        return -1;
    }
};