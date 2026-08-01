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

        if(n==1) return true;

        int slow=n;
        int fast=n;
        
        int stepsNeedToTake=1;

        do{
            slow=fast;
            for(int i=0;i<stepsNeedToTake;i++){
                fast=findSum(fast);
                if(fast==1) return true;
            }
            stepsNeedToTake*=2;
            
        }
        while(slow!=fast);
        return false;
    }
};
