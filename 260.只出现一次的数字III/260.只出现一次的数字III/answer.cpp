
//https://leetcode.cn/problems/single-number-iii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //将所有数据异或，得到的结果就是所求的两个数的异或
        //找到一个为1的比特位，所求的两个数在这个位上的值肯定不同
        //按照这个位上的值将原数组中的数分成两部分
        //分出的结果中出现两次的数绝对在同一组
        //现在分别对这两组数异或，会得到两个值，这两个值就分别是所求的两个值
        int tmp = 0;
        for (auto e : nums)
        {
            tmp ^= e;
        }
        int pos = 1;
        while ((pos & tmp) == 0)
        {
            pos <<= 1;
        }
        vector<int> group1, group2;
        for (auto e : nums)
        {
            if (e & pos)
            {
                group1.push_back(e);
            }
            else
            {
                group2.push_back(e);
            }
        }
        vector<int> ret;
        tmp = 0;
        for (auto e : group1)
        {
            tmp ^= e;
        }
        ret.push_back(tmp);
        tmp = 0;
        for (auto e : group2)
        {
            tmp ^= e;
        }
        ret.push_back(tmp);
        return ret;
    }
};
int main()
{
    vector<int> nums{ 1,2,1,3,2,5 };
    vector<int> ret = Solution().singleNumber(nums);
    cout << ret[0] << " " << ret[1] << endl;
}