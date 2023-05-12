//
//  main.cpp
//  349. 两个数组的交集
//
//  Created by zht on 2023/5/12.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> ret;
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        while(it1 != s1.end() && it2 != s2.end())
        {
            if(*it1 == * it2)//交集
            {
                ret.push_back(*it1);
                ++it1;
                ++it2;
            }
            else
            {
                *it1 < *it2 ? ++it1 : ++it2;
            }
        }
        return ret;
    }
};
