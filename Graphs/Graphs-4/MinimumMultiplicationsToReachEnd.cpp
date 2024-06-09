//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        q.push({start, 0});
        vector<int> distance(100000, 1e9);
        distance[start] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int multiplications = it.second;
            
            q.pop();
            
            if(node == end) return multiplications;
            
            for(int i = 0; i < arr.size(); i++){
                int num = (arr[i] * node)%100000;
                // cout << num << endl;
                if(multiplications + 1 < distance[num]){
                    distance[num] = multiplications + 1;
                    if(num == end) return distance[num];
                    q.push({num, distance[num]});
                }
                
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends