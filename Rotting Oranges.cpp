//TC: O(NxM + NxMx4) ~ O(N x M), For the worst case, all of the cells will have fresh oranges, so the BFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbours, it will take O(N x M x 4) time.
//SC : O(N x M), O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1)fresh++;
            }
        }
        vector<int> dir{0, -1, 0, 1, 0};
        int maxTime = 0, cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            maxTime = max(t, maxTime);
            
            for(int i = 0; i < 4; i++){
                int nrow = r + dir[i];
                int ncol = c + dir[i + 1];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != fresh) return -1;
        return maxTime;
    }
};
