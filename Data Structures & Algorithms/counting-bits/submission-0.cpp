class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>res(n+1,0);
        while(n>0){
            int temp=n;
            int count=0;
            while(temp>0){
                if(temp & 1)count++;
                temp=temp>>1;
            }
            res[n]=count;
            n--;
        }

        return res;
    }
};
