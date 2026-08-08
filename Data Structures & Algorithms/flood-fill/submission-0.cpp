class Solution {
public:
    void dfs(int initialColor, int row, int col, vector<vector<int>> &image, int color, vector<vector<int>> &ans){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        vector<pair<int, int>> dir = {
            {-1, 0}, //up
            {0, 1},  //right
            {1, 0},  // down
            {0, -1}  // left
        };
        for(auto it: dir){
            int nr = row + it.first;
            int nc = col + it.second;

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initialColor && ans[nr][nc] != color){
                ans[nr][nc] = color;
                dfs(initialColor, nr, nc, image, color, ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(initialColor, sr, sc, image, color, ans);
        return ans;
    }
};