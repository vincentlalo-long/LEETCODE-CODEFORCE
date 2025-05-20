//Link : https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=stack
//Code C :
int calPoints(char** operations, int operationsSize) {
    int stack[10000];
    int top = -1; // Khởi tạo stack 

    for (int i = 0; i < operationsSize; i++) {
        char* op = operations[i]; // do mỗi phép toán tử đều là 1 string

        if (strcmp(op, "+") == 0) {
            int sum = stack[top] + stack[top - 1];
            stack[++top] = sum;
        } else if (strcmp(op, "D") == 0) {
            int dbl = 2 * stack[top];
            stack[++top] = dbl;
        } else if (strcmp(op, "C") == 0) {
            top--;  // xóa phần tử gần nhất
        } else {
            // là số, có thể âm => dùng atoi()
            int num = atoi(op);
            stack[++top] = num;
        }
    }

    int res = 0;
    for (int i = 0; i <= top; i++) {
        res += stack[i];
    }

    return res;
}
