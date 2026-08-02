class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size()+num2.size();
        vector<int>resInt(n,0);

        for(int i=num2.size()-1;i>=0;i--){
            for(int j=num1.size()-1;j>=0;j--){
                int res=(num2[i]-'0')*(num1[j]-'0');
                int digit=res%10;
                int carry=res/10;

                resInt[(n-1)-((num2.size()-1-i)+(num1.size()-1-j))]+=digit;
                resInt[(n-1)-((num2.size()-1-i)+(num1.size()-1-j))-1]+=carry;

            }
        }

        for(int idx=resInt.size()-1;idx>=1;idx--){
            int carr=resInt[idx]/10;
            resInt[idx]=resInt[idx]%10;
            resInt[idx-1]+=carr;
        }

        string result="";
        
        int i=0;
        for(int num:resInt){
            if(num==0)i++;
            else{
                break;
            }
        }
        if(i==resInt.size()) return "0";
        while(i<resInt.size()){
            result+=char('0'+resInt[i]);
            i++;
        }





        return result;
        
    }
};
