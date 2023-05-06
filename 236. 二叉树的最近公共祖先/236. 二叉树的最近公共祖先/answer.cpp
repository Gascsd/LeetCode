//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

//�ⷨһ��
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

        if ((pInLeft && qInRight) || (pInRight && qInLeft))//�ֱ��ڴ˽ڵ���������࣬�˽ڵ���������
            return root;
        if (pInLeft && qInLeft)//������࣬�������
            return lowestCommonAncestor(root->left, p, q);
        else//�����Ҳ࣬���Ҳ���
            return lowestCommonAncestor(root->right, p, q);

    }
};

//�ⷨ����
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