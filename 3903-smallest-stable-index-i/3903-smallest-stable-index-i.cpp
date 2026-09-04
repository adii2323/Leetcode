class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int maxi = *max_element(nums.begin(),nums.begin()+i+1);
            int mini = *min_element(nums.begin()+i,nums.end());
            long ins_score = (long)maxi - (long)mini;
            if(ins_score<=k){
                return i;
            }
        }
        return -1;
    }
};