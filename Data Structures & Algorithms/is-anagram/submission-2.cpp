class Solution {
public:
    bool isAnagram(string s, string t) {
    //     //brute force
    //     unordered_map<char,int>st1;
    //     unordered_map<char,int>st2;
    //     for(char c:s){
    //         st1[c]++;
    //     }

    //     for(char c:t){
    //         st2[c]++;
    //     }

    //     return st1==st2;

    // }

    //approach 2
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s==t;
    }
};
