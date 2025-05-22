//Link : https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=linked-list
// Code C : 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return head; // Nếu node head rỗng hoặc danh sách chỉ có 1 node là head thì trả ngay về head
    struct ListNode dummyNode; // tạo 1 note giả dummy node để lưu trữ 
    dummyNode.next=head; // Khởi tạo node giả dummy đứng trước node head ở ban đầu 
    struct ListNode* prev=&dummyNode; // tạo 1 con trỏ prev để trỏ đến node trước của dummyNode
    while(prev->next!=NULL && prev->next->next!=NULL){ // Kiểm tra điều kiện vòng lặp 
        struct ListNode* firstN=prev->next ;
        struct ListNode* secondN=firstN->next;
        firstN->next=secondN->next; // ta sẽ gán first->next sang node đằng sau second để hoán đổi 
        secondN->next=firstN; // Gán lại second thành node first ban đầu = cách trỏ đến node first

        prev->next=secondN; // di chuyển con trỏ prev->next trỏ đến second ( tức là node đầu của danh sách mới )
        prev=firstN; // di chuyển prev đến node sau khi đã hoán đổi 

    }
    return dummyNode.next; // trả về danh sashc liên kết
}
