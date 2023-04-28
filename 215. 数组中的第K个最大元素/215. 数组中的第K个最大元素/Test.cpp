#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//解法一
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> heap(nums.begin(), nums.end());
//         while(--k)
//         {
//             heap.pop();
//         }
//         return heap.top();
//     }
// };
//优化
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap(nums.begin(), nums.begin() + k);
        for (size_t i = k; i < nums.size(); ++i)
        {
            if (nums[i] > heap.top())
            {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};
int main()
{
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    cout << Solution().findKthLargest(nums, k) << endl;
	return 0;
}