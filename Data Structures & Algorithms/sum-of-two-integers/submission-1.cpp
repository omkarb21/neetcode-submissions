class Solution {
public:
    int getSum(int a, int b) {
        int carry=0;

        int sum=a^b;
        carry=(a&b)<<1;
        while(carry!=0){
            int temp=sum;
            sum=sum^carry;
            carry=(temp&carry)<<1;
        }
        return sum;
    }
};
