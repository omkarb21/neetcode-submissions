class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currSum=0;
        int ans=-1;

        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return ans;
        for(int i=0;i<gas.size();i++){
            currSum+=gas[i]-cost[i];

            if(i==0 && currSum>=0) ans=i;

            if(currSum<0){
                currSum=0;
                if(i+1<gas.size()){
                    ans=i+1;
                }
            }
            

        }

        return ans;
    }
};
