class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minR = 0, minC = 0;
        int maxR = m-1, maxC = n-1;
        vector<int> v;
        while(minR <= maxR && minC <= maxC){
            //right
            for(int j = minC; j <= maxC; j++){
                v.push_back(matrix[minR][j]);
            }
            minR++;
            if(minR > maxR || minC > maxC) break;

            //Down
            for(int  i = minR; i <= maxR; i++){
                v.push_back(matrix[i][maxC]);
            }
            maxC--;
            if(minR > maxR || minC > maxC) break;

            // left
            for(int j = maxC; j >= minC; j--){
                v.push_back(matrix[maxR][j]);
            }
            maxR--;
            if(minR > maxR || minC > maxC) break;

            // top
            for(int i = maxR; i >= minR; i--){
                v.push_back(matrix[i][minC]);
            }
            minC++;
        }
    return v;
    }
};
