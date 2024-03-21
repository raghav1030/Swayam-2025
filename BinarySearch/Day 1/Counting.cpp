#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countStudents()
    {
        int n;
        cin >> n;

        int q;
        cin >> q;

        vector<int> a;

        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;

            a.push_back(data);
        }

        for(int i = 0; i < q; i++){
            int x ;
            cin >> x;

            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i] >= x) cnt++;
            }
            cout << cnt; 
        }
    }

    Solution(){return;}
};

int main(){
    Solution s;
    s.countStudents();
}