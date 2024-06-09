//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Disjoint{
    public:
    vector<int> size, rank, parent;

    Disjoint(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i < n ; i++){
            parent[i] = i;
        }

    }

    int findUltimateParent(int x){
        if(parent[x] == x) return x;

        else return parent[x] = findUltimateParent(parent[x]);
    }

    void unionByRank(int x, int y){
        int px = findUltimateParent(x);
        int py = findUltimateParent(y);

        if(px == py) return;

        if(rank[px] < rank[py]){
            parent[px] = py;
        } 
        else if(rank[px] > rank[py] ){
            parent[py] = px;
        }

        else{
            parent[py] = px;
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

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjoint d(n*m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // int visited[n][m];
        //  memset(visited, 0, sizeof visited);
        int count = 0;
        
        vector<int> ans;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            if(visited[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            
            visited[row][col] = 1;
            count++;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m ){
                
                    if( visited[newRow][newCol] == 1){
                        
                        int currentNodeNumber = row * m + col;
                        int newNodeNumber = newRow * m + newCol;
                 
                        if(d.findUltimateParent(currentNodeNumber) != d.findUltimateParent(newNodeNumber)){
                            count--;
                            d.unionBySize(currentNodeNumber, newNodeNumber);
                        }
                    }
                }
                
            }
            ans.push_back(count);
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends