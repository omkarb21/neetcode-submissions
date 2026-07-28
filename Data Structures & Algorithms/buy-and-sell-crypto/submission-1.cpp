class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int left=0;
        int right=1;

        while(right<prices.size()){
            int currProfit=0;
            if(prices[right]>prices[left]){
                currProfit=prices[right]-prices[left];
                maxProfit=max(maxProfit,currProfit);
                
            }
            else{
                left=right;
                
            }
            right++;
        }

        return maxProfit;
    }
};
