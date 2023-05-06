//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

//解法一：
class Solution {
public:
    bool isInTree(TreeNode* root, TreeNode* node)
    {
        if (root == nullptr)
            return false;

        return root == node
            || isInTree(root->left, node)
            || isInTree(root->right, node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        if (root == p || root == q)
            return root;

        bool pInLeft = isInTree(root->left, p);
        bool pInRight = !pInLeft;
        bool qInLeft = isInTree(root->left, q);
        bool qInRight = !qInLeft;

        if ((pInLeft && qInRight) || (pInRight && qInLeft))//分别在此节点的左右两侧，此节点就是所求点
            return root;
        if (pInLeft && qInLeft)//都在左侧，在左侧找
            return lowestCommonAncestor(root->left, p, q);
        else//都在右侧，在右侧找
            return lowestCommonAncestor(root->right, p, q);

    }
};

//解法二：
class Solution {
public:
    bool GetPath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path)
    {
        if (root == nullptr)
            return false;
        path.push(root);
        if (root == node)
            return true;
        if (GetPath(root->left, node, path))
            return true;
        if (GetPath(root->right, node, path))
            return true;
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath;
        stack<TreeNode*> qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);
        while (pPath.size() != qPath.size())
        {
            if (pPath.size() < qPath.size())
                qPath.pop();
            else
                pPath.pop();
        }
        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }
        return pPath.top();
    }
};