class Solution {
public:
    bool isAnagram(string s, string t) {
    //     unordered_map<char,int>smap;
    //     unordered_map<char,int>tmap;

    //     if(s.size()!=t.size()) return false;

    //     for(char i:s){
    //         smap[i]++;
    //     }
    //     for(char j:t){
    //         tmap[j]++;
    //     }

    //     return smap==tmap;
    // }

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s==t;
    }
};
