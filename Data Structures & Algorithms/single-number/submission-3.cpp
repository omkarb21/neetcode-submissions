class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            flag=false;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j] && i!=j) flag=true;
            }
            
            if (flag==false) return nums[i]; 
        }

        return 0;
    }
};
