//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfsToSortComponents(int node, vector<int> &visited, vector<vector<int>> adj, stack<int> &st){
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfsToSortComponents(it, visited, adj, st);
            }
        }
        st.push(node);
    }
    
    void dfsTraversal(int node, vector<int> &visited, vector<int> adj[]){
         visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfsTraversal(it, visited, adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsToSortComponents(i, visited, adj, st);
            }
        }
        
        vector<int> adjT[V];
        
        for(int i = 0; i < V; i++){
            visited[i] = 0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int cnt = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                cnt++;
                dfsTraversal(node, visited, adjT);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends