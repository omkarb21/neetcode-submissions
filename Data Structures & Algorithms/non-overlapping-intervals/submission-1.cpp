class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        
        if (intervals.size()==0) return 0;

        vector<int>prev=intervals[0];
        int count=0;
        for(int i=1;i<intervals.size();i++){
            auto curr=intervals[i];
            if(curr[0]<prev[1]) {
                count++;
                if(min(curr[1],prev[1])==curr[1]){
                    prev=curr;
                }
                
            }
            else{
                prev=curr;
            }
        }

        return count;
    }
};
