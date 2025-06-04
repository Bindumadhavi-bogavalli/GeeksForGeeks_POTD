#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));
        vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    } else {
                        curr[j][k] = max({prev[j][k], curr[j - 1][k], curr[j][k - 1]});
                    }
                }
            }
            prev = curr;
        }

        return curr[n2][n3];
    }
};

int main() {
    Solution sol;

    string s1 = "abcd1e2";
    string s2 = "bc12ea";
    string s3 = "bd1ea";

    int result = sol.lcsOf3(s1, s2, s3);
    cout << "Length of LCS of three strings: " << result << endl;

    return 0;
}
