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
class FindElements {
public:
    TreeNode* head ;
    
    void dfs(TreeNode* p , int v)
    {
        if(p == NULL)
        {
            return;
        }
        
        p->val = v;
        
        dfs(p->left , 2 * v + 1);
        dfs(p->right , 2 * v + 2);
        
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        
        head = root;
        dfs(root , 0);
    }
    
    bool checkTree(TreeNode* p , int strt , int end , int pos)
    {
        if(p == NULL || (pos > end) || (pos < strt))
        {
            return false;
        }
        
        if(strt == end)
        {
            return true;
        }
                 
        int mid = strt + (end - strt) / 2;
        
        return checkTree(p->left , strt , mid , pos) || checkTree(p->right , mid + 1 , end , pos);
    }
    
    
    bool find(int target) {
        //cout<<(log2(target + 1))<<" ";
        int size = pow(2 , int ((log2(target + 1))));
        
        int pos = target - (size - 1);
        return checkTree(head , 0 , size - 1 , pos);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */