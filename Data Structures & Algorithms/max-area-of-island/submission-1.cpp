class Solution {
public:
    int bfs(vector<vector<int>> &vis, int row, int col, vector<vector<int>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});

        vector<pair<int,int>> dir = {
            {-1, 0},  // up
            {0, 1},   // right
            {1, 0},   // down
            {0, -1}   // left
        };

        int cnt = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto it: dir){
                int nr = r + it.first;
                int nc = c + it.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int maxi = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    int area = bfs(vis, row, col, grid);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
