//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
  public:
  vector<int> rank, size, parent;
  
  Disjoint(int n){
      rank.resize(n+1, 0);
      size.resize(n+1, 1);
      parent.resize(n+1);
      
      for(int i = 0; i <= n; i++){
          parent[i] = i;
      }
  }
  
  int findUltimateParent(int v){
      if(parent[v] == v) return v;
      
      else return parent[v] = findUltimateParent(parent[v]);
  }
  
  void unionByRank(int x, int y){
      int px = findUltimateParent(x);
      int py = findUltimateParent(y);
      
      if(px == py) return;
      if(rank[px] < rank[py]){
          parent[px] = py;
      }
      else if(rank[py] < rank[px]){
          parent[py] = px;
      }
      else{
          parent[px] = py;
          rank[px]++;
      }
  }
  
  void unionBySize(int x, int y){
      int px = findUltimateParent(x);
      int py = findUltimateParent(y);
      
      if(px == py) return;
      if(size[px] < size[py]){
          parent[px] = py;
          size[py] += size[px];
      }
      else{
          parent[py] = px;
          size[px] += size[py];
      }
  }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        Disjoint d(V);
        
        int mst = 0;
        for(auto it : edges){
            int wt = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;
            // cout << " ultimate parent of node --->>> " << d.findUltimateParent(node) << endl;
            // cout << " ultimate parent of adjNode --->>> " << d.findUltimateParent(adjNode) << endl;
            if(d.findUltimateParent(node) != d.findUltimateParent(adjNode)){
             mst += wt;
             d.unionByRank(node, adjNode);
            }
        }
        
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends