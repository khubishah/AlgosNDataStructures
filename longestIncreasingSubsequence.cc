#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            vector<int>dp(nums.size());
            int maximum = INT_MIN;
            // dp[i] equals length of longest increasing subsequence from 0,1..,i
            for (int i = 0; i < nums.size(); i++) {
                dp[i] = 1; // a single-element subsequence of just this element counts at least
                for (int j = 0; j < i; j++) { // for each element before this one
                    if (nums[i] > nums[j]) // if the current element is bigger than a previous, they can form a longer subsequence than el i by itself
                        dp[i] = max(dp[i], dp[j] + 1); // take the highest number always
                }
                maximum = max(maximum, dp[i]); // store the max. it's not necessary that it's at n-1 per say if n-1 is a really small number for example compared to the others
            }
            return maximum;
        }
};