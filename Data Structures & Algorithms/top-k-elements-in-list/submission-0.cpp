class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int element:nums){
            mp[element]++;
        }

        vector<vector<int>>freqMapping(nums.size()+1);

        for(auto mpPair:mp){
            freqMapping[mpPair.second].push_back(mpPair.first);
        }

        vector<int>result;
        for(int i=freqMapping.size()-1;i>0;i--){
                for(auto t:freqMapping[i]){
                    result.push_back(t);
                    if(result.size()==k) return result;
                }
        }

    }
};
