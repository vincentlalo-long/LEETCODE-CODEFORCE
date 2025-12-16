//Link L https://leetcode.com/problems/same-tree/description/?envType=problem-list-v2&envId=binary-tree
//COde C bằng đệ quy : 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL && q==NULL) return true; // Nếu 2 cây đề rỗng trả về true
    if(p==NULL||q==NULL) return false;// nếu 1 trong 2 cây rỗng  thì false
    if(p->val!=q->val) return false; // nếu giá trị tại 2 nút khác nhau thì false
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); // duyệt con bên trái và bên phải 

}
