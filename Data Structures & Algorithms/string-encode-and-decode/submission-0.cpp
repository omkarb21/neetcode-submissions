class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for(string word:strs){
            int wordLength=word.length();
            string temp=to_string(wordLength)+'#';
            word=temp+word;
            result+=word;
            
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string>res;
        
        int i=0;
        while(i<s.length()){
            string tempNumber="";
            
            while(s[i]!='#'){
                tempNumber+=s[i];
                i++;
            }
            i++;
            int count=stoi(tempNumber);
            string temp="";
            while(count>0){
                temp+=s[i];
                count--;
                i++;

            }
            res.push_back(temp);


            }

            return res;
        
    }
};
