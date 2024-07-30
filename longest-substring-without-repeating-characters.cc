#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ((int)s.size() == 0) {
            return 0;
        }
        int res = 0;
        int cnt = 1;
        int st = 0;
        unordered_set<char> ust;
        ust.insert(s[st]);
        for (int i = 1; i < (int)s.size(); i++) {
            if (ust.count(s[i])) {
                res = max(res, cnt); 
                // res = max(res, i - st)
                while (s[st] != s[i]) {
                    ust.erase(s[st]);
                    st++;
                    cnt--;
                }
                st++; // s[i]と同じ文字の次にに進める
                // cnt--;
            } else {
                ust.insert(s[i]);
                cnt++;
            }
        }
        res = max(res, cnt);
        return res;
    }
};


int main() {
    string input;
    cin >> input;

    Solution sol;
    cout << sol.lengthOfLongestSubstring(input) << endl;

    return 0;
}