#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int tmp = x;
        while(tmp != 0) {
            int rem = tmp % 10;
            tmp /= 10;

            // INT_MAX = 2147483647;
            // INT_MIN = -2147483648;
            // if (INT_MAX / 10 < res || INT_MIN / 10 > res) { // ← INT_MAX/10 = 214748364となり、剰余が7より大のケースが判定できていない
            //     return 0;
            if (INT_MAX / 10 < res || (INT_MAX / 10 == res && rem > 7)) {
                return 0;
            } else if (INT_MIN / 10 > res || (INT_MIN / 10 == res && rem < -8)) {
                return 0;
            } else {
                res = res * 10 + rem;
            }
        }

        return res;
    }
};

int main() {
    int x;
    cin >> x;

    Solution sol;
    cout << sol.reverse(x) << endl;

    return 0;
}