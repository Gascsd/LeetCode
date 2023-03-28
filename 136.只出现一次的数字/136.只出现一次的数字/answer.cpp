#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/single-number/submissions/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        int ret = 0;
        while (it != nums.end())
        {
            ret ^= *it;
            ++it;
        }
        return ret;
    }
};

