class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](vector<int>a,vector<int>b){return a[0]<b[0];});


        for(int i=1;i<intervals.size();){
            if(intervals[i-1][1]>=intervals[i][0]){
                intervals[i-1][1]=max(intervals[i][1],intervals[i-1][1]);
                intervals.erase(intervals.begin()+i);
            }
            else{
                i++;
            }
        }

        return intervals;
    }
};
