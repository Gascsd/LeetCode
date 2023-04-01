//https://leetcode.cn/problems/single-number-ii/comments/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i += 3)
        {
            if (i + 1 == nums.size() || nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }
};