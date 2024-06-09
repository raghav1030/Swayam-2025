//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<pair<int, int>> adj[]){
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it.first]){
                dfs(it.first, visited, st, adj);
            }
        }
        st.push(node);
    }
    void topo(stack<int> &st, vector<pair<int, int>> adj[], int N){
        vector<int> visited(N, 0);

        
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                dfs(i, visited, st, adj);
            }
        }
    }
    
    
//      void dfs(int node, vector<int> &visited,  vector<pair<int, int>> adj[], stack<int> &st){
//         visited[node] = 1;
        
//         for(auto it : adj[node]){
//             if(!visited[it.first]){
//                 dfs(it.first, visited, adj, st);
//             }
//         }
        
//         st.push(node);
//     }
    
//     stack<int>  topoSort(int V,  vector<pair<int, int>> adj[]) 
// 	{
// 	    vector<int> visited(V, 0);
	    
// 	    stack<int> st;
	    
// 	    for(int i = 0; i < visited.size(); i++){
// 	        if(!visited[i]){
// 	            dfs(i, visited, adj, st);
// 	        }
// 	    }
// 	    return st;
// 	}
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        
        for(int i = 0; i < M; i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int weight = edges[i][2];
            
            adj[src].push_back({dest, weight});
        }
        
        
        // stack<int> st = topoSort(N, adj);
        stack<int> st;
        topo(st, adj, N);
        
        vector<int> distance(N, INT_MAX);
        
        distance[0] = 0;
        // st.pop();
        
        
        
        while(!st.empty()){
            int top = st.top();
            // cout << top << endl;
            st.pop();
            if(distance[top] != INT_MAX){
            for(auto it : adj[top]){
                // if(distance[top] + it.second < distance[it.first]){
                //     distance[it.first] = distance[top] + it.second;
                // }
                distance[it.first] = min(distance[it.first], distance[top] + it.second);
            }
        }
            
        }
        
        for(int i = 0; i < N; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends