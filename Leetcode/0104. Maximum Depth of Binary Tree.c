//Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=binary-tree
//Code C : O(n) 
#define max(a,b) ((a) > (b) ? (a) : (b))

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int lr=maxDepth(root->left);
    int rr=maxDepth(root->right);
    return 1 + max(lr,rr);
}
