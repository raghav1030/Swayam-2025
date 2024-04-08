#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        if(low == high) return low;

        if(nums[low] > nums[low+1]) return low;

        if(nums[high] > nums[high-1]) return high;

        low++;
        high--;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if(nums[mid] > nums[mid-1]) low = mid +1;

            else if(nums[mid] < nums[mid-1]) high = mid - 1; 

        }

        return -1;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << s.findPeakElement(nums);
    return 0;
}