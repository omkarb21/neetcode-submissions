class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size()<t.size()) return "";
        
        unordered_map<char,int>sMap;
        unordered_map<char,int>tMap;
        
        int r=0;
        
        for(int i=0;i<t.length();i++){
            tMap[t[i]]++;
        }

        int need=tMap.size();
        int have=0;
        int l=0;

        int currentWindow=0;
        int minWindow=INT_MAX;
        pair<int,int>minWindowElements={0,0};

        while(r<s.size()){

            sMap[s[r]]++;
            if(sMap[s[r]]==tMap[s[r]]) have++;

            while(have==need){
                //find the window size, compare with minimum and store
                currentWindow=r-l+1;
                if(minWindow>currentWindow){
                    minWindow=currentWindow;
                    minWindowElements={l,r};
                }

                //try to shrink the window
                sMap[s[l]]--;
                if(sMap[s[l]]<tMap[s[l]]) have--;
                l++;
               
            }


            r++;
        }

        if(minWindow==INT_MAX) return "";
        else return s.substr(minWindowElements.first,minWindow);
    }
};
