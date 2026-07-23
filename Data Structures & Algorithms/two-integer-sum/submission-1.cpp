class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>st;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(st.find(complement)!=st.end())return vector<int>{st[complement],i};
            st[nums[i]]=i;
        }

        return {};
    }
};
