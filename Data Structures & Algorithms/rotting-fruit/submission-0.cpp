class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // {{row, col}, time}
        queue<pair<pair<int, int>, int> > q;
        vector<vector<int>> vis(n, vector<int> (m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        int time = 0;
        vector<pair<int,int>> dir = {
            {-1, 0},  // up
            {0, 1},   // right
            {1, 0},   // down
            {0, -1}   // left
        };
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for(auto it: dir){
                int nr = r + it.first;
                int nc = c + it.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 && grid[nr][nc] == 1){
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
