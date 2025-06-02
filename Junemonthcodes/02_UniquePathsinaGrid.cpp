#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

        dp[m-1][n-1] = 1;

        for(int j = n - 2; j >= 0; j--) {
            if(grid[m-1][j] == 1) break;
            dp[m-1][j] = 1;
        }

        for(int i = m - 2; i >= 0; i--) {
            if(grid[i][n-1] == 1) break;
            dp[i][n-1] = 1;
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                if(grid[i][j] == 0) {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = sol.uniquePaths(grid);
    cout << "Unique paths: " << result << endl;

    return 0;
}
