//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs( vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int initialColor, int sr,int  sc, vector<int> &delRow, vector<int> &delCol){
        ans[sr][sc] = newColor;
        int n = ans.size();
        int m = ans[0].size();
        
        for(int i = 0; i < 4; i++){
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && ans[nRow][nCol] != newColor && image[nRow][nCol] == initialColor){
                // ans[nRow][nCol] = newColor;
                dfs(image, ans, newColor, initialColor, nRow, nCol, delRow, delCol);
            }
            
        }
    }
    
    void bfs( vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int initialColor, int sr,int  sc, vector<int> &delRow, vector<int> &delCol){
        ans[sr][sc] = newColor;
        int n = ans.size();
        int m = ans[0].size();
        
        queue<pair<int,int>> q;
        
        q.push({sr, sc});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && ans[nRow][nCol] != newColor && image[nRow][nCol] == initialColor){
                ans[nRow][nCol] = newColor;
                q.push({nRow, nCol});
            }
            
        }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        
        // vector<vector<int>> visited(n , vector<int>(m, 0));
        vector<vector<int>> ans = image;
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0,1,0,-1};
        
        int initialColor = ans[sr][sc];
        
        bfs(image, ans, newColor, initialColor, sr, sc, delRow, delCol);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends