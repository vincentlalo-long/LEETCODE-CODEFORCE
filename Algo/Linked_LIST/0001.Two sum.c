//LINK : https://leetcode.com/problems/two-sum/description/
#include <stdio.h>
#include <stdlib.h>

// Entry: phần tử của bảng băm
typedef struct Entry {
    int key;             // key là số nguyên
    int value;           // giá trị
    struct Entry* next;  // cho chaining
} Entry;

// HashTable: mảng các bucket (danh sách liên kết)
typedef struct HashTable {
    Entry** bucket;
    int size;
} HashTable;

// Hàm băm đơn giản cho int
unsigned int hash(int key, int table_size) {
    return (unsigned int)(key) % table_size;
}

// Khởi tạo bảng băm
HashTable* createTable(int size) {
    HashTable* table = malloc(sizeof(HashTable));
    table->size = size;
    table->bucket = calloc(size, sizeof(Entry*));
    return table;
}

// Thêm phần tử vào bảng băm
void insert(int key, HashTable* table, int value) {
    int index = hash(key, table->size);
    Entry* head = table->bucket[index];

    while (head != NULL) {
        if (key == head->key) {
            head->value = value;  // update nếu key đã tồn tại
            return;
        }
        head = head->next;
    }

    // Thêm mới
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = table->bucket[index];
    table->bucket[index] = newEntry;
}

// Tìm kiếm key trong bảng băm
int* search(HashTable* table, int key) {
    int index = hash(key, table->size);
    Entry* head = table->bucket[index];

    while (head != NULL) {
        if (head->key == key) {
            return &(head->value);
        }
        head = head->next;
    }
    return NULL;
}

// Hàm Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* map = createTable(1000);
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int* found = search(map, complement);// complement là giá trị của target-nums để lưu làm key để dễ dàng tìm kiếm
        if (found != NULL) {
            int* res = malloc(2 * sizeof(int));
            res[0] = *found; // trả về found vì found trả về value mà value của bài này đang chứ chỉ số của số
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        insert(nums[i], map, i);
    }
    *returnSize = 0;
    return NULL;
}
