#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

    bool checkFunc(vector<int> nums, int maxOperations, int maxBalls){
        long long int currOperations = 0;

        for(int num : nums){
            currOperations += (num/maxBalls) - 1;
            if(num%maxBalls != 0) currOperations++;
        }

        if(currOperations <= maxOperations) return true;

        else return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = INT_MIN;

        for(int num : nums){
            high = max(num, high);
        }

        while(low <= high){
            int mid = low + (high-low)/2;

            if(checkFunc(nums, maxOperations, mid)){
                high = mid-1;
            }
            else low = mid + 1;
        }

        return low;
    }
};

int main(){
    vector<int> nums = {9};
    int maxOperations = 2;
    Solution s;
    cout << s.minimumSize(nums, maxOperations) << endl;
    return 0;
}