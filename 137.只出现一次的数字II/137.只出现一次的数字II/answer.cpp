//https://leetcode.cn/problems/single-number-ii/comments/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //�ⷨ1�����򣺲�������ʱ�临�Ӷ�
    int singleNumber1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i += 3)
        {
            if (i + 1 == nums.size() || nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }
    //�ⷨ2��λ����ķ���
    int singleNumber2(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (auto e : nums)
            {
                count += (e >> i) & 1;
            }
            ret |= (count % 3) << i;
        }
        return ret;
    }

};

int main()
{
    vector<int> nums{ 2,2,3,2 };
    cout << Solution().singleNumber2(nums) << endl;
}