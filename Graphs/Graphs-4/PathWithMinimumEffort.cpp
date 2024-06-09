//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> dist(rows, vector<int>(columns, INT_MAX));
        
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            auto top = pq.top();
            int diff = top.first;
            int r = top.second.first;
            int c = top.second.second;
        
            
            pq.pop();
            
            if(r == rows-1 && c == columns-1) return diff;
            
            for(int i = 0; i < 4; i++){
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns){
                    int newEffort = max(abs(heights[newRow][newCol] - heights[r][c]), diff);
                    
                    if(newEffort < dist[newRow][newCol]){
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
                
            }
            
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends