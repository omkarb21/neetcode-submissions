class Solution {
public:
    vector<int> partitionLabels(string s) {
        //create a map of last characters
        unordered_map<int,int>mp;
        for(int i=s.size()-1;i>=0;i--){
            if(mp.count(s[i])) continue;
            else mp[s[i]]=i;
        }

        //iterate over string
            //get end and iterate till end, check for updating the end, if not increase length count
            //once you reach end, update length to ans
        int i=0;
        int lengthOfString=0;
        vector<int>ans;
        while(i<s.size()){
            lengthOfString=0;
            int end=mp[s[i]];
            int start=i;
            while(start<=end){
                if(mp[s[start]]>end){
                    end=mp[s[start]];
                }
                start++;
                lengthOfString++;
            }
            ans.push_back(lengthOfString);
            i=end+1;
        }

        return ans;
    }
};
