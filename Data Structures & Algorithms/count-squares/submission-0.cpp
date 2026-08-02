class CountSquares {
public:
    map<pair<int,int>,int>pointsMap;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pointsMap[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int result=0;
        int x=point[0];
        int y=point[1];
        for(auto [coords,count]:pointsMap){
            int cx=coords.first;
            int cy=coords.second;

            if(cx==x || cy==y) continue;
            if(abs(cx-x)!=abs(cy-y)) continue;

            pair<int,int>firstPoint={cx,y};
            pair<int,int>secondPoint={x,cy};
            if(pointsMap.count(firstPoint) && pointsMap.count(secondPoint)){
                result+=count*pointsMap[firstPoint]*pointsMap[secondPoint];
            }


        }
        return result;
    }
};
