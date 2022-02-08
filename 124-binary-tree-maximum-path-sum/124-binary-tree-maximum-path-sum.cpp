/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans;
    
    int findPath(TreeNode* p)
    {
        if(p == NULL)
        {
            return 0;
        }
        
        int l = findPath(p->left);
        int r = findPath(p->right);
        
        ans = max(ans , l + r + p->val);
        
        return max(0 , max(l , r) + p->val);
    }
    int maxPathSum(TreeNode* root) {
        
        ans = INT_MIN;
        
        int x = findPath(root);
        return ans;
    }
};