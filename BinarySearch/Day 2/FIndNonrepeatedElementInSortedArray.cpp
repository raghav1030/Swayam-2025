#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        if(low == high)  return nums[0];

        if(nums[0] != nums[1]) return nums[0];

        if(nums[high-1] != nums[high]) return nums[high];

        low++;
        high--;
        
        while(low <= high){
            int mid = low + (high-low)/2;
        
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

            else {

                if(mid % 2 == 0){

                    if(nums[mid-1] == nums[mid]){
                        high = mid - 1;
                    }

                    else if(nums[mid+1] == nums[mid]){
                        low = mid + 1;
                    }
                }

                else{
                    if(nums[mid-1] == nums[mid]){
                        low = mid + 1;
                    }

                    else if(nums[mid+1] == nums[mid]){
                        high = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << s.singleNonDuplicate(nums);
    return 0;
}