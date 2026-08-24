class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0;
        int right=0;
        int maxJump=0;
        int jumpCount=0;

        if(nums.size()==1) return 0;

        while(right<nums.size()-1){
            maxJump=0;
            for(int i=left;i<=right;i++){
                maxJump=max(maxJump, nums[i]+i);
            }
            left=right+1;
            right=maxJump;
            
            jumpCount++;
            
            
        }

        return jumpCount;
    }
};
