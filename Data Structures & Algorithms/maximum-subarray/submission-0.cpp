class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int CurrSum=0;
        for(int i=0;i<nums.size();i++){
            if(CurrSum<0) CurrSum=0;
            CurrSum+=nums[i];
            maxSum=max(CurrSum,maxSum);
        }

        return maxSum;
    }
};
