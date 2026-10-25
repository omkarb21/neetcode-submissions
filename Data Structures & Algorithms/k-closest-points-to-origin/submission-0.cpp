class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>maxHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>>maxHeap;


        int i=0;
        for(auto p:points){
            int dist=p[0]*p[0]+p[1]*p[1];
            if(maxHeap.size()<k){
                maxHeap.push({dist,i});
            }
            else{
                if(dist<maxHeap.top().first){
                    maxHeap.pop();
                    maxHeap.push({dist,i});
                }
            }


            i++;
        }
        vector<vector<int>>result;
        while(!maxHeap.empty()){
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};
