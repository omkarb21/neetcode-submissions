class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arrS1[26]={0};
        int arrS2[26]={0};

        if(s1.length()>s2.length()) return false;

        for(int i=0;i<s1.length();i++){
            arrS1[s1[i]-'a']++;
            arrS2[s2[i]-'a']++;
            
        }
        int matches=0;
        int i=0;
        while(i<26){
            if(arrS1[i]==arrS2[i]) matches++;
            i++;

        }

        if(matches==26) return true;
        int l=0;
        for(int r=s1.length();r<s2.length();r++){
            arrS2[s2[r]-'a']++;
            if(arrS2[s2[r]-'a']==arrS1[s2[r]-'a']) matches++;
            else if(arrS2[s2[r]-'a']==arrS1[s2[r]-'a']+1) matches--;

            arrS2[s2[l]-'a']--;
            if(arrS2[s2[l]-'a']==arrS1[s2[l]-'a']) matches++;
            else if(arrS2[s2[l]-'a']+1==arrS1[s2[l]-'a']) matches--;
            if(matches==26) return true;

            l++;
        }

        return false;



        
    }
};
