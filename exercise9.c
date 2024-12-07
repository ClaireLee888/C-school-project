#include <stdio.h>

// 判斷堆疊是否已滿
int is_full(int *index, const int size) {
    return *index == size; // 當 index 等於 size 時，堆疊已滿
}

// 判斷堆疊是否為空
int is_empty(int *index) {
    return *index == 0; // 當 index 為 0 時，堆疊為空
}

// 將數字推入堆疊
void push(int *stack, int *index, const int size, const int num) {
    if (is_full(index, size)) {
        printf("The stack is already full!\n");
        return;
    }
    stack[*index] = num; // 將數字放入堆疊
    (*index)++; // 增加索引
    printf("push %d\n", num);
}

// 從堆疊中彈出數字
void pop(int *stack, int *index) {
    if (is_empty(index)) {
        printf("No element left!\n");
        return;
    }
    (*index)--; // 減少索引
    printf("pop %d\n", stack[*index]);
    stack[*index] = 0; // 清空堆疊位置
}

int main() {
    int S, N;
    scanf("%d %d", &S, &N);
    int stack[S], index = 0;


    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        if (M == 0) { // Pop 操作
            pop(stack, &index);
        } else if (M == 1) { // Push 操作
            int num;
            scanf("%d", &num);
            push(stack, &index, S, num);
        }
    }

    // 輸出剩餘堆疊元素
    printf("The all stack elements are:\n");
    if (index == 0) {
        printf("No element left!\n");
    } else {
        for (int j = index - 1; j >= 0; j--) {
            printf("%d ", stack[j]);
        }
        printf("\n");
    }

    return 0;
}