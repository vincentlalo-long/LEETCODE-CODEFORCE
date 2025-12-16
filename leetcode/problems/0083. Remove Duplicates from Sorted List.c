//LInk problem : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/?envType=problem-list-v2&envId=linked-list
// COde C :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode* current=head;
    while(current!=NULL&&current->next!=NULL){ 
        if(current->val==current->next->val){ // xét 2 phần tử liên tiếp tại dãy đã sort rồi
            struct ListNode* temp=current->next;
            current->next=current->next->next; 
            free(temp);
        }
        else{
            current=current->next;
        }
    }
    return head;

}
