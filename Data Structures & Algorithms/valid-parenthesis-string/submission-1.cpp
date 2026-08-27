class Solution {
public:
    bool checkValidString(string s) {
        int leftbrackets=0;
        int maxLeft=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                leftbrackets+=1;
                maxLeft+=1;
            }
            else if(s[i]==')'){
                leftbrackets=leftbrackets-1;
                maxLeft=maxLeft-1;
            }
            else{
                leftbrackets=leftbrackets-1;
                maxLeft=maxLeft+1;

            }

            if(maxLeft<0) return false;
            if(leftbrackets<0)leftbrackets=0;
        }

        return leftbrackets==0;
    }
};
