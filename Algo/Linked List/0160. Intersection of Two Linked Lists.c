//Link bài toán : https://leetcode.com/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* currentA=headA; // khởi tạo node currA ở đầu danh sách
    struct ListNode* currentB=headB; // tương tự như node trên
    while(currentA != currentB){ // kiểm tra nếu 2 node chưa giao nhau 
        currentA= (currentA==NULL)? headB:currentA->next;
        currentB=(currentB==NULL)? headA:currentB->next; // điều kiện này là để khi chạy hết list B thì chuyển sang đầu listB để duyệt tiếp .
        // cả 2 con trỏ current đều sẽ đi hết skipA+skipB+c bước ( c là số node chung)
    }
    return currentA;
}
