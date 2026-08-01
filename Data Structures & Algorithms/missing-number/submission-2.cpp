class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=nums.size();
        int arraySum=0;
        for(int i=0;i<nums.size();i++){
            arraySum=arraySum+nums[i];
            sum=sum+i;
        }

        return sum-arraySum;


    }
};
