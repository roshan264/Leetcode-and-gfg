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
    
    string ans;
    
    string compare(string ans , string s)
    {
        if(ans == "")
        {
            return s;
        }
        
        int i = ans.size() - 1 , j = s.size() - 1;
        
        while(i >= 0 && j >= 0)
        {
            if(ans[i] > s[j])
            {
                return s;
            }
            else if(ans[i] < s[j])
            {
                return ans;
            }
            
            i--;
            j--;
        }
        
        if(i == -1)
        {
            return ans;
        }
        
        return s;
    }
    void dfs(TreeNode* p , string s)
    {
        if(p == NULL)
        {
            ans = compare(ans , s);
            return ;
        }
        
        char c = 'a' + p->val;
        
        s = s + c;
        
        if(p->left == NULL && p->right == NULL)
        {
            ans = compare(ans , s);
            return ; 
        }
       
        if(p->left != NULL)
        dfs(p->left , s);
        
        if(p->right != NULL)
        dfs(p->right , s);
        
        
    }
    string smallestFromLeaf(TreeNode* root) {
        
        ans = "";
        
        dfs(root , "");
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};