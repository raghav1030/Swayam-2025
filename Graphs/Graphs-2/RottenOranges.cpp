#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n , vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j  < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int time = 0;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0,1,0,-1};


        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;

            time = max(tm, time);

            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && visited[nRow][nCol] != 2){
                visited[nRow][nCol] = 2;
                q.push({{nRow, nCol}, tm+1});
            }

            }
            

        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }
        return time;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.orangesRotting(grid) << endl;
    }
    return 0;
}