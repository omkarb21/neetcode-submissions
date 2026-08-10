class Solution {
public:
    int checkIfValid(vector<int>&piles, int mid){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=piles[i]/mid;
            if(piles[i]%mid!=0) ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int res=e;

        while(s<=e){
        //find mid and check if ans is lesser than or equal to k
        int mid=s+(e-s)/2;

        int ans=checkIfValid(piles, mid);

        //if answer is lesser than h, decrease teh range e=mid-1
        if(ans<=h){
            res=mid;
            e=mid-1;
        }
        else{
            //if answer is greater, s=mid+1
            s=mid+1;
        }
        
        }

        return res;
        
    }
};
