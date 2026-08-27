class Solution {
public:
    bool checkValidString(string s) {
        int runningStatus=0;
        int maxLeft=0;
        for(auto c:s){
            if(c=='('){
                runningStatus+=1;
                maxLeft+=1;
            }
            else if(c==')'){
                runningStatus=runningStatus-1;
                maxLeft=maxLeft-1;
            }else{
                runningStatus=runningStatus-1;
                maxLeft+=1;
            }
            if(maxLeft<0) return false;

            if(runningStatus<0) runningStatus=0;

        }

        if(runningStatus==0) return true; else return false;





    }
};
