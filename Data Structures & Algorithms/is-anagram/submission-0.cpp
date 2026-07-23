class Solution {
public:
    bool isAnagram(string s, string t) {
        //brute force
        unordered_map<char,int>st1;
        unordered_map<char,int>st2;
        for(char c:s){
            if(st1.find(c)!=st1.end()){
                st1[c]++;
                
            }
            else st1[c]=1;
        }

        for(char c:t){
            if(st2.find(c)!=st2.end()){
                st2[c]++;
                
            }
            else st2[c]=1;
        }

        return st1==st2;
        



    }
};
