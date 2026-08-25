class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0;

        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) {ans=-1;return ans;}
        int diff=0;
        for(int i=0;i<gas.size();i++){
            diff=diff+(gas[i]-cost[i]);

            if(diff<0){
                diff=0;
                ans=i+1;
            }
        }

        return ans;
    }
};
