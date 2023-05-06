//https://leetcode.cn/problems/binary-tree-level-order-traversal/


//可以考虑把https://leetcode.cn/problems/binary-tree-level-order-traversal/这道题的结果reverse一下即可
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        int levelSize = 0;
        if (root)
        {
            q.push(root);
            levelSize = 1;
        }
        while (!q.empty())
        {
            vector<int> levelV;
            while (levelSize--)
            {
                TreeNode* front = q.front();
                q.pop();
                levelV.push_back(front->val);
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            ret.push_back(levelV);
            levelSize = q.size();
        }
        return ret;
    }
};

