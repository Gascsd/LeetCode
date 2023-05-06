//https://leetcode.cn/problems/binary-tree-preorder-traversal/


//C语言解法
void preoder(struct TreeNode* root, int* ret, int* pi)
{
    if (root == NULL)
        return;

    ret[*pi] = root->val;
    (*pi)++;
    preoder(root->left, ret, pi);
    preoder(root->right, ret, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    assert(ret);
    int i = 0;
    preoder(root, ret, &i);
    *returnSize = i;
    return ret;
}


//C++解法
class Solution {
public:
    void _preorderTraversal(TreeNode* root, vector<int>& ret)
    {
        if (root == nullptr)
            return;
        ret.push_back(root->val);
        _preorderTraversal(root->left, ret);
        _preorderTraversal(root->right, ret);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        _preorderTraversal(root, ret);
        return ret;
    }
};