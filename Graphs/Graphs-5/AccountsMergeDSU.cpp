//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        unordered_map<string, int> mapMailNode;
        Disjoint d(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    d.unionBySize(i, mapMailNode[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n];
        
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = d.findUltimateParent(it.second);
            
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0) continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends