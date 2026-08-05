class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>dup(matrix.size(),vector<int>(matrix[0].size(),0));
        int n=matrix.size();

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dup[j][n-1-i]=matrix[i][j];
            }
        }

        matrix=dup;

    }
};
