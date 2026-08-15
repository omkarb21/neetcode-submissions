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
    bool isValidSquare(int currX,int currY, vector<vector<char>>&board,vector<int>&mp1,vector<int>&mp2,vector<int>&mp3){
         
         int n=board.size();

        if(mp1[currX]==1 ||  mp2[currX-currY+n-1]==1 || mp3[currY+currX]==1){
            return false;
        }


         return true;

    }


    void recQueens(vector<vector<string>>& ans, int currX, int currY, vector<vector<char>>&board,int n,vector<int>&mp1,vector<int>&mp2,vector<int>&mp3){
        if(currY>=n){
            storeAns(board,ans);
            return;
        }

        for(int i=0;i<n;i++){
            currX=i;
            if(isValidSquare(currX,currY,board,mp1,mp2,mp3)){
                board[currX][currY]='Q';
                mp1[currX]=1;
                mp2[currX-currY+n-1]=1;
                mp3[currY+currX]=1;
                recQueens(ans,currX,currY+1,board,n,mp1,mp2,mp3);
                board[currX][currY]='.';
                mp1[currX]=0;
                mp2[currX-currY+n-1]=0;
                mp3[currY+currX]=0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int currX=0;
        int currY=0;
        vector<int>mp1(n,0),mp2(2*n-1,0),mp3(2*n-1,0);
        recQueens(ans,currX,currY,board,n,mp1,mp2,mp3);
        return ans;
    }
};
