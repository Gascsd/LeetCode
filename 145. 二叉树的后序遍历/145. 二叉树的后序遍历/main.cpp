//
//  main.cpp
//  145. 二叉树的后序遍历
//
//  Created by zht on 2023/5/8.
//
// https://leetcode.cn/problems/binary-tree-postorder-traversal/submissions/


#include <iostream>


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postorder;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;//这里使用一个prev保存上一个访问的节点
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            //当右子树为空或者右子树已经访问过
            if(top->right == nullptr || top->right == prev)
            {
                st.pop();
                postorder.push_back(top->val);//访问根
                prev = top;//记录上一个访问节点
            }
            else//右子树没有被访问过，迭代访问右子树
                cur = top->right;
        }
        return postorder;
    }
};
