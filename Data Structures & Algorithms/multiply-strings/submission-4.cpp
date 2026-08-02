class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> resInt(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = (num1[i] - '0') * (num2[j] - '0');

                int unitsIdx = i + j + 1;   // less significant slot
                int carryIdx = i + j;       // one place more significant

                
                resInt[unitsIdx] += ans % 10;
                resInt[carryIdx] += ans / 10;
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
