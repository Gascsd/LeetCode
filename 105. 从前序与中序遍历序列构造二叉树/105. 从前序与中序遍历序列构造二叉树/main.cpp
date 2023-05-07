//
//  main.cpp
//  105. 从前序与中序遍历序列构造二叉树
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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int begin, int end)
    {
        if(begin > end)//当区间不存在时，直接return
        {
            return nullptr;
        }
        int i = 0;
        for(; i < inorder.size(); ++i)
        {
            if(inorder[i] == preorder[prei])
                break;
        }
        TreeNode* root = new TreeNode(preorder[prei++]);//构造一个当前序列的根节点

        // [begin,i-1] i [i+1, end]
        root->left = _buildTree(preorder, inorder, prei, begin, i-1);
        root->right = _buildTree(preorder, inorder, prei, i+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, preorder.size()-1);
    }
};
int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(preorder, inorder);
    return 0;
}
