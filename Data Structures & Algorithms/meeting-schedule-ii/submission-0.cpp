/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>startMeet;
        vector<int>endMeet;
        for(auto in:intervals){
            startMeet.push_back(in.start);
            endMeet.push_back(in.end);
        }

        sort(startMeet.begin(),startMeet.end(),[](int a,int b){return a<b;});
        sort(endMeet.begin(),endMeet.end(),[](int a,int b){return a<b;});

        int startPtr=0;
        int endPtr=0;


        int maxMeets=0;
        int currMeet=0;
        while(startPtr<startMeet.size()){
            if(startMeet[startPtr]<endMeet[endPtr]){
                currMeet++;
                maxMeets=max(currMeet,maxMeets);
                startPtr++;
            }
            else{
                currMeet--;
                endPtr++;
            }
        }


        return maxMeets;


    }
};
