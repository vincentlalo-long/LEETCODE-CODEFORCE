/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head!=NULL && head->val==val){ // kiểm tra xem node đầu có val =key không
        struct ListNode* temp=head; // khởi tạo con trỏ temp để lưu trữ dữ liệu của head 
        head=head->next; // di chuyển con trỏ head sang phần tử tiếp theo trong danh sách
        free(temp);
    }
    struct ListNode* current=head; // khởi tạo current để lưu dữ liệu head
    while(current!=NULL && current->next!=NULL){
        if(current->next->val==val)  { //kiểm tra xem node bên cạnh current có khóa =val không , tại vì node head sẽ không bao giờ bằng val do hàm ở bên trên 
            struct ListNode* temp=current->next;
            current->next=current->next->next; // gán con trỏ current->next sang phần tử sau phần tử có giá trị bằng val 
            free(temp);
        }
        else{
            current=current->next; // không thì di chuyển đến node tiếp theo
        }
    }
    return head; // trả về danh sách mới 

}
