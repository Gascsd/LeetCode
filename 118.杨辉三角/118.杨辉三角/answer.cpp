#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/pascals-triangle/description/
#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv(numRows);
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            vv[i].resize(i + 1);
//            vv[i][0] = vv[i][vv[i].size() - 1] = 1;
//        }
//        for (size_t i = 2; i < vv.size(); ++i)
//        {
//            for (size_t j = 1; j < vv[i].size(); ++j)
//            {
//                vv[i][j] = vv[i - 1][j] = vv[i - 1][j - 1];
//            }
//        }
//        return vv;
//    }
//};
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) 
        {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) 
            {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vv = Solution().generate(n);
    for (size_t i = 0; i < vv.size(); ++i)
    {
        for (size_t j = 0; j < vv[i].size(); ++j)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


