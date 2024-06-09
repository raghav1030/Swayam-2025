#include <bits/stdc++.h>
using namespace std; 

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
private:
    bool isValid(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        Disjoint d(n*m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for(int dir = 0; dir < 4; dir++){
                    int nrow = i + dr[dir];
                    int ncol = j + dc[dir];
                    if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1){
                        int currentNode = i * m + j;
                        int newNode = nrow * m + ncol;
                        d.unionBySize(currentNode, newNode);
                    }
                }
            }
        }

        int maxSize = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                
                unordered_set<int> components;
                for(int dir = 0; dir < 4; dir++){
                    int nrow = i + dr[dir];
                    int ncol = j + dc[dir];
                    if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1){
                        components.insert(d.findUltimateParent(nrow * m + ncol));
                    }
                }

                int size = 0;
                for(auto it : components){
                    size += d.size[it];
                }

                maxSize = max(maxSize, size+1);
            }
        }
        for(int i = 0; i < n*n; i++){
            maxSize = max(maxSize, d.size[d.findUltimateParent(i)]);
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0 ; j < m; j++){
        //         maxSize = max(maxSize, d.size[d.findUltimateParent(i * m + j)]);
        //     }
        // }

        return maxSize;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    Solution s;
    cout << s.largestIsland(grid) << endl;
    return 0;
}