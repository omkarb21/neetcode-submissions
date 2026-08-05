class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i<j){
                    int temp=matrix[j][i];
                    matrix[j][i]=matrix[i][j];
                    matrix[i][j]=temp;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            int l=0;
            int r=matrix[0].size()-1;
            while(l<r){
                int temp2=matrix[i][l];
                matrix[i][l]=matrix[i][r];
                matrix[i][r]=temp2;
                l++;
                r--;
            }
        }


    }
};
