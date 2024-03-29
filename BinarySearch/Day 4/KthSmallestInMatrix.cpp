#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSmallerElementsThanMid(vector<int>& a, int target){
        int low = 0;
        int high = a.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(a[mid] <= target) low = mid + 1;

            else high = mid - 1;

        }


        return low;
    }

    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int low = a[0][0];
        int high = a[n-1][n-1];

        while(low <= high){
            int mid = low + (high-low)/2;

            int count = 0;
            for(int i = 0; i < n; i++){
                count += countSmallerElementsThanMid(a[i], mid);
            }

            if(count < k ) low = mid + 1;

            else high = mid - 1;
        }

        return low;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a = {{1,5,9},{10,11,13},{12,13,15}};
    cout<<s.kthSmallest(a, 8);
}