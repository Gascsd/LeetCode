#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/reverse-words-in-a-string-iii/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string::iterator start = s.begin();
        string::iterator end = start;
        while ((end = find(start, s.end(), ' ')) != s.end())
        {
            reverse(start, end);
            start = end + 1;
        }
        reverse(start, s.end());
        return s;
    }
};