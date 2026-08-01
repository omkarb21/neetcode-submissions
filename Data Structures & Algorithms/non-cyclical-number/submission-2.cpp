class Solution {
public:
    int findSum(int n){
        int sum=0;
        int lastDigit=0;
        while(n>0){
            lastDigit=n%10;
            sum+=(lastDigit*lastDigit);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum=0;
        int slow=n;
        int fast=n;
        while(fast!=1){
            slow=findSum(slow);
            fast=findSum(findSum(fast));
            if(slow==fast && slow!=1) return false;
        }
        return true;
    }
};
