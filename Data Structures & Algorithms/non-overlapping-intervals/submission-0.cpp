class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int>b){return a[0]<b[0];});
        if(intervals.size()==0) return 0;

        int count=0;
        vector<int>curr=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<curr[1]){
                count++;
                if(curr[1]>intervals[i][1]){
                    curr=intervals[i];
                }
            }
            else{
                curr=intervals[i];
            }
        }

        return count;
    }
};
