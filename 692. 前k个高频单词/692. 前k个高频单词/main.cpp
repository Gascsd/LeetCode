//
//  main.cpp
//  692. 前k个高频单词
//
//  Created by zht on 2023/5/12.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string,int>& l, const pair<string,int>& r)
        {
            return l.second > r.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        //在map中统计次数
        for(auto& e : words)
        {
            countMap[e]++;
        }
        //排序取出来
        vector<pair<string,int>> v;
        for(auto& e : countMap)
        {
            v.push_back(e);
        }
        //sort(v.begin(),v.end(), Compare());
        stable_sort(v.begin(),v.end(), Compare());
        vector<string> ret;
        for(size_t i = 0; i < k; ++i)
        {
            ret.push_back(v[i].first);
        }
        return ret;
    }
};

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> ret = Solution( ).topKFrequent(words, 2);
    for(auto& e : ret)
    {
        cout << e <<" ";
    }
    cout << endl;
    return 0;
}
