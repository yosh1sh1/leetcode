#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());

        // if (is_sorted(nums.begin(), nums.end())) {
        //     int tmp = *(nums.end() - 1);
        //     *(nums.end() - 1) = *(nums.end() - 2);
        //     *(nums.end() - 2) = tmp;
        //     return;
        // }

        // if (is_sorted(nums.begin(), nums.end(), std::greater<>())) {
        //     sort(nums.begin(), nums.end());
        //     return;
        // }

        // auto itr = is_sorted_until(nums.begin(), nums.end());
        // cout << *itr << endl;

        // int tar = *(itr - 1);
        // int diff = INT_MAX;
        // auto res = find_if(itr, nums.end(), [&tar, &diff](int x){ return x > tar && (x - tar) < diff; });
        // if (res == nums.end()) {
        //     auto min = min_element(itr, nums.end());
        //     iter_swap(itr - 2, min);
        //     sort(itr - 1, nums.end());
        // } else {
        //     iter_swap();
        // }

        return;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    Solution sol;
    sol.nextPermutation(v);

    for (auto t : v) {
        cout << t << ", ";
    }
    cout << endl;

    return 0;
}