class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if((long long)m*k>n)return -1;
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=0;
            int flower=0;
            for(int i=0;i<n;i++){
                if(mid>=nums[i]){
                    cnt++;
                    if(cnt==k){
                        flower++;
                        cnt=0;
                    }
                }
                else{
                    cnt=0;
                }
            }
            if(flower>=m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};