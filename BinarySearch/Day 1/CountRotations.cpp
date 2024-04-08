#include <vector>
using namespace std;

int findKRotation(vector<int> &arr){
    // Write your code here. 
    int low = 0;
    int high = arr.size() - 1;

    if(arr[low] <= arr[high]) return 0;

    
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] ) return mid+1;

        if(arr[mid] >= arr[0]) low = mid + 1;

        else high = mid - 1;
    }   

    return -1;
}