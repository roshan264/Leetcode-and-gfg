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
    bool between(int strt , int end , int i)
    {
        if(i < strt || i > end)
        {
            return false;
        }
        
        return true;
    }
    TreeNode* constructTree(vector<int> preorder , vector<int> postorder , int startPre , int endPre , int startPost , int endPost)
    {
      //  cout<<startPre<<" "<<endPre<<" "<<startPost<<" "<<endPost<<"\n";
        if(startPre > endPre || startPost > endPost)
        {
            return NULL;
        }
        
        if(startPre == endPre )
        {
            TreeNode* temp = new TreeNode(preorder[startPre]);
            return temp;
        }
        
        if(startPre + 1 == endPre)
        {
            TreeNode* temp = new TreeNode(preorder[startPre]);
            TreeNode* temp1 = new TreeNode(preorder[startPre+1]);
            
            temp->left = temp1;
            return temp;
        }
        int root = preorder[startPre + 1];
        
        TreeNode *l = NULL , *r = NULL;
        for(int i = startPost ; i < endPost ; i++)
        {
            if(postorder[i] == root)
            {
                int len = (i - startPost);
                
                 if(between(startPre+1,endPre ,  startPre + 1 ) && between(startPre+1,endPre ,  startPre + len + 1))
                l = constructTree(preorder , postorder , startPre + 1 , startPre + len + 1 , startPost , i);
                
                if(between(startPre+1,endPre , startPre + 2 + len) && between(startPost,endPost-1 , i + 1)  && between(startPost,endPost -1, endPost-1));
                r = constructTree(preorder , postorder , startPre + 2 + len , endPre , i + 1 , endPost-1);
                break;
            }
        }
        
        TreeNode* head = new TreeNode(preorder[startPre]);
        head->left = l;
        head->right = r;
        
         
        return head;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        
        return constructTree(preorder , postorder , 0 , n - 1 , 0 , n - 1);
    }
};

