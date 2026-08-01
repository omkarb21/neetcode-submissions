class Solution {
public:
    double binaryCal(double x, int n ){
        if(n==0) return 1;

        double res=binaryCal(x,n/2);
        return (n%2==0)? res*res: x*res*res;
    }
    double myPow(double x, int n) {
        if(n==0) return 1;

        double ans=binaryCal(x,abs((long)(n)));
        
        return (n>0)? ans: 1/ans;
    }
};
