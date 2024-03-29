#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        if(n1 > n2) return findMedianSortedArrays(b, a);

        int left = (n1 + n2)/2;
        int n = n1+n2;
        int low = 0;
        int high = n1;

        while(low <= high ){
            int mid1 = low + (high- low)/2;
            int mid2 = left - mid1;

            int l1 = INT_MIN; 
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1)  return min(r1, r2);
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            if(l1 > r2) high = mid1 - 1;
            if(l2 > r1) low = mid1 + 1;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << sol.findMedianSortedArrays(a, b) << endl;
    return 0;
}