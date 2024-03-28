#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution
{

public:
    int findTotalBouquet(vector<int> &arr, int target, int k)
    {
        int flowerCount = 0;
        int bouquet = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= target)
            {
                flowerCount++;

                if (flowerCount == k)
                {
                    bouquet++;
                    flowerCount = 0;
                }
            }

            else
            {
                flowerCount = 0;
            }
        }

        return bouquet;
    }

    int minDays(vector<int> &arr, int m, int k)
    {
        int s = INT_MAX;
        int e = INT_MIN;
        if (arr.size() / k < m)
        {
            return -1;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            s = min(s, arr[i]);
            e = max(arr[i], e);
        }

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            int totalBouquet = findTotalBouquet(arr, mid, k);

            if (totalBouquet >= m)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return s;
    }
};


int main()
{
    Solution s;
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << s.minDays(arr, m, k);
    return 0;
}