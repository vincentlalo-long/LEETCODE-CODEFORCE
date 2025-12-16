//LInk : https://leetcode.com/problems/symmetric-tree/description/?envType=problem-list-v2&envId=binary-tree
// Code C : 


// Định nghĩa node cây nhị phân
/*struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};*/

// Cấu trúc cặp node đối xứng
typedef struct {
    struct TreeNode* n1;
    struct TreeNode* n2;
} Pair;

// Hàng đợi đơn giản
typedef struct {
    Pair* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (Pair*)malloc(sizeof(Pair) * capacity);
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->capacity = capacity;
    return q;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

bool enqueue(Queue* q, struct TreeNode* n1, struct TreeNode* n2) {
    if (q->size == q->capacity) return false; // Không mở rộng trong ví dụ này
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear].n1 = n1;
    q->data[q->rear].n2 = n2;
    q->size++;
    return true;
}

bool dequeue(Queue* q, struct TreeNode** n1, struct TreeNode** n2) {
    if (isEmpty(q)) return false;
    *n1 = q->data[q->front].n1;
    *n2 = q->data[q->front].n2;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return true;
}

//  Hàm kiểm tra đối xứng bằng BFS
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;

    Queue* q = createQueue(1000);
    enqueue(q, root->left, root->right);

    struct TreeNode *n1, *n2;

    while (dequeue(q, &n1, &n2)) {
        if (!n1 && !n2) continue;
        if (!n1 || !n2 || n1->val != n2->val) {
            free(q->data); free(q);
            return false;
        }

        // Đẩy cặp con đối xứng vào queue
        enqueue(q, n1->left, n2->right);
        enqueue(q, n1->right, n2->left);
    }

    free(q->data); free(q);
    return true;
}
