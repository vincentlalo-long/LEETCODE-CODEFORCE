/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL) return NULL; // nếu node head là NULL thì trả về NULL
    head->next=removeElements(head->next,val); // gọi đệ quy đến node head->next
    if(head->val==val){ // tH node head có giá trị =val
        struct ListNode* temp=head->next;// lưu node head->next
        free(head); // xóa node head
        return temp;
    }
    return head;
}
