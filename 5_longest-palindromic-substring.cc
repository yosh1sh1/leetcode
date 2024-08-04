#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        // if (n == 0)
        //     return "";
        array<int, 2> ar = {0, 1};
        // string res;

        vector<vector<bool>> dp(n, vector<bool>(n));
        rep(i, 0, n)
            dp[i][i] = true;
        rep(i, 0, n-1) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                // res = s.substr(i, 2);
                ar = {i, 2};
            }
        }

        for (int l = 2; l < n; l++) {
            for (int i = 0; i < n - l; i++)  {
                if (s[i] == s[i+l] && dp[i+1][i+l-1]) {
                    dp[i][i+l] = true;
                    // res = s.substr(i, l+1);
                    ar = {i, l+1};
                }
            }
        }

        // return res;
        return s.substr(ar[0], ar[1]);
    }

    string bf_longestPalindrome(string s) {
        string res;
        for (int i = 0; i < (int)s.size(); i++) {
            for (int j = i + 1; j <= (int)s.size(); j++) {
                string sub = s.substr(i, j - i);

                if (isPalindrome(sub) && res.size() < sub.size()) {
                    res = sub;
                }
            }
        }
        
        return res;
    }

private:
    bool isPalindrome(string& s) {
        for (int i = 0; i < (int)s.size() / 2; i++) {
            if (s[i] != s[(int)s.size() - (i + 1)]) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    string input;
    cin >> input;

    Solution sol;
    cout << sol.longestPalindrome(input) << endl;

    return 0;
}