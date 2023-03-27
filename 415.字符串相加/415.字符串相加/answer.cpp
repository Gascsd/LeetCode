#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/add-strings/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans += '0' + result % 10;
            add = result / 10;
            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string ret = Solution().addStrings(s1, s2);
    cout << ret << endl;
    return 0;
}
