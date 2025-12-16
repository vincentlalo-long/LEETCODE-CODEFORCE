//Link : https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // Ta sẽ giải bằng phương pháp đệ quy 
    // Đầu tiên ta giải các TH base case 
    if(head==NULL || head->next==NULL) return head; // nếu không có node nào hoặc chỉ có duy nhất 1 node thì trả về 
    // Khi có 2 node trở lên thì ta sẽ đệ quy để swap
    struct ListNode* first=head;
    struct ListNode* second=first->next;
    first->next=swapPairs(second->next);
    second->next=first;
    return second;
}
