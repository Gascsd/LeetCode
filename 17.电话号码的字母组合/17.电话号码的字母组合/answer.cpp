#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    vector<string> _vs{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void DFS(vector<string>& allRet, string curRet, int i, const string& digits)
    {
        if (i == digits.size())//判断当前深度是否到达最深
        {
            allRet.push_back(curRet);
            return;
        }
        int num = digits[i] - '0';
        string str = _vs[num];
        for (auto e : str)
        {
            DFS(allRet, curRet + e, i + 1, digits);
        }

    }
    vector<string> letterCombinations(string digits) {

        vector<string> allRet;
        string curRet;
        if (digits.empty())
        {
            return allRet;
        }
        DFS(allRet, curRet, 0, digits);

        return allRet;
    }
};

int main()
{
    string digits = "23";
    vector<string> ret = Solution().letterCombinations(digits);
    for (auto& e : ret)
    {
        cout << e << endl;
    }
    return 0;
}