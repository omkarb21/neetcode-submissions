class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>,vector<string>>mp;

        for(string word:strs){

            vector<int> count(26, 0);
            for(char c:word){
                

                count[int(c)-int('a')]+=1;
            }

            mp[count].push_back(word);
        }

        for(auto entry:mp){
            result.push_back(entry.second);
        }
        return result;
    }
};
