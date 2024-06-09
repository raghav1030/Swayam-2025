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
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        Disjoint d(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            d.unionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int count = 0;
        for(auto it : stoneNodes){
            if(d.findUltimateParent(it.first) == it.first){
                count++;
            }
        }

        return n - count;

    }
};