class Solution {
public:
    double myPow(double x, int n) {
        
        int temp=abs(n);
        double res=1;
        if(n==0)return res;

        while(temp>0){
            res*=x;
            temp--;
        }

        if(n<0)return 1/res;
        else return res;
    }
};
