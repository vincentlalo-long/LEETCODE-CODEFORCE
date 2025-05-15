// Link : https://leetcode.com/problems/palindrome-linked-list/description/?envType=problem-list-v2&envId=stack
// COde C :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int STACK[100000]; // Khởi tạo stack bằng array
    int top=-1; // khởi tạo giá trị top
    struct ListNode* current=head;
    while(current!=NULL){
        STACK[++top]=current->val; // cập nhật giá trị và lưu vào stack 
        current=current->next; // di chuyển đến phần tử tiếp theo
    }
    current=head;
    while(current!=NULL){
        if(STACK[top--]!=current->val){ // duyệt ngược lại để xét với các giá trị ban đầu
            return false;
        }
        current=current->next;
    }
    return true;


}
