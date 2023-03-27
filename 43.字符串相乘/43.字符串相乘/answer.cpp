#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        size_t i = num1.size() - 1;
        size_t j = num2.size() - 1;
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
    string multiply_1(string s, char c)//大数乘一个数,返回相乘后的结果
    {
        int add = 0;
        string ans;
        for (auto e : s)
        {
            add = (e - '0') * (c - '0') + add;
            char tmp = add % 10 + '0';
            ans += tmp;
            add /= 10;
        }
        if (add != 0)
        {
            ans += add;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return 0;
        //默认num1长度大于num2
        if (num1.size() < num2.size())
            return multiply(num2, num1);
        //逆向遍历num2，与num1中的所有值逆序相乘
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        vector<string> v;
        v.reserve(num2.size());
        for (size_t i = 0; i < v.capacity(); i++)
        {
            v[i] = multiply_1(num1, num2[i]);
        }
        for (size_t i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < i; ++j)
            {
                v[i] += '0';
            }
            ans = addStrings(ans, v[i]);
        }
        return ans;
    }
};

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    string ans = Solution().multiply(num1, num2);
    cout << ans << endl;
    return 0;
}
