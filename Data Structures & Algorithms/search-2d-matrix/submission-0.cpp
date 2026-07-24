class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //flattening 2d-->1d: i = row*numCols + col
        //row = i/numCols, col = i%numCols

        int numCols = matrix[0].size(), numRows = matrix.size();
        int l = 0, r = numCols*numRows - 1;

        while(l<=r){
            int mid = (l+r)/2;
            int row = mid/numCols, col = mid%numCols;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }
};
