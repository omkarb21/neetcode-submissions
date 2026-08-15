class Solution {
public:
    void storeAns(vector<vector<char>>& board,vector<vector<string>>& ans){
        int n=board.size();
        vector<string>output;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=board[i][j];

            }
            output.push_back(temp);
        }
        ans.push_back(output);
    }
    bool isValidSquare(int currX,int currY, vector<vector<char>>&board){
         int n=board.size();
         int y=currY-1;
         while(y>=0){
            if(board[currX][y]=='Q') return false;
            y--;
         }
         int x=currX-1;
         y=currY-1;
         while(x>=0 && y>=0){
            if(board[x][y]=='Q') return false;
            x--;
            y--;
         }
        
         x=currX+1;
         y=currY-1;           
         while(x<n && y>=0){
            if(board[x][y]=='Q') return false;
            x++;
            y--;

         }
         return true;

    }


    void recQueens(vector<vector<string>>& ans, int currX, int currY, vector<vector<char>>&board,int n){
        if(currY>=n){
            storeAns(board,ans);
            return;
        }

        for(int i=0;i<n;i++){
            currX=i;
            if(isValidSquare(currX,currY,board)){
                board[currX][currY]='Q';
                recQueens(ans,currX,currY+1,board,n);
                board[currX][currY]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int currX=0;
        int currY=0;
        recQueens(ans,currX,currY,board,n);
        return ans;
    }
};
