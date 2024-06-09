#include<bits/stdc++.h>
#include<vector>
using namespace std;


class Disjoint{
  public:
  vector<int> rank, size, parent;
  
  Disjoint(int n){
      rank.resize(n+1, 0);
      size.resize(n+1, 1);
      parent.resize(n+1);
      
      for(int i = 0; i <= n; i++){
          parent[i] = i;
      }
  }
  
  int findUltimateParent(int v){
      if(parent[v] == v) return v;
      
      else return parent[v] = findUltimateParent(parent[v]);
  }
  
  void unionByRank(int x, int y){
      int px = findUltimateParent(x);
      int py = findUltimateParent(y);
      
      if(px == py) return;
      if(rank[px] < rank[py]){
          parent[px] = py;
      }
      else if(rank[py] < rank[px]){
          parent[py] = px;
      }
      else{
          parent[px] = py;
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





class Disjoint{
  public:
  vector<int> size, rank, parent;
  
  Disjoint(int n){
      parent.resize(n+1);
      rank.resize(n+1, 0);
      size.resize(n+1, 1);
      
      for(int i = 0; i <= n; i++){
          parent[i] = i;
      }
  }
  
  int findUltimateParent(int x){
      if(parent[x] = x) return x;
      
      else return parent[x] = findUltimateParent(parent[x]);
  }
  
  void unionByRank(int x, int y){
      int px = findUltimateParent(x);
      int py = findUltimateParent(y);
  
      if(px == py){
          return;
      }
      
      if(rank[px] < rank[py]){
          parent[px] = py;
          rank[py]++;
      }
      else if(rank[py] < rank[px]){
          parent[py] = px;
          rank[px]++;
      }
      
      else{
          parent[px] = py;
          rank[py]++;
      }
  }
  void unionBySize(int x, int y){
      int px = findUltimateParent(x);
      int py = findUltimateParent(y);
  
      if(px == py){
          return;
      }
      
      if(size[px] < size[py]){
          parent[px] = py;
          size[py]+= size[px];
      }
      else if(size[py] < size[px]){
          parent[py] = px;
          size[px] += size[py];
      }
      
      else{
          parent[px] = py;
          size[py] += size[px];
      }
  }
};
