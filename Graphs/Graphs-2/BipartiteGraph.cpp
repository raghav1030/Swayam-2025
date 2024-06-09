//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int start,vector<int>adj[], vector<int> &colored){
        
	    
	    queue<int> q;

	    
	   // colored[adj[0]] = 0;
	    q.push(start);
        colored[start] = 0;
        
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
            for(auto it : adj[node]){
                if(colored[it] == -1){
                    colored[it] = !colored[node];
                    q.push(it);
                }
                else if(colored[it] == colored[node]){
                    return false;
                }
            }
	    }
	    
	    return true;
    }
    
    bool checkDFS(int start,vector<int>adj[], vector<int> &colored, int color){
        colored[start] = color;
        
        for(auto it : adj[start]){
            if(colored[it] == -1){
                if(checkDFS(it, adj, colored, !color) == false) return false;
            }
            else if(colored[it] == colored[start]){
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colored(V, -1);
	    for(int i = 0; i < V; i++){
	        if(colored[i] == -1){
	           // if(check(i, adj, colored) == false){
	           //     return false;
	           // }
	           if(checkDFS(i, adj, colored, 0) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends