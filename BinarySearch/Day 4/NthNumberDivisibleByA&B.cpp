#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    long long int gcd(long long int a, long long int b){
        if(b == 0) return a;

        return gcd(b, a%b);
    }

    long long int lcm(long long int a, long long int b){
        return (a*b)/gcd(a,b);
    }

    long long int divisibleTermCount(long long int mid, long long int a, long long int b){
        return (mid/a) + (mid/b) - (mid/lcm(a,b));
    }


    int nthMagicalNumber(int n, int a, int b) {
        long long int low = 1;
        long long int high = 1e17;
        int mod = 1e9+7;

        while(low < high){
            long long int mid = low + (high-low)/2;

            long long int count = divisibleTermCount(mid, a, b);

            if(count < n) low = mid + 1;

            else high = mid;
        }

        return high%mod;
    }
};


int main(){
    Solution sol;
    cout << sol.nthMagicalNumber(1, 2, 3) << endl;
    return 0;
}