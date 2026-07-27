class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longest_seq_len=0;
        unordered_set<int>mp;


        for(auto temp:nums){
            mp.insert(temp);
        }

        //aboev thing of puttitng elements in set coudl be done using-->
        //unordered_set<int> mp(nums.begin(), nums.end()); // dedupe directly on construction


        for(int num:nums){
            int currentSeqLen=1;
            if(mp.find(num-1)!=mp.end()) continue;
            else if(mp.find(num+1)!=mp.end())
            {
                currentSeqLen++;
                int temp=num+1;
                while(true){
                    if(mp.find(temp+1)!=mp.end()){
                        temp++;
                        currentSeqLen++;
                    }
                    else break;
                }

                

            }
            if(currentSeqLen>longest_seq_len) longest_seq_len=currentSeqLen;
        }

        return longest_seq_len;
    }
};
