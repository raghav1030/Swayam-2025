#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;


	
	int NthRoot(int n, int m)
	{
	    int low = 0;
	    int high =  m;
	    
	    if(n==0) return 0;
	    if(n==1) return m;
	    
	    if(m==0) return 0;
	    if(m==1) return 1;
	    
	    int ans = -1;
	    
	    while(low <= high){
	        int mid = low + (high-low)/2;
	        
	        if(pow(mid, n) == m) return mid;
	        else if(pow(mid , n) < m){
	            low = mid + 1;
	        }
	        
	        else high = mid - 1;
	    }
	    
	    return ans;
 	}  

int main(){
    int n = 6;
	int m = 4096;
	cout << NthRoot(n, m);
	return 0;
    
}