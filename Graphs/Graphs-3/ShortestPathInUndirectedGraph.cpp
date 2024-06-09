//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int> adj[N];
        
        for(int i = 0; i < M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        vector<int> distance(N, INT_MAX);
        distance[src] = 0;
        q.push(src);
        
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto it : adj[front]){
                if(distance[front] + 1 < distance[it]){
                distance[it] = min(distance[it], distance[front] + 1 );
                q.push(it);
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(distance[i] == INT_MAX) {
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends