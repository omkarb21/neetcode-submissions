class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target=nums.size()-1;
        int i=target-1;
        bool canReach=true;
        while(i>=0){
            if(target-i<=nums[i]){
                canReach=true;
                target=i;
                i--;
            }else{
                canReach=false;
                i--;
            }
        }


        return canReach;
    }
};
