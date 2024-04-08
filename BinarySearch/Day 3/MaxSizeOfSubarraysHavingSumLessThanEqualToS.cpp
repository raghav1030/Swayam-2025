#include<iostream>
#include<vector>

using namespace std;

bool checkFunc(vector<int> a, int n, int maxSize, int maxSum){
    int sum = 0;

    int i = 0;
    int j = 0;

    while(j < n){
        sum += a[j];

        if(j-i+1 < maxSize) j++;

        else if(j-i+1 == maxSize){
            if(sum > maxSum) return false;

            sum -= a[i];
            i++;
        j++;
        } 

    }

    return true;
}

int LengthOfSubarrayWithSumLessThanEqualToS(vector<int> a, int n, int s){
    int low = 1;
    int high = n;
    int ans = 0;

    while(low <= high){
        int mid = low + (high-low)/2;

        bool isValid = checkFunc(a, n,mid, s);

        if(isValid) {
            ans = mid;
            low = mid + 1;
        }
            
            else high = mid - 1;
    }

    return ans;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    int s = 11;
    cout << LengthOfSubarrayWithSumLessThanEqualToS(a, n, s);
    return 0;
}