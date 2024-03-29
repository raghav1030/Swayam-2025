
#include <bits/stdc++.h>

using namespace std;

bool isValidBooks(vector<int> &a, vector<int> &b, int books, int n, int m, int maxTime ){
    int i = 0;
    int j = 0;
    int currTime = 0;
    bool flag = true;
    
    while(i<n && j <m){
        if(a[i] < b[j]){
            if(currTime+a[i] <= maxTime){
                currTime += a[i];
                i++;
            }
            else {
             flag = false;
                break;
            }
        }
        else {
            
            if(currTime+b[j] <= maxTime){
             currTime += b[j];
            j++;
            }
            else {
                flag = false;
            
                break;
            }
            
        }
        
    }
    
    while(i<n && flag){
        if(currTime+a[i] <= maxTime){
            currTime += a[i];
            i++;
        }
            
        else {
         flag = false;
            break;
        }
    }
    
    
    while(j<m && flag){
        if(currTime+b[j] <= maxTime){
            currTime += b[j];
            j++;
        }
        else {
            flag = false;
        
            break;
        }
    }
    
    
    if(i+j+2 >= books) return true;
    
    else false;
}

int CountBooks(vector<int> &a, vector<int> &b, int n, int m, int k ){
    int low = 0;
    int high = n+m;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        bool isValid = isValidBooks(a,b, mid, n, m, k); 
        
        if(isValid) low = mid + 1;
        
        else high = mid - 1;
    }
    
    return high;
}


int main(){
    vector<int> a = {1, 2, 3};
    vector<int> b = {80, 150, 80, 150};
    int n = 3;
    int m = 4;
    int k = 240;
    cout << CountBooks(a, b, n, m, k) << endl;
    return 0;
}