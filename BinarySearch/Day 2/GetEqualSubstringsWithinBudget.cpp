#include <string>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        long long int currCost = 0;
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;

        while (j < s.length())
        {
            currCost += abs(s[j] - t[j]);

            if (currCost >= maxCost)
            {
                while (currCost > maxCost && i <= j)
                {
                    cout << j - i + 1 << " " << currCost << " " << maxCost << endl;

                    currCost -= abs(s[i] - t[i]);
                    i++;
                }
            }
            maxLen = max(maxLen, j - i + 1);

            j++;
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
    string s1 = "abcd";
    string s2 = "bcdf";
    int maxCost = 3;
    cout << s.equalSubstring(s1, s2, maxCost);
    return 0;
}