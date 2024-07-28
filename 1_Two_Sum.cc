\class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            int tmp = target - nums[i];
            auto itr = find(nums.begin() + (i + 1), nums.end(), tmp);
            if (itr == nums.end()) {
                continue;
            } else {
                res.push_back(i);
                res.push_back(static_cast<int>(distance(nums.begin(), itr)));
                break;
            }
        }
        return res;
    }
};