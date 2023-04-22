//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/

//c
int removeDuplicates(int* nums, int numsSize) {
    int dst = 0, src = 1;
    while (src < numsSize)
    {
        if (nums[dst] == nums[src])
        {
            src++;
        }
        else
        {
            dst++;
            nums[dst] = nums[src];
            src++;
        }
    }
    return ++dst;
}


//cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto start = nums.begin();
        while (start != --nums.end())
        {
            if (*start == *(start + 1))
            {
                start = nums.erase(start);
            }
            else
            {
                ++start;
            }
        }
        return nums.size();
    }
};