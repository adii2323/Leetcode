class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int i=0;i<n;i++){
            high += weights[i];
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            int daysneeded=1;
            int currentload=0;
            for(int i=0;i<n;i++){
                if(currentload+weights[i]>mid){
                    daysneeded++;
                    currentload=weights[i];
                }
                else{
                    currentload += weights[i];
                }
            }
            if(daysneeded<=days){
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};