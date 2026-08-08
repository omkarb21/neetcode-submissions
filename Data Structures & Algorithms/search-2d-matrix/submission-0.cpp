class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int s=0;
        int e=row*col-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            int i=mid/col;
            int j=mid%col;
            if(matrix[i][j]==target) return true;

            if(target>matrix[i][j]) s=mid+1;
            else e=mid-1;
        }

        return false;
    }
};
