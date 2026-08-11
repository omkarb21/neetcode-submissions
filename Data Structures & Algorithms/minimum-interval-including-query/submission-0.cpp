class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;


        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        int n=intervals.size();


        vector<pair<int,int>> qvector;
        for (int j = 0; j < queries.size(); j++) {
            qvector.push_back({queries[j], j});
        }

        sort(qvector.begin(),qvector.end());
        int i=0;
        vector<int> res(queries.size());
        //first add all elements whic have start lesser than query
        for(auto q:qvector){
            while(i<n){
                if(intervals[i][0]<=q.first){
                    int len=intervals[i][1]-intervals[i][0]+1;
                    minHeap.push({len,intervals[i][1]});
                    i++;
                }
                else{
                    break;
                }
            }
 //check heap if theres any interval. If its valid then also add interval lendth to answer array       
            
            
                while(!minHeap.empty() && (minHeap.top().second)<q.first){
                    minHeap.pop();
                }

                if(!minHeap.empty()){
                    res[q.second]=minHeap.top().first;
                } 
                else{
                    res[q.second]=-1;
                }
                

        }

        return res;
       
    }
};
