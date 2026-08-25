class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;


        if(hand.size()%groupSize!=0) return false;

        int i=0;
        while(i<hand.size()){
            mp[hand[i]]++;
            if(mp[hand[i]]==1){
                pq.push(hand[i]);
            }
            i++;
            
        }
        bool ans=true;



        while(!pq.empty()){
            
            
            int i=0;
            bool innerAns=true;
            
            
    
            int first=pq.top();
            if (mp[first] == 0) {
                pq.pop();
                continue;
            }
            

            while(i<groupSize){
                if(mp.count(first+i)==0 || mp[first+i]==0){
                    innerAns=false;
                    break;
                }
                else{
                    mp[first+i]--;
                }
                i++; 
            }

            if(mp[first]==0){
                pq.pop();
            }



            if(!innerAns){
                ans=false;
                break;
            }



        }

        return ans;


    }
};
