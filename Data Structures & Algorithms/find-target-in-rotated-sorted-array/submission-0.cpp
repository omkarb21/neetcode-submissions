class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s=0;
        int e=nums.size()-1;
        int firstElement=nums[0];


        while(s<=e){
            int mid=s+(e-s)/2;
        
            //check if it is equal to target or not
            if(nums[mid]==target) return mid;

            //check if element in right or left branch
            if(target>=firstElement){
                if(nums[mid]>=firstElement){
                    if(nums[mid]>target){
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
                }
                else{
                    e=mid-1;
                }
            }
            else{
                if(nums[mid]>=firstElement){
                    s=mid+1;
                }
                else{
                    if(nums[mid]>target){
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
                }
            }
            
        }

        return -1;
        
    }
};
