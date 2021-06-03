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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int leftsum = 0;
        int rightsum = 0;
        if(root-> val > high && root -> left != NULL){
                leftsum = rangeSumBST(root -> left, low, high);
        }
        
        else if(root-> val < low && root -> right != NULL){
                rightsum = rangeSumBST(root -> right, low, high);
        }
        else{
            if(root -> left != NULL)
                leftsum = rangeSumBST(root->left, low, high);
            if(root->right != NULL)
                rightsum = rangeSumBST(root->right, low, high);
        }
        if(root-> val >= low && root->val <= high)
            return leftsum + rightsum + root-> val;
        return leftsum + rightsum;
    }
    
};