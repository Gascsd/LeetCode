#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        //���������ַ���
        for (size_t i = 0; i < s.size(); i++)
        {
            //ת��ΪСд
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 'a' - 'A';
            }
        }
        string tmp;
        tmp.reserve(s.size());
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                tmp += s[i];
            }
        }
        s = tmp;
        //�жϴ����Ĵ��Ƿ��ǻ��Ĵ�
        reverse(tmp.begin(), tmp.end());
        if (s == tmp)
            return true;
        else
            return false;
    }
};

int main()
{
    string s;
    getline(cin, s);
    bool ret = Solution().isPalindrome(s);
    if (ret == false)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    return 0;
}