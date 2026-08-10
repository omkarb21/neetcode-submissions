class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans="";

        if(mp.find(key)!=mp.end()){
            int s=0;
            int e=mp[key].size()-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(mp[key][mid].second==timestamp) {
                    return mp[key][mid].first;
                    
                }
                if(mp[key][mid].second>timestamp){
                    e=mid-1;
                }
                else{
                    ans=mp[key][mid].first;
                    s=mid+1;
                }
            }
        }
        

        return ans;

    }
};
