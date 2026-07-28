class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        unordered_set<int>mp;
        int currLength=0;
        int maxLength=0;

        while(r<s.length()){
            while(mp.find(s[r])!=mp.end()){
                mp.erase(s[l]);
                l=l+1;
                currLength--;

            }
            mp.insert(s[r]);
            currLength=currLength+1;
            maxLength=max(maxLength,currLength);
            r++;
            

        }

        return maxLength;
    }
};
