class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string temp="";
        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                temp+='1';
            }
            else{
                temp+='0';
            }
        }
        int ans=0;

        for(int j=0;j<32;j++){
            if(temp[31-j]=='1'){
                ans=ans|(1<<j);
            }
        }

        return ans;


    }
};
