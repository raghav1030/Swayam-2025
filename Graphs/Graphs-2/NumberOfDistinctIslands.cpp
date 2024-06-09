//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int,int>> &v, int row0, int col0){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        v.push_back({row0 - row, col0 - col});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int mcol = col + dc[i];
            
            if(nrow >= 0 && nrow < n && mcol >= 0 && mcol < m && !visited[nrow][mcol] && grid[nrow][mcol] == 1){
                dfs(nrow, mcol, grid, visited, v, row0, col0);
            }
        }
         
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        set<vector<pair<int, int>>> st;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> v;
                    dfs(i, j, grid, visited, v, i, j);
                    st.insert(v);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends