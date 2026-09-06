class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int> (n));
        int minR = 0;
        int minC = 0;
        int maxR = n-1;
        int maxC = n-1;
        int count = 1;
        while(minR <= maxR && minC <= maxC){
            // Right
            for(int j = minC; j <= maxC; j++){
                arr[minC][j] = count++;
            }
            minR++;
            // Down
            for(int i = minR; i <= maxR; i++){
                arr[i][maxC] = count++;
            }
            maxC--;
            // Left
            for(int j = maxC; j >= minC; j--){
                arr[maxR][j] = count++;
            }
            maxR--;
            // Up
            for(int i = maxR; i >= minR; i--){
                arr[i][minC] = count++;
            }
            minC++;
        }
        return arr;
    }
};