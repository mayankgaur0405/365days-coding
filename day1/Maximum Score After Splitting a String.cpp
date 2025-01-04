// class Solution {
//  public:
//   int maxScore(string s) {
//     int ans = 0;
//     int zeros = 0;
//     int ones = ranges::count(s, '1');

//     for (int i = 0; i + 1 < s.size(); ++i) {
//       if (s[i] == '0')
//         ++zeros;
//       else
//         --ones;
//       ans = max(ans, zeros + ones);
//     }

//     return ans;
//   }
// };

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int zeros = 0;
        int ones = count(s.begin(), s.end(), '1');

        for (int i = 0; i + 1 < s.size(); ++i) {
            if (s[i] == '0')
                ++zeros;
            else
                --ones;
            ans = max(ans, zeros + ones);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the binary string: ";
    cin >> s;
    cout << "Maximum score after splitting the string: " << solution.maxScore(s) << endl;
    return 0;
}
