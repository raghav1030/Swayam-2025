#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
void dfs(int node, vector<bool> &visited, vector<vector<int>>& isConnected){
      visited[node] = true;
    //   ls.push_back(node);
      
      for(int i = 0; i < isConnected[node].size(); i++){
        if(isConnected[node][i] == true && visited[i] == false){
            dfs(i, visited, isConnected);
        }
      }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <bool> visited(isConnected.size(), false);
        int count = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(visited[i] == false){
                count++;
                dfs(i, visited, isConnected);
            }
        }   
        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V, vector<int>(V, 0));

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        Solution obj;
        cout << obj.findCircleNum(adj) << endl;
    }
    return 0;
}