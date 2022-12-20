//TC : O(n^2) n = v(number of node)
//SC : O(n) A queue and visited array of size n is used.
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited(v, 0);
        int count = 0;
        queue<int>q;
        for (int i = 0; i < v; i++) {
            if (visited[i] == 0) {
                q.push(i);

                while (!q.empty()) {
                    int s = q.front();
                    q.pop();
                    visited[s] = 1;
                    for (int j = 0; j < v; j++) {
                        if (visited[j] == 0 && isConnected[s][j] == 1)
                            q.push(j);
                    }
                }
                count++;
            }
        }
        return count;
    }
};
