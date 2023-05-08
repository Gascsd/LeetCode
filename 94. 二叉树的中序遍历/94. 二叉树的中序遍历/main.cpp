//
//  main.cpp
//  94. 二叉树的中序遍历
//
//  Created by zht on 2023/5/8.
//
//https://leetcode.cn/problems/binary-tree-inorder-traversal/submissions/
#include <iostream>
#include <vector>
using namespace


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            st.pop();
            inorder.push_back(top->val);//这里是在处理右子树之前push_back
            cur = top->right;
        }
        return inorder;
    }
};
