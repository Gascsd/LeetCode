//
//  main.cpp
//  106. 从中序和后续遍历序列构造二叉树
//
//  Created by zht on 2023/5/7.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder, int& posti, int begin, int end)
    {
        if(begin > end)//当区间不存在时，直接return
        {
            return nullptr;
        }
        int i = 0;
        for(; i < inorder.size(); ++i)
        {
            if(inorder[i] == postorder[posti])
                break;
        }
        TreeNode* root = new TreeNode(postorder[posti--]);//构造一个当前序列的根节点

        // [begin,i-1] i [i+1, end]
        root->right = _buildTree(postorder, inorder, posti, i + 1, end);
        root->left = _buildTree(postorder, inorder, posti, begin, i - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return _buildTree(postorder, inorder, i, 0, postorder.size() - 1);
    }
};

int main()
{
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(postorder, inorder);
    return 0;
}
