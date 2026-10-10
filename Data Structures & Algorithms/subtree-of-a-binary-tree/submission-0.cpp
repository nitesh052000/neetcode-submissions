
class Solution {
public:
    bool sameTreeSolution(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        if (p->val != q->val)
            return false;

        return sameTreeSolution(p->left, q->left) &&
               sameTreeSolution(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      
      if(subRoot==NULL)
      return true;

      if(root==NULL)
      return false;

      if (root->val == subRoot->val &&
            sameTreeSolution(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); 

    }
};
