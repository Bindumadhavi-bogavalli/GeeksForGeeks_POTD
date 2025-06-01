#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        set<int> s1;
        set<int> s2;
        for (auto row : mat1)
            for (auto val : row)
                s1.insert(val);
                
        for (auto row : mat2)
            for (auto val : row)
                s2.insert(val);
        
        int cnt = 0;
        for (auto ele : s1) {
            int finder = x - ele;
            if (s2.find(finder) != s2.end())
                cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    vector<vector<int>> mat2 = {{5, 6}, {7, 8}};
    int x = 9;

    int result = sol.countPairs(mat1, mat2, x);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
