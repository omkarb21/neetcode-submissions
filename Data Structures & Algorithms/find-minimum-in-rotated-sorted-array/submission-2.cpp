class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=nums[0];
        int startElement=nums[0];

        while(s<=e){
            int mid=s+(e-s)/2;

            if(mid>0 && nums[mid]<nums[mid-1]) return nums[mid];

            if(nums[mid]>=startElement){
                s=mid+1;
            }   
            else{
                ans=nums[mid];
                e=mid-1;
                
            }
        }

        return ans;
    }
};
