#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        size_t start = 0;
        size_t end = 0;
        while (s.size() - start >= 2 * k)
        {
            end = start + k;
            reverse(s.begin() + start, s.begin() + end);
            start += 2 * k;
        }
        if (s.size() - start < k)
            end = s.size();
        else
            end = start + k;
        reverse(s.begin() + start, s.begin() + end);
        return s;
    }
};

int main()
{
    int k;
    string s;
    cin >> s >> k;
    s = Solution().reverseStr(s, k);
    cout << s << endl;
	return 0;
}