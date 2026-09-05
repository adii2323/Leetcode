class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i=0;i<n;i++){
            high += nums[i];
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            int subarray = 1;
            int currentsum = 0;
            for(int i=0;i<n;i++){
                if(currentsum+nums[i]>mid){
                    subarray++;
                    currentsum=nums[i];
                }else{
                    currentsum += nums[i];
                }
            }
            if(subarray<=k){
                    ans=mid;
                    high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};