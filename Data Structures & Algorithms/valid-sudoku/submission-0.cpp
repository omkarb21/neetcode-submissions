class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>>rows;
        unordered_map<int,unordered_set<char>>cols;
        unordered_map<int,unordered_set<char>>boxes;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char currChar=board[i][j];
                if(currChar=='.') continue;
                int boxkey=(i/3)*3+(j/3);
                if(rows[i].count(currChar) || cols[j].count(currChar)|| boxes[boxkey].count(currChar)) return false;

                rows[i].insert(currChar);
                cols[j].insert(currChar);
                boxes[boxkey].insert(currChar);
            }
        }

        return true;
    }
};
