//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[], vector<int> &check){
      visited[node] = 1;
      pathVisited[node] = 1;
      
      check[node] = 0;
      
      for(auto it : adj[node]){
          if(!visited[it]){
              if(dfs(it, visited, pathVisited, adj, check) == true) {
                  check[it] = 0;
                  return true;
              }
          }
          
          else if(pathVisited[it]){
              check[it] = 0;
              return true;
          }
      }
      
      pathVisited[node] = 0;
      check[node] = 1;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        
        vector<int> check(V, 0);
        vector<int> safeState;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited, pathVisited, adj, check);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(check[i] == 1) safeState.push_back(i);
        }
        
        return safeState;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends