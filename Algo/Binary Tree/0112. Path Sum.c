//Link : https://leetcode.com/problems/path-sum/description/?envType=problem-list-v2&envId=binary-tree
//Code C : 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL){
        return (root->val==targetSum);
    }
    return hasPathSum(root->left,targetSum-root->val)|| 
    hasPathSum(root->right,targetSum-root->val);
}
