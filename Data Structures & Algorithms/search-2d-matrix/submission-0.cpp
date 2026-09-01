class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int m = matrix.size();
        // int n = matrix[0].size();
        // int row = 0, col = n-1;

        // while(row <= m-1 && col >= 0){
        //     int curr = matrix[row][col];
        //     if(curr == target) return true;
        //     if(curr < target) row++;
        //     else col--;
        // }
        // return false;



        // Best Approach(TC--> 0(log(m*n)))

        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0, hi=m*n-1;

        while(lo <= hi){
            int mid = (lo+hi)/2;
            int row = mid/n, col = mid%n;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) hi = mid-1;
            else lo = mid + 1;
        }
        return false;
    }
};
