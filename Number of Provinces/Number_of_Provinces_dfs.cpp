//TC : O(n^2) n = v(number of node)
//SC : O(n)
class Solution {
private:
    void traverse(int i, vector<int>&vis, vector<vector<int>> &isConnected){
        vis[i] = 1;
        for(int j = 0; j < isConnected.size(); j++){
            if(vis[j] == 0 && isConnected[i][j] == 1){
                traverse(j, vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int provinces = 0;
        vector<int> vis(v, 0);

        for(int i = 0; i < v; i++){
            if(vis[i] == 0){
                provinces++;
                traverse(i, vis, isConnected);
            }
        }
        return provinces;
    }
};
