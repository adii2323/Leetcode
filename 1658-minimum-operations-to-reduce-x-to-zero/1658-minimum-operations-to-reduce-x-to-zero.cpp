class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(*min_element(nums.begin(),nums.end())>x)return -1;
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total-x;
        if(target<0)return -1;
        if(target==0)return n;

        int left=0;
        int sum=0;
        int longest=-1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(left<=i && sum>target){
                sum -= nums[left++];
            }
            if(sum==target){
                longest = max(longest,i-left+1);
            }
        }
        if(longest==-1)return -1;
        else return n-longest;
    }
};