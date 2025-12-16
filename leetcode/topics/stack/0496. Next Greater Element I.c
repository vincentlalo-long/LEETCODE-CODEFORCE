//https://leetcode.com/problems/next-greater-element-i/?envType=problem-list-v2&envId=stack
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct{
    int key; // Phần tử ban đầu ( các phần tử trong mảng nums2 cũng như phần tử trong nums1 , ví dụ nums2 là 2 4 6 3 thì key ở đây sẽ là 2 4 6 3)
    int val; // next greater element của khóa key , ví dụ nếu key là 2 thì val sẽ là 4
 }Pair;
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res=(int*)malloc(nums1Size*sizeof(int)); // Khởi tạo mảng để lưu kết quả
    int* stack=(int*)malloc(nums2Size*sizeof(int)); // Khởi tạo 1 stack để đẩy các phần tử greater của key vào
    Pair* map=(Pair*)malloc(nums2Size*sizeof(Pair)); // Khởi tạo 1 bảng map 
    int mapSize=0; // Khởi tạo số phần tử của map ( map ở đây là lưu trữ các cặp  key- val  , ví dụ nếu là 2 4 6 3 thì 2 -4 , 4-6,6- -1 , 3 cũng là -1 sizemap sẽ là 4)
    int top=-1;
    // Ta sẽ duyệt qua list 2 và xây 1 cái map để ánh xạ : 
    for(int i=0;i<nums2Size;i++){
        while(top>=0 && nums2[i]>=stack[top]){
            // nếu phần tử đang xét tới mà lớn hơn đỉnh của stack thì ta sẽ pop cái top ra và đẩy nums2[i] vào
            int val=stack[top--]; // val chính là giá trị mà top của stack cũ , tức là cái giá trị key cho vào map để tìm nextt greater 
            map[mapSize++]=(Pair){val,nums2[i]};

        }
        stack[++top]=nums2[i]; // đẩy phần tử vào stack top 
    }
    // Ta sẽ xử lí các phần tử mà ko có các phần tử lớn hơn 
    while(top>=0){
        int val =stack[top--]; // val chính là phần tử top của stack lấy ra
        map[mapSize++]=(Pair){val,-1};
    }
    // Tiếp đến ta sẽ xử lí nums1 để duyệ ttimf các phần tử greater 
    for(int i=0;i<nums1Size;i++){
        int key=nums1[i]; // gán giá trị key là giá trị của nums1
        for(int j=0;j<mapSize;j++){
            if(map[j].key==key){
                res[i]=map[j].val;
                break;
            }
        }
    }
    *returnSize=nums1Size;
    free(stack);
    free(map);
    return res; // trả về mảng res

    
}
