/*
Given a 2D grid where each spot has a integer value, starting from orig (0,0), find the greatest total 
weight you can accumulate with K steps starting at the origin.

Assumption: all grid values are > 0

i.d.
_______
3|4|2|1
6|1|9|3
3|5|2|4
-------
K = 4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWeightPathKSteps(vector<vector<int>> & grid, int k) {
            if (grid.size() == 0 || grid[0].size() == 0) return 0;
            int dp [grid.size()][grid[0].size()][k]; // dp[r][c][s] = max weight path when you take s steps starting at (r,c)
            int steps = 0;
            int nRows = grid.size();
            int nCols = grid[0].size();
            while (steps < k) {
                for (int r = 0; r < min(k, nRows); r++) {
                    for (int c = 0; c < min(k, nCols); c++) {
                        if (steps == 0) {
                            dp[r][c][steps] = grid[r][c];
                            continue;
                        }
                        int above = r-1 >= 0 ? dp[r-1][c][steps - 1] : 0;
                        int below = r+1 < nRows ? dp[r+1][c][steps -1] : 0;
                        int left = c-1 >= 0 ? dp[r][c-1][steps -1] : 0;
                        int right = c+1 < nCols ? dp[r][c+1][steps-1] : 0;
                        dp[r][c][steps] = grid[r][c] + max(above, max(left, max(right, below)));
                    }
                }
                steps++;
            }
            
            return dp[0][0][k-1];
            
        }

int main()
{
    vector<vector<int>> grid = {{3,4,2,1}, {6,1,9,3}, {3,5,2,4}};
    int ans = maxWeightPathKSteps(grid, 4);
    cout << "ANSWER: " << ans << endl;

    return 0;
}

/*
DP Solution:
Runtime: O(max(nRows,k)*max(nCols,k)*k)
Space: O(nRows*nCols*k)
*/