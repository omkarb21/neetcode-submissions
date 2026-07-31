class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //get the binary representation
        string binary="";
        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                binary+='1';
            }
            else binary+='0';

        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(binary[31-i]=='1'){
                ans=ans | (1<<i);
            }
            
        }
        return ans;
    }
};
