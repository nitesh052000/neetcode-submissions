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
        TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preIndex, int instart,int inend){
            
            // Base case
            if (instart > inend)
            return NULL;

            // step 1 find the root node

            int rootval = preorder[preIndex++];

            TreeNode* root = new TreeNode(rootval);

            //step 2 find root in inorder
            int i = instart;
            while(i<=inend && inorder[i]!=rootval){
                i++;
            }

            root->left = solve(preorder,inorder,preIndex,instart,i-1);

            root->right = solve(preorder, inorder,preIndex,i+1,inend);

            return  root;

        }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;

        return solve(preorder, inorder, preIndex, 0,inorder.size()-1);
    }
};
