//Link : https://leetcode.com/problems/search-in-a-binary-search-tree/description/?envType=problem-list-v2&envId=binary-tree
//Code C : 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while(root!=NULL){
        if(root->val==val) return root;
        else if(root->val<=val){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return NULL;
}
