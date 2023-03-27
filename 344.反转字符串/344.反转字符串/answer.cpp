#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        auto begin = s.begin();
        auto end = s.end() - 1;
        while (begin < end)
        {
            char tmp = *begin;
            *begin = *end;
            *end = tmp;
            begin++;
            end--;
        }

    }
};

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    char c;
    //while (cin >> c)
    //{
    //    s.push_back(c);
    //}
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
    Solution().reverseString(s);
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
	return 0;
}
