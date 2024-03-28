#include<iostream>
#include<vector>
using namespace std;

bool isPossible( vector<int> &boards, int k, int mid ){
    int painterCount = 1 ;
    int Sum = 0 ;
    for (int i = 0 ; i < boards.size() ; i++){
         if  (Sum + boards[i] <= mid){
             Sum += boards[i] ;
         }   
        
        else {
            painterCount++;
            
            if( painterCount > k || boards[i] > mid){
                return false;
            }
            
            Sum = boards[i] ;
        }
    }
   return true;
}



int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    for (int i = 0 ; i < boards.size() ; i++  ){
         sum += boards[i] ;   
    }
    int e = sum;
    int ans = -1 ;
    int mid  = s + ( e - s ) / 2 ;
    
    while (s <= e){
        if(isPossible(boards , k , mid )){
            ans = mid ;
            e = mid - 1 ;
        }
        
        else{
            s = mid + 1 ;
        }
        mid  = s + ( e - s ) / 2 ;
    }
    return ans ;
}


int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << findLargestMinDistance(boards, k) << endl;
    return 0;
}