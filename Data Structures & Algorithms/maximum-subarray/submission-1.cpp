class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lastSum=0;
        int maxSum=nums[0];
        for(int i=0;i<nums.size();i++){
            if(lastSum<0) lastSum=nums[i];
            else lastSum+=nums[i];
            maxSum=max(maxSum,lastSum);
        }

        return maxSum;
    }
};
