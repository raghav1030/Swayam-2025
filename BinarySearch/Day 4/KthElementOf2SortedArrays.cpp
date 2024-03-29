#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int n, int m, int k){
    // Write your code here
    if(n > m) return kthElement(b, a, m, n, k);

    int low = max(0, k-m);
    int high = min(k , n);

    while(low <= high){
        int mid1 = low + high >> 1;
        int mid2 = k - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n) r1 = a[mid1];
        if(mid2 < m) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1 ){
             return max(l1, l2);
            
        }

        else if(l1 > r2) high = mid1 - 1;

        else if(l2 > r1) low = mid1 + 1;
    }
    return 0;

}

int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int n = 5;
    int m = 4;
    int k = 5;
    cout << kthElement(a, b, n, m, k) << endl;
    return 0;
}