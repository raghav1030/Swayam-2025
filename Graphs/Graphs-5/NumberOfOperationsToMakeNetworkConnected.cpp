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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint d(n);
        int cntExtra = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(d.findUltimateParent(u) == d.findUltimateParent(v)){
                cntExtra++;
            }
            else {
                d.unionByRank(u, v);
            }
        }

        int cntComponents = 0;
        for(int i = 0; i < n; i++){
            if(d.parent[i] == i) cntComponents++;
        }

        if(cntExtra >= cntComponents - 1) return cntComponents - 1;
        else return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout << s.makeConnected(6, connections) << endl;
    return 0;
}