class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;

        vector<vector<int>> adj(n);
        for(auto &c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<int> vis(n, 0);
        int components = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                components++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto &nei : adj[node]){
                        if(!vis[nei]){
                            vis[nei] = 1;
                            q.push(nei);
                        }
                    }
                }
            }
        }

        return components - 1;
    }
};