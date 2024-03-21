#include <bits/stdc++.h>
#include<vector>

using namespace std;

bool findNoOfCows(vector<int> stalls, int minDist, int cows)
{
    int lastStall = stalls[0];
    int count = 1;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastStall >= minDist)
        {
            count++;
            lastStall = stalls[i];
        }

        if (count >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    if (stalls.size() < k)
        return 0;
    int n = stalls.size();
    int low = 1;

    sort(stalls.begin(), stalls.end());

    int high = stalls[n - 1] - stalls[0];
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        bool isPossibleToAccomodate = findNoOfCows(stalls, mid, k);
        if (isPossibleToAccomodate)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << aggressiveCows(stalls, k);
    return 0;
}