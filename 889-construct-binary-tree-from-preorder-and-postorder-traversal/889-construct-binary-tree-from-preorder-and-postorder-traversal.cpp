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
     int indexPost[31];
    
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
        int i = indexPost[root];
        int len = (i - startPost);

        l = constructTree(preorder , postorder , startPre + 1 , startPre + len + 1 , startPost , i);                
        r = constructTree(preorder , postorder , startPre + 2 + len , endPre , i + 1 , endPost-1);

        TreeNode* head = new TreeNode(preorder[startPre]);
        head->left = l;
        head->right = r;
        
         
        return head;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        
       
        
        memset(indexPost , -1 , sizeof(indexPost));
        for(int i = 0 ; i < postorder.size() ; i++)
        {
            indexPost[postorder[i]] = i;
        }
        return constructTree(preorder , postorder , 0 , n - 1 , 0 , n - 1);
    }
};

