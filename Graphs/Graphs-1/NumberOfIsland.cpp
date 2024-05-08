//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void dfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int i, int j){
      visited[i][j] = 1;
       int n = grid.size();
        int m = grid[0].size();
       for(int delRow = -1; delRow <=1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    int nRow = i + delRow;
                    int nCol = j + delCol;
                    
                    if((nRow >= 0 && nRow < n) && (nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && visited[nRow][nCol] == 0)){
                        visited[nRow][nCol] = 1;
                        dfs(grid, visited, nRow, nCol);
                    }
                }
            }
  }
  
   void bfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int i, int j){
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        q.push({i, j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            
            
            for(int delRow = -1; delRow <=1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    int nRow = row + delRow;
                    int nCol = col + delCol;
                    
                    if((nRow >= 0 && nRow < n) && (nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && visited[nRow][nCol] == 0)){
                        visited[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }

        }

    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row , vector<int>(col , 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++ ){
                if(visited[i][j] == 0 && grid[i][j] == '1') {
                    count++;
                    // dfs(grid, visited, i, j);
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends