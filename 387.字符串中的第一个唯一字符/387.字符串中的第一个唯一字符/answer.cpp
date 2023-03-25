#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int* hash = new int[26];
        for (size_t i = 0; i < 26; i++)
        {
            hash[i] = 0;
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            if (hash[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    string s;
    cin >> s;
    int ret = Solution().firstUniqChar(s);
    cout << ret << endl;
    return 0;
}