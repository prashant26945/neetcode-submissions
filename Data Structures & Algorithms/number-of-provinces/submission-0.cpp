class Solution {
public:
    void dfs(vector<vector<int>> &adjList, vector<int> &vis, int i){
        vis[i] = 1;
        for(auto it: adjList[i]){
            if(!vis[it]){
                dfs(adjList, vis, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] == 1){
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adjList, vis, i);
            }
        }
        return cnt;
        
    }
};