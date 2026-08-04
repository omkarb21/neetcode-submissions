class Solution {
public:
    bool isPalindrome(string s) {
        
        int l=0;
        int r=s.length()-1;

        while(l<r){
            while(l<r && !alphanum(s[l])){
                l++;
            }
            while(l<r && !alphanum(s[r])){
                r--;
            }

            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }

        return true;



    }

    bool alphanum(char s){
        return (s>='a'&& s<='z' || s>='A'&& s<='Z' || s>='0' && s<='9');
    }
};
