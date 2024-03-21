#include <string>
#include <iostream>
#include <cmath>
using namespace std;

    class Solution {
    public:

    bool findNoOfEqualSubstrings(string s, string t, int maxLength, int maxCost){
        int currCost = 0;
        int length = 0;
        int i = 0;
        int newLength = -1;
        while(i < s.size()){
            if(currCost + abs(s[i] - t[i]) <= maxCost){
                currCost += abs(s[i] - t[i]);
                length++;
            // cout << abs(s[i] - t[i]) << " " << endl;
            }
            else {
                currCost = abs(s[i] - t[i]);
                newLength = max(length, newLength);
                length = 0;
            }

            // cout << currCost << " " << abs(s[i] - t[i]) << " " << length << " " <<  newLength << " " << maxLength <<  endl;

            // if(currCost > maxCost) break;
            i++;
        }
            if(newLength >= maxLength ) return true;

        cout << endl;

        return false;
    }
        int equalSubstring(string s, string t, int maxCost) {
            int low = 0;
            int high = s.size()-1;

            while(low <= high){
                int mid = low + (high-low)/2;

                bool isPossible = findNoOfEqualSubstrings(s,  t, mid, maxCost);

                if(isPossible) low = mid + 1;

                else high = mid - 1;

            }

            if(high < 0) return 0;
            return high;
        }
    };


    int main(){
        Solution s;
        string s1 = "abcd";
        string s2 = "bcdf";
        int maxCost = 3;
        cout << s.equalSubstring(s1, s2, maxCost);
        return 0;
    }