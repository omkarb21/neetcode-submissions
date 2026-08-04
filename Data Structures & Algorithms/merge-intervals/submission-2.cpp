class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](vector<int>a,vector<int>b){return a[0]<b[0];});

        vector<vector<int>>res;
        for(auto in:intervals){
            if(!res.empty() && res.back()[1]>=in[0]){
                res.back()[1]=max(res.back()[1],in[1]);
            }
            else{
                res.push_back(in);
            }

            
        }

        return res;
    }
};
