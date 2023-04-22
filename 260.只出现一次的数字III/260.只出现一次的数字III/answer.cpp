
//https://leetcode.cn/problems/single-number-iii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //������������򣬵õ��Ľ����������������������
        //�ҵ�һ��Ϊ1�ı���λ������������������λ�ϵ�ֵ�϶���ͬ
        //�������λ�ϵ�ֵ��ԭ�����е����ֳ�������
        //�ֳ��Ľ���г������ε���������ͬһ��
        //���ڷֱ������������򣬻�õ�����ֵ��������ֵ�ͷֱ������������ֵ
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