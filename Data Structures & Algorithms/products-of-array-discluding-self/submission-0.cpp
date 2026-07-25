class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size(),1);
        
        for(int i=0;i<nums.size();i++){
            if(i==0) 
                result[0]=1;
            else
                result[i]=result[i-1]*nums[i-1];
        }
        
        int ans=1;
        for(int i=nums.size()-1;i>=0;i--){
           if(i==nums.size()-1)
            {
                ans=nums[i];
                continue;
            }
           result[i]=result[i]*ans;
           ans=ans*nums[i];
        }

        return result;
    }
};
