//Link : https://leetcode.com/problems/minimum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=binary-tree
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left == 0 || right == 0)
        return 1 + left + right;  // một trong 2 nhánh là NULL
    else
        return 1 + (left < right ? left : right);
}
