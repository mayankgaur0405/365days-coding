// class Solution {
//  public:
//   int climbStairs(int n) {
  
//     vector<int> dp(n + 1);
//     dp[0] = 1;
//     dp[1] = 1;

//     for (int i = 2; i <= n; ++i)
//       dp[i] = dp[i - 1] + dp[i - 2];

//     return dp[n];
//   }
// };


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " steps: " << solution.climbStairs(n) << endl;
    return 0;
}
