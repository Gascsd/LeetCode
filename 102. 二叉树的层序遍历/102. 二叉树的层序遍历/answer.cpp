//https://leetcode.cn/problems/binary-tree-level-order-traversal/submissions/

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
            //“ª≤„“ª≤„push
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