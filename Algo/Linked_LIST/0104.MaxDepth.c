
#define max(a,b) ((a) > (b) ? (a) : (b))
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int lr=maxDepth(root->left);
    int rr=maxDepth(root->right);
    return 1 + max(lr,rr);
}
