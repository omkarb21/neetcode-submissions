class Solution {
public:
    int getMaxFreqFromMap(unordered_map<char,int>mp){
        int maxCount=0;
        for(auto ele:mp){
            maxCount=max(maxCount,ele.second);
            
        }return maxCount;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        int mostFreq=0;
        int validLength=0;

        if (s.length()==0) return validLength;
        
        
        while(r<s.length()){
            mp[s[r]]++;
            mostFreq=getMaxFreqFromMap(mp);
            if((r-l+1)-mostFreq<=k)  {
                validLength++;
                
            }
            else{
                
                mp[s[l]]--;
                l++;
            }
            
            r++;
            
        }

        return validLength;
    }
};
