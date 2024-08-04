#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n);
        dp[0].push_back("()");

        for (int i = 1; i < n; i++) {
            // 最初の ) が出るまでに () を追加してけばよさそう
            for (auto s : dp[i - 1]) {
                dp[i].push_back("()" + s);
                int j = 0;
                while (s[j] != ')') { // insert [s[0] ~ s[j] + "()" + s[j+1] ~]
                    string tmp = s;
                    dp[i].push_back(tmp.insert(j+1, "()"));
                    j++;
                }
            }
        }
        
        return dp[n - 1];
    }
};

int main () {
    int n;
    cin >> n;

    Solution sol;
    for (auto s : sol.generateParenthesis(n)) {
        cout << s << ", ";
    }
    cout << endl;

    return 0;
}