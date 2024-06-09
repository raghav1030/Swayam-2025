//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(int row, int col, vector<vector<char>> &temp, vector<vector<int>> &visited){
        visited[row][col] = 1;
        
        int n = temp.size();
        int m = temp[0].size();
        
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && temp[nrow][ncol] == 'O'){
                dfs(nrow, ncol, temp, visited);
            }
        }
        
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        vector<vector<char>> temp = mat;
        
        for(int j = 0; j < m; j++){
            if(temp[0][j] == 'O' && visited[0][j] == 0){
                dfs(0, j, temp, visited);
            }
            
            if(temp[n-1][j] == 'O' && visited[n-1][j] == 0){
                dfs(n-1, j, temp, visited);
            }
        }
        
        
        for(int i = 0; i < n; i++){
            if(temp[i][0] == 'O' && visited[i][0] == 0){
                dfs(i, 0, temp, visited);
            }
            
            if(temp[i][m-1] == 'O' && visited[i][m-1] == 0){
                dfs(i, m-1, temp, visited);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && temp[i][j] == 'O'){
                    temp[i][j] = 'X';
                }
            }
        }
        
        return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends