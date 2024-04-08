#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int CountElementsLessThanEqualToMid(vector<int> row, int upperBound){
    int low = 0; 
    int high = row.size()-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(row[mid] <= upperBound) low = mid + 1;

        else high = mid - 1;
    }

    return low;
}

int median(vector<vector<int>> &a, int m, int n) {
    // Write your code here.
    int low = INT_MAX;
    int high = INT_MIN;

    for(int i = 0; i < m; i++){
        if(a[i][0] < low) low = a[i][0];

        if(a[i][n-1] > high) high = a[i][n-1];
    }

    while(low <= high){
        int mid = low + (high-low)/2;
        int count = 0;

        for(int i = 0; i < m; i++){
            count += CountElementsLessThanEqualToMid(a[i], mid);
        }

        if(count < ((n*m+1)/2)) low = mid + 1;

        else high = mid - 1;
    }

    return low;
}

int main(){
    vector<vector<int>> a = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    int m = 3;
    int n = 3;
    cout << median(a, m, n) << endl;
    return 0;
}