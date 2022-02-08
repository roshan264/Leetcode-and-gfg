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
    
  //  int ans;
   
    int max(int a , int b)
    {
        if(a > b)
        {
            return a;
        }
        
        return b;
    }
    int findPath(TreeNode* p , int *ans)
    {
        if(p == NULL)
        {
            return 0;
        }
        
        int l = findPath(p->left , ans);
        int r = findPath(p->right , ans);
        
        *ans = max(*ans , l + r + p->val);
        
        return max(0 , max(l , r) + p->val);
    }
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        
        int x = findPath(root , &ans);
        return ans;
    }
};