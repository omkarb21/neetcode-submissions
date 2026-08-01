class Solution {
public:
    int findSum(int n){
        int sum=0;
        int lastDigit=0;
        while(n>0){
            lastDigit=n%10;
            sum=sum+(lastDigit*lastDigit);
            n=n/10;
        }

        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int>seen;

        if(n==1) return true;
        else seen.insert(n);
        
        while(n!=1){
            //find sum
            n=findSum(n);

            //check if the number is in map & ADD
            if(seen.find(n)!=seen.end())return false;
            else seen.insert(n);

        }
        return true;
    }
};
